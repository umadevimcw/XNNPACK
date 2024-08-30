// Auto-generated file. Do not edit!
//   Template: src/f32-vcmul/avx512f.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include "xnnpack/common.h"
#include "xnnpack/vbinary.h"

void xnn_f32_vcmul_ukernel__avx512f_u32(
    size_t batch,
    const float* input_a,
    const float* input_b,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const float* ar = input_a;
  const float* ai = (const float*) ((uintptr_t) input_a + batch);
  const float* br = input_b;
  const float* bi = (const float*) ((uintptr_t) input_b + batch);
  float* or = output;
  float* oi = (float*) ((uintptr_t) output + batch);
  for (; batch >= 32 * sizeof(float); batch -= 32 * sizeof(float)) {
    const __m512 va0r = _mm512_loadu_ps(ar);
    const __m512 va0i = _mm512_loadu_ps(ai);
    const __m512 vb0r = _mm512_loadu_ps(br);
    const __m512 vb0i = _mm512_loadu_ps(bi);
    const __m512 va1r = _mm512_loadu_ps(ar + 16);
    const __m512 va1i = _mm512_loadu_ps(ai + 16);
    const __m512 vb1r = _mm512_loadu_ps(br + 16);
    const __m512 vb1i = _mm512_loadu_ps(bi + 16);
    ar += 32;
    ai += 32;
    br += 32;
    bi += 32;

    __m512 vacc0r = _mm512_mul_ps(va0r, vb0r);
    __m512 vacc0i = _mm512_mul_ps(va0r, vb0i);
    __m512 vacc1r = _mm512_mul_ps(va1r, vb1r);
    __m512 vacc1i = _mm512_mul_ps(va1r, vb1i);

    vacc0r = _mm512_fnmadd_ps(va0i, vb0i, vacc0r);
    vacc0i = _mm512_fmadd_ps(va0i, vb0r, vacc0i);
    vacc1r = _mm512_fnmadd_ps(va1i, vb1i, vacc1r);
    vacc1i = _mm512_fmadd_ps(va1i, vb1r, vacc1i);

    _mm512_storeu_ps(or, vacc0r);
    _mm512_storeu_ps(oi, vacc0i);
    _mm512_storeu_ps(or + 16, vacc1r);
    _mm512_storeu_ps(oi + 16, vacc1i);
    or += 32;
    oi += 32;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const __m128 var = _mm_loadu_ps(ar);
    ar += 4;
    const __m128 vai = _mm_loadu_ps(ai);
    ai += 4;
    const __m128 vbr = _mm_loadu_ps(br);
    br += 4;
    const __m128 vbi = _mm_loadu_ps(bi);
    bi += 4;

    __m128 vaccr = _mm_mul_ps(var, vbr);
    __m128 vacci = _mm_mul_ps(var, vbi);

    vaccr = _mm_sub_ps(vaccr, _mm_mul_ps(vai, vbi));
    vacci = _mm_add_ps(vacci, _mm_mul_ps(vai, vbr));

    _mm_storeu_ps(or, vaccr);
    or += 4;
    _mm_storeu_ps(oi, vacci);
    oi += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const __m128 var = _mm_loadu_ps(ar);
    ar += 4;
    const __m128 vai = _mm_loadu_ps(ai);
    ai += 4;
    const __m128 vbr = _mm_loadu_ps(br);
    br += 4;
    const __m128 vbi = _mm_loadu_ps(bi);
    bi += 4;

    __m128 vaccr = _mm_mul_ps(var, vbr);
    __m128 vacci = _mm_mul_ps(var, vbi);

    vaccr = _mm_sub_ps(vaccr, _mm_mul_ps(vai, vbi));
    vacci = _mm_add_ps(vacci, _mm_mul_ps(vai, vbr));

    if (batch & (2 * sizeof(float))) {
      _mm_storel_pi((__m64*) or, vaccr);
      or += 2;
      _mm_storel_pi((__m64*) oi, vacci);
      oi += 2;
      vaccr = _mm_movehl_ps(vaccr, vaccr);
      vacci = _mm_movehl_ps(vacci, vacci);
    }
    if (batch & (1 * sizeof(float))) {
      _mm_store_ss(or, vaccr);
      _mm_store_ss(oi, vacci);
    }
  }
}