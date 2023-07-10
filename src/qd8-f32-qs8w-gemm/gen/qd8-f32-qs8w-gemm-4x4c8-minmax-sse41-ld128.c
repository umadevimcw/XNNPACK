// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/MRx4c8-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <smmintrin.h>

#include <xnnpack/gemm.h>
#include <xnnpack/math.h>
#include <xnnpack/unaligned.h>


void xnn_qd8_f32_qs8w_gemm_minmax_ukernel_4x4c8__sse41_ld128(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)],
    const struct xnn_qd8_quantization_params quantization_params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 4);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(int8_t));
  const int8_t* a0 = a;
  float* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const int8_t* a2 = (const int8_t*) ((uintptr_t) a1 + a_stride);
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const int8_t* a3 = (const int8_t*) ((uintptr_t) a2 + a_stride);
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 4) {
    a3 = a2;
    c3 = c2;
  }

  do {
    const __m128i vksum = _mm_load_si128((const __m128i*) w);
    const __m128i vzero = _mm_setzero_si128();
    const __m128i vzp01 = _mm_loadu_si128((const __m128i*) &quantization_params[0].zero_point);
    const __m128i vzp0 = _mm_shuffle_epi32(vzp01, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128i vzp1 = _mm_shuffle_epi32(vzp01, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128i vzp23 = _mm_loadu_si128((const __m128i*) &quantization_params[2].zero_point);
    const __m128i vzp2 = _mm_shuffle_epi32(vzp23, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128i vzp3 = _mm_shuffle_epi32(vzp23, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128i vksumzp0 = _mm_mullo_epi32(vksum, vzp0);
    const __m128i vksumzp1 = _mm_mullo_epi32(vksum, vzp1);
    const __m128i vksumzp2 = _mm_mullo_epi32(vksum, vzp2);
    const __m128i vksumzp3 = _mm_mullo_epi32(vksum, vzp3);
    __m128i vacc0x0 = _mm_blend_epi16(vksumzp0, vzero, 0xFC);
    __m128i vacc0x1 = _mm_blend_epi16(vksumzp0, vzero, 0xF3);
    __m128i vacc0x2 = _mm_blend_epi16(vksumzp0, vzero, 0xCF);
    __m128i vacc0x3 = _mm_blend_epi16(vksumzp0, vzero, 0x3F);
    __m128i vacc1x0 = _mm_blend_epi16(vksumzp1, vzero, 0xFC);
    __m128i vacc1x1 = _mm_blend_epi16(vksumzp1, vzero, 0xF3);
    __m128i vacc1x2 = _mm_blend_epi16(vksumzp1, vzero, 0xCF);
    __m128i vacc1x3 = _mm_blend_epi16(vksumzp1, vzero, 0x3F);
    __m128i vacc2x0 = _mm_blend_epi16(vksumzp2, vzero, 0xFC);
    __m128i vacc2x1 = _mm_blend_epi16(vksumzp2, vzero, 0xF3);
    __m128i vacc2x2 = _mm_blend_epi16(vksumzp2, vzero, 0xCF);
    __m128i vacc2x3 = _mm_blend_epi16(vksumzp2, vzero, 0x3F);
    __m128i vacc3x0 = _mm_blend_epi16(vksumzp3, vzero, 0xFC);
    __m128i vacc3x1 = _mm_blend_epi16(vksumzp3, vzero, 0xF3);
    __m128i vacc3x2 = _mm_blend_epi16(vksumzp3, vzero, 0xCF);
    __m128i vacc3x3 = _mm_blend_epi16(vksumzp3, vzero, 0x3F);
    w = (const int32_t*) w + 4;

    size_t k = 0;
    while (k < kc) {
      const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
      const __m128i vxa0 = _mm_cvtepi8_epi16(va0);
      a0 += 8;
      const __m128i va1 = _mm_loadl_epi64((const __m128i*) a1);
      const __m128i vxa1 = _mm_cvtepi8_epi16(va1);
      a1 += 8;
      const __m128i va2 = _mm_loadl_epi64((const __m128i*) a2);
      const __m128i vxa2 = _mm_cvtepi8_epi16(va2);
      a2 += 8;
      const __m128i va3 = _mm_loadl_epi64((const __m128i*) a3);
      const __m128i vxa3 = _mm_cvtepi8_epi16(va3);
      a3 += 8;

      const __m128i vb01 = _mm_load_si128((const __m128i*) w);
      const __m128i vxb0 = _mm_cvtepi8_epi16(vb01);
      const __m128i vxb1 = _mm_srai_epi16(_mm_unpackhi_epi8(vb01, vb01), 8);

      vacc0x0 = _mm_add_epi32(vacc0x0, _mm_madd_epi16(vxa0, vxb0));
      vacc0x1 = _mm_add_epi32(vacc0x1, _mm_madd_epi16(vxa0, vxb1));
      vacc1x0 = _mm_add_epi32(vacc1x0, _mm_madd_epi16(vxa1, vxb0));
      vacc1x1 = _mm_add_epi32(vacc1x1, _mm_madd_epi16(vxa1, vxb1));
      vacc2x0 = _mm_add_epi32(vacc2x0, _mm_madd_epi16(vxa2, vxb0));
      vacc2x1 = _mm_add_epi32(vacc2x1, _mm_madd_epi16(vxa2, vxb1));
      vacc3x0 = _mm_add_epi32(vacc3x0, _mm_madd_epi16(vxa3, vxb0));
      vacc3x1 = _mm_add_epi32(vacc3x1, _mm_madd_epi16(vxa3, vxb1));
      const __m128i vb23 = _mm_load_si128((const __m128i*) ((const int8_t*) w + 16));
      const __m128i vxb2 = _mm_cvtepi8_epi16(vb23);
      const __m128i vxb3 = _mm_srai_epi16(_mm_unpackhi_epi8(vb23, vb23), 8);

      vacc0x2 = _mm_add_epi32(vacc0x2, _mm_madd_epi16(vxa0, vxb2));
      vacc0x3 = _mm_add_epi32(vacc0x3, _mm_madd_epi16(vxa0, vxb3));
      vacc1x2 = _mm_add_epi32(vacc1x2, _mm_madd_epi16(vxa1, vxb2));
      vacc1x3 = _mm_add_epi32(vacc1x3, _mm_madd_epi16(vxa1, vxb3));
      vacc2x2 = _mm_add_epi32(vacc2x2, _mm_madd_epi16(vxa2, vxb2));
      vacc2x3 = _mm_add_epi32(vacc2x3, _mm_madd_epi16(vxa2, vxb3));
      vacc3x2 = _mm_add_epi32(vacc3x2, _mm_madd_epi16(vxa3, vxb2));
      vacc3x3 = _mm_add_epi32(vacc3x3, _mm_madd_epi16(vxa3, vxb3));

      w = (const void*) ((const int8_t*) w + 32);
      k += 8 * sizeof(int8_t);
    }

    const __m128i vacc0x01 = _mm_hadd_epi32(vacc0x0, vacc0x1);
    const __m128i vacc0x23 = _mm_hadd_epi32(vacc0x2, vacc0x3);
    const __m128i vacc1x01 = _mm_hadd_epi32(vacc1x0, vacc1x1);
    const __m128i vacc1x23 = _mm_hadd_epi32(vacc1x2, vacc1x3);
    const __m128i vacc2x01 = _mm_hadd_epi32(vacc2x0, vacc2x1);
    const __m128i vacc2x23 = _mm_hadd_epi32(vacc2x2, vacc2x3);
    const __m128i vacc3x01 = _mm_hadd_epi32(vacc3x0, vacc3x1);
    const __m128i vacc3x23 = _mm_hadd_epi32(vacc3x2, vacc3x3);

    __m128i vacc0x0123 = _mm_hadd_epi32(vacc0x01, vacc0x23);
    __m128i vacc1x0123 = _mm_hadd_epi32(vacc1x01, vacc1x23);
    __m128i vacc2x0123 = _mm_hadd_epi32(vacc2x01, vacc2x23);
    __m128i vacc3x0123 = _mm_hadd_epi32(vacc3x01, vacc3x23);

    __m128 vout0x0123 = _mm_cvtepi32_ps(vacc0x0123);
    __m128 vout1x0123 = _mm_cvtepi32_ps(vacc1x0123);
    __m128 vout2x0123 = _mm_cvtepi32_ps(vacc2x0123);
    __m128 vout3x0123 = _mm_cvtepi32_ps(vacc3x0123);
    const __m128 vscale01 = _mm_loadu_ps(&quantization_params[0].scale);
    const __m128 vscale0 = _mm_shuffle_ps(vscale01, vscale01, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 vscale1 = _mm_shuffle_ps(vscale01, vscale01, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 vscale23 = _mm_loadu_ps(&quantization_params[2].scale);
    const __m128 vscale2 = _mm_shuffle_ps(vscale23, vscale23, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 vscale3 = _mm_shuffle_ps(vscale23, vscale23, _MM_SHUFFLE(2, 2, 2, 2));
    vout0x0123 = _mm_mul_ps(vout0x0123, vscale0);
    vout1x0123 = _mm_mul_ps(vout1x0123, vscale1);
    vout2x0123 = _mm_mul_ps(vout2x0123, vscale2);
    vout3x0123 = _mm_mul_ps(vout3x0123, vscale3);

    const __m128 vbias0123 = _mm_load_ps(w); w = (const float*) w + 4;
    vout0x0123 = _mm_add_ps(vout0x0123, vbias0123);
    vout1x0123 = _mm_add_ps(vout1x0123, vbias0123);
    vout2x0123 = _mm_add_ps(vout2x0123, vbias0123);
    vout3x0123 = _mm_add_ps(vout3x0123, vbias0123);
    const __m128 vmax = _mm_load_ps(&params->sse.max[0]);
    const __m128 vmin = _mm_load_ps(&params->sse.min[0]);
    vout0x0123 = _mm_max_ps(vout0x0123, vmin);
    vout0x0123 = _mm_min_ps(vout0x0123, vmax);
    vout1x0123 = _mm_max_ps(vout1x0123, vmin);
    vout1x0123 = _mm_min_ps(vout1x0123, vmax);
    vout2x0123 = _mm_max_ps(vout2x0123, vmin);
    vout2x0123 = _mm_min_ps(vout2x0123, vmax);
    vout3x0123 = _mm_max_ps(vout3x0123, vmin);
    vout3x0123 = _mm_min_ps(vout3x0123, vmax);

    if XNN_LIKELY(nc >= 4) {
      _mm_storeu_ps(c3, vout3x0123);
      _mm_storeu_ps(c2, vout2x0123);
      _mm_storeu_ps(c1, vout1x0123);
      _mm_storeu_ps(c0, vout0x0123);

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);
      a2 = (const int8_t*) ((uintptr_t) a2 - kc);
      a3 = (const int8_t*) ((uintptr_t) a3 - kc);

      c0 = (float*) ((uintptr_t) c0 + cn_stride);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);

      nc -= 4;
    } else {
      if (nc & 2) {
        _mm_storel_pi((__m64*) c0, vout0x0123);
        vout0x0123 = _mm_unpackhi_ps(vout0x0123, vout0x0123);
        c0 += 2;
        _mm_storel_pi((__m64*) c1, vout1x0123);
        vout1x0123 = _mm_unpackhi_ps(vout1x0123, vout1x0123);
        c1 += 2;
        _mm_storel_pi((__m64*) c2, vout2x0123);
        vout2x0123 = _mm_unpackhi_ps(vout2x0123, vout2x0123);
        c2 += 2;
        _mm_storel_pi((__m64*) c3, vout3x0123);
        vout3x0123 = _mm_unpackhi_ps(vout3x0123, vout3x0123);
        c3 += 2;
      }
      if (nc & 1) {
        _mm_store_ss(c0, vout0x0123);
        _mm_store_ss(c1, vout1x0123);
        _mm_store_ss(c2, vout2x0123);
        _mm_store_ss(c3, vout3x0123);
      }
      nc = 0;
    }
  } while (nc != 0);
}