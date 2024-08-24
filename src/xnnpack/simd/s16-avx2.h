// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX2_H_
#define __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX2_H_

#include <assert.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/common.h"
#include "xnnpack/unaligned.h"

// SIMD vector type for s16 using AVX2.
typedef __m256i xnn_simd_s16_t;
#define xnn_simd_size_s16 16
#define xnn_simd_log2_size_s16 4
#define xnn_simd_bytes_s16 (xnn_simd_size_s16 * sizeof(int16_t))

#define XNN_SIMD_CONST_S16(var, val) \
  const xnn_simd_s16_t var = _mm256_set1_epi16(val);

// Mask table used for masked load/store operations.
static const int32_t mask_table_avx_s16[32] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
// Arithmetic operations.

// Bitwise Operations

static XNN_INLINE xnn_simd_s16_t xnn_clz_s16(xnn_simd_s16_t a) {
  __m128i lowi = _mm256_extracti128_si256(a, 0);
  __m128i highi = _mm256_extracti128_si256(a, 1);

  __m256i low_32 = _mm256_cvtepi16_epi32(lowi);
  __m256i high_32 = _mm256_cvtepi16_epi32(highi);

  __m256 low = _mm256_cvtepi32_ps((low_32));
  __m256 high = _mm256_cvtepi32_ps((high_32));
  xnn_simd_s16_t low_a = _mm256_castps_si256(low);
  xnn_simd_s16_t high_a = _mm256_castps_si256(high);

  xnn_simd_s16_t shift_low = _mm256_srli_epi32(low_a, 23);
  xnn_simd_s16_t shift_high = _mm256_srli_epi32(high_a, 23);

  xnn_simd_s16_t exponent_combined = _mm256_packs_epi32(shift_low, shift_high);
  xnn_simd_s16_t exponent =
      _mm256_permute4x64_epi64(exponent_combined, _MM_SHUFFLE(3, 1, 2, 0));

  exponent = _mm256_and_si256(exponent, _mm256_set1_epi16(0xFF));

  xnn_simd_s16_t result =
      _mm256_sub_epi16(_mm256_set1_epi16(15),
                       _mm256_sub_epi16(exponent, _mm256_set1_epi16(127)));
  xnn_simd_s16_t zero = _mm256_setzero_si256();
  xnn_simd_s16_t mask = _mm256_cmpgt_epi16(zero, a);
  result = _mm256_andnot_si256(mask, result);

  xnn_simd_s16_t sixteen = _mm256_set1_epi16(16);
  xnn_simd_s16_t maskz = _mm256_cmpeq_epi16(a, zero);

  result = _mm256_blendv_epi8(result, sixteen, maskz);
  return result;
}
// Load/store operations.

static XNN_INLINE xnn_simd_s16_t xnn_loadu_s16(const int16_t* ptr) {
  return _mm256_loadu_si256((const __m256i*)ptr);
}

static XNN_INLINE xnn_simd_s16_t xnn_load_s16(const int16_t* ptr) {
  return _mm256_load_si256((const __m256i*)ptr);
}

static XNN_INLINE void xnn_storeu_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm256_storeu_si256((__m256i*)ptr, v);
}

static XNN_INLINE void xnn_store_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm256_store_si256((__m256i*)ptr, v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_s16(int16_t v) {
  return _mm256_set1_epi16(v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_or_load_s16(const int16_t* v) {
#if XNN_ARCH_X86
  return _mm256_load_si256((const __m256i*)v);
#else
  return _mm256_set1_epi16(*v);
#endif
}

// Tail load/store operations.

static XNN_INLINE xnn_simd_s16_t
xnn_load_tail_s16(const int16_t* input, size_t num_elements) XNN_OOB_READS {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);
  const __m256i vmask = _mm256_loadu_si256(
      (const __m256i*)(&mask_table_avx_s16[16 - num_elements]));
  return _mm256_maskload_epi32((const int32_t*) input, vmask);
}

static XNN_INLINE void xnn_store_tail_s16(int16_t* output, xnn_simd_s16_t v,
                                          size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);

  __m128i v_lo = _mm256_castsi256_si128(v);
  if (num_elements & 8) {
    _mm_storeu_si128((__m128i*)output, v_lo);
    v_lo = _mm256_extractf128_si256(v, 1);
    output += 8;
  }
  if (num_elements & 4) {
    _mm_storel_epi64((__m128i*)output, v_lo);
    v_lo = _mm_unpackhi_epi64(v_lo, v_lo);
    output += 4;
  }
  if (num_elements & 2) {
    unaligned_store_u32(output, (uint32_t)_mm_cvtsi128_si32(v_lo));
    v_lo = _mm_srli_epi64(v_lo, 32);
    output += 2;
  }
  if (num_elements & 1) {
    unaligned_store_u16(output, (uint16_t)_mm_extract_epi16(v_lo, 0));
  }
}

#endif  // __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX2_H_
