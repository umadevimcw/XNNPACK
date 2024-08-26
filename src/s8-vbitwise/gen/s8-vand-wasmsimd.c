// Auto-generated file. Do not edit!
//   Template: src/s8-vbitwise/s8-vbitwise.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/simd/s8-wasmsimd.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_s8_vand_ukernel__wasmsimd_u16(
    size_t batch,
    const int8_t* input_a,
    const int8_t* input_b,
    int8_t* output,
    const union xnn_s8_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int8_t) == 0);
  assert(input_b != NULL);
  assert(input_a != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s8 == 16);

  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_and_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s8_t vin1 = xnn_load_tail_s8(input_a, batch >> XNN_LOG2_SIZEOF_INT8_T);

    xnn_simd_s8_t vin2 = xnn_load_tail_s8(input_b, batch >> XNN_LOG2_SIZEOF_INT8_T);

    xnn_simd_s8_t vy = xnn_and_s8(vin1, vin2);

    xnn_store_tail_s8(output, vy, batch >> XNN_LOG2_SIZEOF_INT8_T);
  }
}

void xnn_s8_vand_ukernel__wasmsimd_u32(
    size_t batch,
    const int8_t* input_a,
    const int8_t* input_b,
    int8_t* output,
    const union xnn_s8_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int8_t) == 0);
  assert(input_b != NULL);
  assert(input_a != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s8 == 16);

  for (; batch >= 32 * sizeof(int8_t); batch -= 32 * sizeof(int8_t)) {
    xnn_simd_s8_t vin1_0 = xnn_loadu_s8(input_a);
    xnn_simd_s8_t vin1_1 = xnn_loadu_s8(input_a + 1 * xnn_simd_size_s8);
    input_a += 32;

    xnn_simd_s8_t vin2_0 = xnn_loadu_s8(input_b);
    xnn_simd_s8_t vin2_1 = (xnn_loadu_s8(input_b + 1 * xnn_simd_size_s8));
    input_b += 32;

    xnn_simd_s8_t vy_0 = xnn_and_s8(vin1_0, vin2_0);
    xnn_simd_s8_t vy_1 = xnn_and_s8(vin1_1, vin2_1);

    xnn_storeu_s8(output, vy_0);
    xnn_storeu_s8(output + 1 * xnn_simd_size_s8, vy_1);
    output += 32;
  }
  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_and_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s8_t vin1 = xnn_load_tail_s8(input_a, batch >> XNN_LOG2_SIZEOF_INT8_T);

    xnn_simd_s8_t vin2 = xnn_load_tail_s8(input_b, batch >> XNN_LOG2_SIZEOF_INT8_T);

    xnn_simd_s8_t vy = xnn_and_s8(vin1, vin2);

    xnn_store_tail_s8(output, vy, batch >> XNN_LOG2_SIZEOF_INT8_T);
  }
}
