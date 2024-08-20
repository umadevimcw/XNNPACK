// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef __XNNPACK_SRC_XNNPACK_SIMD_S16_SSE2_H_
#define __XNNPACK_SRC_XNNPACK_SIMD_S16_SSE2_H_

#include <assert.h>
#include <smmintrin.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/common.h"
#include "xnnpack/unaligned.h"

// SIMD vector type for s16 using SSE41.
typedef __m128i xnn_simd_s16_t;
#define xnn_simd_size_s16 8
#define xnn_simd_log2_size_s16 3
#define xnn_simd_bytes_s16 (xnn_simd_size_s16 * sizeof(int16_t))

#define XNN_SIMD_CONST_S16(var, val) \
  const xnn_simd_s16_t v16 = _mm_set1_epi16(val);

// Arithmetic operations.

static XNN_INLINE xnn_simd_s16_t xnn_clz_s16(xnn_simd_s16_t a) {
  __m128i shuffled_a = _mm_shufflehi_epi16(a, _MM_SHUFFLE(2, 0, 3, 1));
  __m128i shuffled_b = _mm_shufflehi_epi16(a, _MM_SHUFFLE(3, 1, 2, 0));

  __m128i ah = _mm_unpackhi_epi16(shuffled_b, shuffled_a);

  xnn_simd_s16_t low_half = _mm_cvtepi16_epi32(a);
  xnn_simd_s16_t high_half = _mm_cvtepi16_epi32(ah);
  __m128 low = _mm_cvtepi32_ps(low_half);
  __m128 high = _mm_cvtepi32_ps(high_half);
  xnn_simd_s16_t low_a = _mm_castps_si128(low);
  xnn_simd_s16_t high_a = _mm_castps_si128(high);
  //
  xnn_simd_s16_t shift_low = _mm_srli_epi32(low_a, 23);    //& 0xFF;
  xnn_simd_s16_t shift_high = _mm_srli_epi32(high_a, 23);  //& 0xFF;
                                                           //
  xnn_simd_s16_t exponent = _mm_set_epi16(
      (_mm_extract_epi16(shift_high, 6)), (_mm_extract_epi16(shift_high, 4)),
      (_mm_extract_epi16(shift_high, 2)), (_mm_extract_epi16(shift_high, 0)),
      (_mm_extract_epi16(shift_low, 6)), (_mm_extract_epi16(shift_low, 4)),
      (_mm_extract_epi16(shift_low, 2)), (_mm_extract_epi16(shift_low, 0)));
  exponent = _mm_and_si128(exponent, _mm_set1_epi16(0xFF));
  xnn_simd_s16_t result = _mm_sub_epi16(
      _mm_set1_epi16(15), _mm_sub_epi16(exponent, _mm_set1_epi16(127)));

  xnn_simd_s16_t zero = _mm_setzero_si128();
  xnn_simd_s16_t mask = _mm_cmpgt_epi16(zero, a);
  result = _mm_andnot_si128(mask, result);

  xnn_simd_s16_t sixteen = _mm_set1_epi16(16);
  xnn_simd_s16_t maskz = _mm_cmpeq_epi16(a, zero);

  result = _mm_blendv_epi8(result, sixteen, maskz);
  return result;
}

// Load/store operations.

static XNN_INLINE xnn_simd_s16_t xnn_loadu_s16(const int16_t* ptr) {
  return _mm_loadu_si128((const __m128i*)ptr);
}

static XNN_INLINE xnn_simd_s16_t xnn_load_s16(const int16_t* ptr) {
  return _mm_load_si128((const __m128i*)ptr);
}

static XNN_INLINE void xnn_storeu_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm_storeu_si128((__m128i*)ptr, v);
}

static XNN_INLINE void xnn_store_s16(int16_t* ptr, xnn_simd_s16_t v) {
  _mm_store_si128((__m128i*)ptr, v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_s16(int16_t v) {
  return _mm_set1_epi16(v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_or_load_s16(const int16_t* v) {
#if XNN_ARCH_X86
  return _mm_load_si128((const __m128i*)v);
#else
  return _mm_set1_epi16(*v);
#endif
}

// Tail load/store operations.

static XNN_INLINE xnn_simd_s16_t
xnn_load_tail_s16(const int16_t* input, size_t num_elements) XNN_OOB_READS {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);
  return _mm_loadu_si128((const __m128i*)input);
}

static XNN_INLINE void xnn_store_tail_s16(int16_t* output, xnn_simd_s16_t v,
                                          size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);

  if (num_elements & 4) {
    _mm_storel_epi64((__m128i*)output, v);
    v = _mm_unpackhi_epi64(v, v);
    output += 4;
  }
  if (num_elements & 2) {
    unaligned_store_u32(output, (uint32_t)_mm_cvtsi128_si32(v));
    v = _mm_srli_epi64(v, 32);
    output += 2;
  }
  if (num_elements & 1) {
    unaligned_store_u16(output, (uint16_t)_mm_extract_epi16(v, 0));
  }
}

#endif  // __XNNPACK_SRC_XNNPACK_SIMD_S16_SSE2_H_
