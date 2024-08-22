// Auto-generated file. Do not edit!
//   Template: src/s16-vlshift/s16-vlshift.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/simd/s16-wasmsimd.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vbinary.h"


void xnn_s16_vlshift_ukernel__wasmsimd_u8(
    size_t batch,
    const int16_t* input_a,
    const int16_t* input_b,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input_b != NULL);
  assert(input_a != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 8);

  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin1 = xnn_loadu_s16(input_a);
    input_a += xnn_simd_size_s16;

    xnn_simd_s16_t vin2 = xnn_loadu_s16(input_b);
    input_b += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s16_t vin1 = xnn_load_tail_s16(input_a, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vin2 = xnn_load_tail_s16(input_b, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_store_tail_s16(output, vy, batch >> XNN_LOG2_SIZEOF_INT16_T);
  }
}

void xnn_s16_vlshift_ukernel__wasmsimd_u16(
    size_t batch,
    const int16_t* input_a,
    const int16_t* input_b,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input_b != NULL);
  assert(input_a != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 8);

  for (; batch >= 16 * sizeof(int16_t); batch -= 16 * sizeof(int16_t)) {
    xnn_simd_s16_t vin1_0 = xnn_loadu_s16(input_a);
    xnn_simd_s16_t vin1_1 = xnn_loadu_s16(input_a + 1 * xnn_simd_size_s16);
    input_a += 16;

    xnn_simd_s16_t vin2_0 = xnn_loadu_s16(input_b);
    xnn_simd_s16_t vin2_1 = (xnn_loadu_s16(input_b + 1 * xnn_simd_size_s16));
    input_b += 16;

    xnn_simd_s16_t vy_0 = xnn_sllv_s16(vin1_0, vin2_0);
    xnn_simd_s16_t vy_1 = xnn_sllv_s16(vin1_1, vin2_1);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    output += 16;
  }
  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin1 = xnn_loadu_s16(input_a);
    input_a += xnn_simd_size_s16;

    xnn_simd_s16_t vin2 = xnn_loadu_s16(input_b);
    input_b += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s16_t vin1 = xnn_load_tail_s16(input_a, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vin2 = xnn_load_tail_s16(input_b, batch >> XNN_LOG2_SIZEOF_INT16_T);

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_store_tail_s16(output, vy, batch >> XNN_LOG2_SIZEOF_INT16_T);
  }
}
