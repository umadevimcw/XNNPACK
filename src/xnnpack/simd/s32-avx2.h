// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef __XNNPACK_SRC_XNNPACK_SIMD_S32_AVX2_H_
#define __XNNPACK_SRC_XNNPACK_SIMD_S32_AVX2_H_

#include <assert.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/common.h"
#include "xnnpack/unaligned.h"

// SIMD vector type for s32 using AVX2.
typedef __m256i xnn_simd_s32_t;
#define xnn_simd_size_s32 8
#define xnn_simd_log2_size_s32 3
#define xnn_simd_bytes_s32 (xnn_simd_size_s32 * sizeof(int32_t))

#define XNN_SIMD_CONST_S32(var, val) \
  const xnn_simd_s32_t var = _mm256_set1_epi32(val);

// Mask table used for masked load/store operations.
static const int32_t mask_table_avx_s32[14] = {-1, -1, -1, -1, -1, -1, -1,
                                               0,  0,  0,  0,  0,  0,  0};
// Arithmetic operations.
static XNN_INLINE xnn_simd_s32_t xnn_mul_s32(xnn_simd_s32_t a,
                                             xnn_simd_s32_t b) {
  return _mm256_mullo_epi32(a, b);
}

static XNN_INLINE xnn_simd_s32_t xnn_max_s32(xnn_simd_s32_t a,
                                             xnn_simd_s32_t b) {
  return _mm256_max_epi32(a, b);
}

static XNN_INLINE xnn_simd_s32_t xnn_min_s32(xnn_simd_s32_t a,
                                             xnn_simd_s32_t b) {
  return _mm256_min_epi32(a, b);
}

// Bitwise operations.
static XNN_INLINE xnn_simd_s32_t xnn_popcnt_s32(xnn_simd_s32_t a) {
  xnn_simd_s32_t lookup_table = _mm256_setr_epi8(
    (char)0, (char)1, (char)1, (char)2,(char)1, (char)2, (char)2, (char)3,
    (char)1, (char)2, (char)2, (char)3,(char)2, (char)3, (char)3, (char)4,
    (char)0, (char)1, (char)1, (char)2,(char)1, (char)2, (char)2, (char)3,
    (char)1, (char)2, (char)2, (char)3,(char)2, (char)3, (char)3, (char)4
  );
  
  const xnn_simd_s32_t mask =  _mm256_set1_epi32(0x0000000F);
  xnn_simd_s32_t result = _mm256_setzero_si256();
  for (int i = 0; i < 8; ++i) {
    xnn_simd_s32_t nibble = _mm256_and_si256(_mm256_srli_epi32(a, i*4), mask);
    result = _mm256_add_epi32(result, _mm256_shuffle_epi8(lookup_table, nibble));
  }
  return result;
}

// Load/store operations.

static XNN_INLINE xnn_simd_s32_t xnn_loadu_s32(const int32_t* ptr) {
  return _mm256_loadu_si256((const __m256i*)ptr);
}

static XNN_INLINE xnn_simd_s32_t xnn_load_s32(const int32_t* ptr) {
  return _mm256_load_si256((const __m256i*)ptr);
}

static XNN_INLINE void xnn_storeu_s32(int32_t* ptr, xnn_simd_s32_t v) {
  _mm256_storeu_si256((__m256i*)ptr, v);
}

static XNN_INLINE void xnn_store_s32(int32_t* ptr, xnn_simd_s32_t v) {
  _mm256_store_si256((__m256i*)ptr, v);
}

static XNN_INLINE xnn_simd_s32_t xnn_set1_s32(int32_t v) {
  return _mm256_set1_epi32(v);
}

static XNN_INLINE xnn_simd_s32_t xnn_set1_or_load_s32(const int32_t* v) {
#if XNN_ARCH_X86
  return _mm256_load_si256((const __m256i*)v);
#else
  return _mm256_set1_epi32(*v);
#endif
}

// Tail load/store operations.

static XNN_INLINE xnn_simd_s32_t
xnn_load_tail_s32(const int32_t* input, size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s32);

  const __m256i vmask = _mm256_loadu_si256(
      (const __m256i*)(&mask_table_avx_s32[7] - num_elements));
  return _mm256_maskload_epi32(input, vmask);
}

static XNN_INLINE void xnn_store_tail_s32(int32_t* output, xnn_simd_s32_t v,
                                          size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s32);

  __m128i v_lo = _mm256_castsi256_si128(v);
  if (num_elements & 4) {
    _mm_storeu_si128((__m128i*)output, v_lo);
    v_lo = _mm256_extractf128_si256(v, 1);
    output += 4;
  }
  if (num_elements & 2) {
    _mm_storel_epi64((__m128i*)output, v_lo);
    v_lo = _mm_unpackhi_epi64(v_lo, v_lo);
    output += 2;
  }
  if (num_elements & 1) {
    unaligned_store_u32(output, (uint32_t)_mm_cvtsi128_si32(v_lo));
  }
}

#endif  // __XNNPACK_SRC_XNNPACK_SIMD_S32_AVX2_H_
