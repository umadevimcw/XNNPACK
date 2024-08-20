// Auto-generated file. Do not edit!
//   Template: src/s16-vclz/s16-vclz.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/simd/s16-avx512bw.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_s16_vclz_ukernel__avx512bw_u32(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 32);

  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s16_t vin = xnn_load_tail_s16(input, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_store_tail_s16(output, vy, batch >> XNN_LOG2_SIZEOF_INT16_T);
  }
}

void xnn_s16_vclz_ukernel__avx512bw_u64(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 32);

  for (; batch >= 64 * sizeof(int16_t); batch -= 64 * sizeof(int16_t)) {
    xnn_simd_s16_t vin_0 = xnn_loadu_s16(input);
    xnn_simd_s16_t vin_1 = xnn_loadu_s16(input + 1 * xnn_simd_size_s16);
    input += 64;

    xnn_simd_s16_t vy_0 = xnn_clz_s16(vin_0);
    xnn_simd_s16_t vy_1 = xnn_clz_s16(vin_1);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    output += 64;
  }
  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s16_t vin = xnn_load_tail_s16(input, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_store_tail_s16(output, vy, batch >> XNN_LOG2_SIZEOF_INT16_T);
  }
}
