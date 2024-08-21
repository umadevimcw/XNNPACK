// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512F_H_
#define __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512F_H_

#include <assert.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/common.h"
#include "xnnpack/intrinsics-polyfill.h"
#include "xnnpack/unaligned.h"

// SIMD vector type for s16 using SSE41.
typedef __m512i xnn_simd_s16_t;
#define xnn_simd_size_s16 32
#define xnn_simd_log2_size_s16 5
#define xnn_simd_bytes_s16 (xnn_simd_size_s16 * sizeof(int16_t))

#define XNN_SIMD_CONST_S16(var, val) \
  const xnn_simd_s16 var = _mm_set1_epi16(val);

// Arithmetic operations.

// Bitwise operations

static XNN_INLINE xnn_simd_s16_t xnn_clz_s16(xnn_simd_s16_t a) {
  xnn_simd_s16_t shuffled_a =
      _mm512_shuffle_i32x4(a, a, _MM_SHUFFLE(3, 2, 3, 2));
  xnn_simd_s16_t shuffled_b =
      _mm512_shuffle_i32x4(a, a, _MM_SHUFFLE(1, 0, 1, 0));

  __m256i lower_half = _mm512_castsi512_si256(shuffled_b);
  __m256i upper_half = _mm512_castsi512_si256(shuffled_a);

  __m512i lowi = _mm512_cvtepi16_epi32(lower_half);
  __m512i highi = _mm512_cvtepi16_epi32(upper_half);

  __m512 low = _mm512_cvtepi32_ps(lowi);
  __m512 high = _mm512_cvtepi32_ps(highi);

  xnn_simd_s16_t low_a = _mm512_castps_si512(low);
  xnn_simd_s16_t high_a = _mm512_castps_si512(high);

  xnn_simd_s16_t shift_low = _mm512_srli_epi32(low_a, 23);
  xnn_simd_s16_t shift_high = _mm512_srli_epi32(high_a, 23);

  xnn_simd_s16_t mask = _mm512_set_epi16(31, 29, 27, 25, 23, 21, 19, 17, 15, 13,
                                        11, 9, 7, 5, 3, 1, 30, 28, 26, 24, 22,
                                        20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0);
  xnn_simd_s16_t mlow = _mm512_permutexvar_epi16(mask, shift_low);
  xnn_simd_s16_t mhigh = _mm512_permutexvar_epi16(mask, shift_high);

  __m256i ai = _mm512_extracti64x4_epi64(mlow, 0);
  __m256i bi = _mm512_extracti64x4_epi64(mhigh, 0);

  xnn_simd_s16_t exponent =
      _mm512_inserti64x4(_mm512_castsi256_si512(ai), bi, 1);

  exponent = _mm512_and_si512(exponent, _mm512_set1_epi16(0xFF));

  xnn_simd_s16_t result =
      _mm512_sub_epi16(_mm512_set1_epi16(15),
                      _mm512_sub_epi16(exponent, _mm512_set1_epi16(127)));

  xnn_simd_s16_t zero = _mm512_setzero_si512();

  __mmask32 maskl = _mm512_cmpge_epi16_mask(a, zero);
  result = _mm512_maskz_mov_epi16(maskl, result);
  __mmask32 maskz = _mm512_cmpeq_epi16_mask(a, zero);
  result = _mm512_mask_mov_epi16(result, maskz, _mm512_set1_epi16(16));

  return result;
}
// Load/store operations.

static XNN_INLINE xnn_simd_s16_t xnn_loadu_s16(const int16_t* ptr) {
  return _mm512_loadu_si512(ptr);
}

static XNN_INLINE xnn_simd_s16_t xnn_load_s16(const int16_t* ptr) {
  return _mm512_load_si512(ptr);
}

static XNN_INLINE void xnn_storeu_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm512_storeu_si512(ptr, v);
}

static XNN_INLINE void xnn_store_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm512_storeu_si512(ptr, v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_s16(int16_t v) {
  return _mm512_set1_epi16(v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_or_load_s16(const int16_t* v) {
  return _mm512_set1_epi16(*v);
}

// Tail load/store operations.

static XNN_INLINE xnn_simd_s16_t
xnn_load_tail_s16(const int16_t* input, size_t num_elements) XNN_OOB_READS {
  assert(num_elements > 0);
  assert(num_elements <= xnn_simd_size_s16);
  return _mm512_loadu_si512(input);
}

static XNN_INLINE void xnn_store_tail_s16(int16_t* output, xnn_simd_s16_t v,
                                          size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);

  const __mmask32 vmask =
      _cvtu32_mask32((uint32_t)((UINT32_C(1) << num_elements) - UINT32_C(1)));
  _mm512_mask_storeu_epi16(output, vmask, v);
}

#endif  // __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512F_H_
