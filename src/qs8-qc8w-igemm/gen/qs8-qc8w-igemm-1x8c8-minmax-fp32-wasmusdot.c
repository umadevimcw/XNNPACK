// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/c8-wasmdot.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include "xnnpack/gemm.h"
#include "xnnpack/math.h"


void xnn_qs8_qc8w_igemm_minmax_fp32_ukernel_1x8c8__wasmusdot(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_qc8w_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (1 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(int8_t));
  int8_t* c0 = c;

  const v128_t vmagic_bias = wasm_f32x4_const_splat(12582912.0f);
  const int32_t output_min_less_zero_point = (int32_t) params->fp32_scalar.output_min - (int32_t) params->fp32_scalar.output_zero_point;
  const v128_t vmagic_min = wasm_i32x4_splat((int32_t) float_as_uint32(12582912.0f + output_min_less_zero_point));
  const v128_t vmagic_bias_less_output_zero_point = wasm_i32x4_splat(INT32_C(0x4B400000) - (int32_t) params->fp32_scalar.output_zero_point);
  const v128_t voutput_max = wasm_i8x16_splat(params->fp32_scalar.output_max);
  XNN_FORCE_REALIZATION(vmagic_bias);
  XNN_FORCE_REALIZATION(vmagic_min);
  XNN_FORCE_REALIZATION(vmagic_bias_less_output_zero_point);
  XNN_FORCE_REALIZATION(voutput_max);

  const v128_t vsign_mask = wasm_u8x16_const_splat(UINT8_C(0x80));
  XNN_FORCE_REALIZATION(vsign_mask);
  do {
    v128_t vacc0x01 = wasm_u64x2_load32x2(w); w = (const int32_t*) w + 2;
    v128_t vacc0x23 = wasm_u64x2_load32x2(w); w = (const int32_t*) w + 2;
    v128_t vacc0x45 = wasm_u64x2_load32x2(w); w = (const int32_t*) w + 2;
    v128_t vacc0x67 = wasm_u64x2_load32x2(w); w = (const int32_t*) w + 2;

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      a += 1;

      size_t k = kc;
      while (k != 0) {
        const v128_t va0x01 = wasm_v128_xor(wasm_v128_load64_splat(a0), vsign_mask);
        a0 += 8;

        const v128_t vb01x01 = wasm_v128_load(w); w = (const int8_t*) w + 16;
        const v128_t vb23x01 = wasm_v128_load(w); w = (const int8_t*) w + 16;
        const v128_t vb45x01 = wasm_v128_load(w); w = (const int8_t*) w + 16;
        const v128_t vb67x01 = wasm_v128_load(w); w = (const int8_t*) w + 16;

        vacc0x01 = wasm_i32x4_relaxed_dot_i8x16_i7x16_add(vb01x01, va0x01, vacc0x01);
        vacc0x23 = wasm_i32x4_relaxed_dot_i8x16_i7x16_add(vb23x01, va0x01, vacc0x23);
        vacc0x45 = wasm_i32x4_relaxed_dot_i8x16_i7x16_add(vb45x01, va0x01, vacc0x45);
        vacc0x67 = wasm_i32x4_relaxed_dot_i8x16_i7x16_add(vb67x01, va0x01, vacc0x67);

        k -= 8 * sizeof(int8_t);
      }

      p -= 1 * sizeof(void*);
    } while (p != 0);

    v128_t vacc0x0123 = wasm_i32x4_add(wasm_v32x4_shuffle(vacc0x01, vacc0x23, 0, 2, 4, 6), wasm_v32x4_shuffle(vacc0x01, vacc0x23, 1, 3, 5, 7));
    v128_t vacc0x4567 = wasm_i32x4_add(wasm_v32x4_shuffle(vacc0x45, vacc0x67, 0, 2, 4, 6), wasm_v32x4_shuffle(vacc0x45, vacc0x67, 1, 3, 5, 7));

    vacc0x0123 = wasm_f32x4_convert_i32x4(vacc0x0123);
    vacc0x4567 = wasm_f32x4_convert_i32x4(vacc0x4567);

    const v128_t vscale0123 = wasm_v128_load(w);
    w = (const float*) w + 4;
    const v128_t vscale4567 = wasm_v128_load(w);
    w = (const float*) w + 4;
    vacc0x0123 = wasm_f32x4_mul(vacc0x0123, vscale0123);
    vacc0x4567 = wasm_f32x4_mul(vacc0x4567, vscale4567);

    vacc0x0123 = wasm_f32x4_add(vacc0x0123, vmagic_bias);
    vacc0x4567 = wasm_f32x4_add(vacc0x4567, vmagic_bias);

    vacc0x0123 = wasm_i32x4_max(vacc0x0123, vmagic_min);
    vacc0x4567 = wasm_i32x4_max(vacc0x4567, vmagic_min);

    vacc0x0123 = wasm_i32x4_sub(vacc0x0123, vmagic_bias_less_output_zero_point);
    vacc0x4567 = wasm_i32x4_sub(vacc0x4567, vmagic_bias_less_output_zero_point);

    v128_t vacc0x01234567 = wasm_i16x8_narrow_i32x4(vacc0x0123, vacc0x4567);

    v128_t vout0x01234567_0x01234567 = wasm_i8x16_narrow_i16x8(vacc0x01234567, vacc0x01234567);

    vout0x01234567_0x01234567 = wasm_i8x16_min(vout0x01234567_0x01234567, voutput_max);

    if (nc >= 8) {
      wasm_v128_store64_lane(c0, vout0x01234567_0x01234567, 0);

      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);

      nc -= 8;
    } else {
      if (nc & 4) {
        wasm_v128_store32_lane(c0, vout0x01234567_0x01234567, 0);
        c0 += 4;

        vout0x01234567_0x01234567 = wasm_u64x2_shr(vout0x01234567_0x01234567, 32);
      }
      if (nc & 2) {
        wasm_v128_store16_lane(c0, vout0x01234567_0x01234567, 0);
        c0 += 2;

        vout0x01234567_0x01234567 = wasm_u32x4_shr(vout0x01234567_0x01234567, 16);
      }
      if (nc & 1) {
        wasm_v128_store8_lane(c0, vout0x01234567_0x01234567, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}