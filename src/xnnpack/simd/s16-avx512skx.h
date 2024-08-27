// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512SKX_H_
#define __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512SKX_H_

#include <assert.h>
#include <immintrin.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/common.h"
#include "xnnpack/intrinsics-polyfill.h"
#include "xnnpack/unaligned.h"

// SIMD vector type for s16 using AVX512SKX.
typedef __m512i xnn_simd_s16_t;
#define xnn_simd_size_s16 32
#define xnn_simd_log2_size_s16 5
#define xnn_simd_bytes_s16 (xnn_simd_size_s16 * sizeof(int16))

#define XNN_SIMD_CONST_S16(var, val) \
  const xnn_simd_s16 var = _mm_set1_epi16(val);

// Arithmetic operations.

// Bitwise operations.
static XNN_INLINE xnn_simd_s16_t xnn_popcnt_s16(xnn_simd_s16_t a) {
  __m256i lookup_table =_mm256_setr_epi8(
    (char)0, (char)1, (char)1, (char)2,(char)1, (char)2, (char)2, (char)3,
    (char)1, (char)2, (char)2, (char)3,(char)2, (char)3, (char)3, (char)4,
    (char)0, (char)1, (char)1, (char)2,(char)1, (char)2, (char)2, (char)3,
    (char)1, (char)2, (char)2, (char)3,(char)2, (char)3, (char)3, (char)4
  );
  const __m256i mask = _mm256_set1_epi16(0x000F);
  const __m256i lower = _mm512_extracti64x4_epi64(a, 0);
  const __m256i upper = _mm512_extracti64x4_epi64(a, 1);
  __m256i result_upper = _mm256_setzero_si256();
  __m256i result_lower = _mm256_setzero_si256();

  for (int i = 0; i < 4; ++i) {
    const __m256i nibble_l = _mm256_and_si256(_mm256_srli_epi16(lower, i * 4), mask);
    result_lower = _mm256_add_epi16(result_lower, _mm256_shuffle_epi8(lookup_table, nibble_l));

    const __m256i nibble_u = _mm256_and_si256(_mm256_srli_epi16(upper, i * 4), mask);
    result_upper = _mm256_add_epi16(result_upper, _mm256_shuffle_epi8(lookup_table, nibble_u));
  }

  xnn_simd_s16_t result = _mm512_set_epi64(
    _mm256_extract_epi64(result_upper, 3),
    _mm256_extract_epi64(result_upper, 2),
    _mm256_extract_epi64(result_upper, 1),
    _mm256_extract_epi64(result_upper, 0),
    _mm256_extract_epi64(result_lower, 3),
    _mm256_extract_epi64(result_lower, 2),
    _mm256_extract_epi64(result_lower, 1),
    _mm256_extract_epi64(result_lower, 0)
  );
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

static XNN_INLINE xnn_simd_s16_t xnn_set1_s16_t(int16_t v) {
  return _mm512_set1_epi16(v);
}

static XNN_INLINE xnn_simd_s16_t xnn_set1_or_load_s16_t(const int16_t* v) {
  return _mm512_set1_epi16(*v);
}

// Tail load/store operations.

static XNN_INLINE xnn_simd_s16_t
xnn_load_tail_s16(const int16_t* input, size_t num_elements) XNN_OOB_READS {
  assert(num_elements > 0);
  assert(num_elements <= xnn_simd_size_s16);
  return _mm512_loadu_epi16(input);
}

static XNN_INLINE void xnn_store_tail_s16(int16_t* output, xnn_simd_s16_t v,
                                          size_t num_elements) {
  assert(num_elements > 0);
  assert(num_elements < xnn_simd_size_s16);

  const __mmask32 vmask =
      _cvtu32_mask32((uint32_t)((UINT32_C(1) << num_elements) - UINT32_C(1)));
  _mm512_mask_storeu_epi16(output, vmask, v);
}

#endif  // __XNNPACK_SRC_XNNPACK_SIMD_S16_AVX512SKX_H_
