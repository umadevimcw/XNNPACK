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

#include "xnnpack/simd/s16-scalar.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_s16_vclz_ukernel__scalar_u1(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}

void xnn_s16_vclz_ukernel__scalar_u2(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 2 * sizeof(int16_t); batch -= 2 * sizeof(int16_t)) {
    xnn_simd_s16_t vin_0 = xnn_loadu_s16(input);
    xnn_simd_s16_t vin_1 = xnn_loadu_s16(input + 1 * xnn_simd_size_s16);
    input += 2;

    xnn_simd_s16_t vy_0 = xnn_clz_s16(vin_0);
    xnn_simd_s16_t vy_1 = xnn_clz_s16(vin_1);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    output += 2;
  }
  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}

void xnn_s16_vclz_ukernel__scalar_u4(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 4 * sizeof(int16_t); batch -= 4 * sizeof(int16_t)) {
    xnn_simd_s16_t vin_0 = xnn_loadu_s16(input);
    xnn_simd_s16_t vin_1 = xnn_loadu_s16(input + 1 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_2 = xnn_loadu_s16(input + 2 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_3 = xnn_loadu_s16(input + 3 * xnn_simd_size_s16);
    input += 4;

    xnn_simd_s16_t vy_0 = xnn_clz_s16(vin_0);
    xnn_simd_s16_t vy_1 = xnn_clz_s16(vin_1);
    xnn_simd_s16_t vy_2 = xnn_clz_s16(vin_2);
    xnn_simd_s16_t vy_3 = xnn_clz_s16(vin_3);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    xnn_storeu_s16(output + 2 * xnn_simd_size_s16, vy_2);
    xnn_storeu_s16(output + 3 * xnn_simd_size_s16, vy_3);
    output += 4;
  }
  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}

void xnn_s16_vclz_ukernel__scalar_u8(
    size_t batch,
    const int16_t* input,
    int16_t* output,
    const union xnn_s16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 8 * sizeof(int16_t); batch -= 8 * sizeof(int16_t)) {
    xnn_simd_s16_t vin_0 = xnn_loadu_s16(input);
    xnn_simd_s16_t vin_1 = xnn_loadu_s16(input + 1 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_2 = xnn_loadu_s16(input + 2 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_3 = xnn_loadu_s16(input + 3 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_4 = xnn_loadu_s16(input + 4 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_5 = xnn_loadu_s16(input + 5 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_6 = xnn_loadu_s16(input + 6 * xnn_simd_size_s16);
    xnn_simd_s16_t vin_7 = xnn_loadu_s16(input + 7 * xnn_simd_size_s16);
    input += 8;

    xnn_simd_s16_t vy_0 = xnn_clz_s16(vin_0);
    xnn_simd_s16_t vy_1 = xnn_clz_s16(vin_1);
    xnn_simd_s16_t vy_2 = xnn_clz_s16(vin_2);
    xnn_simd_s16_t vy_3 = xnn_clz_s16(vin_3);
    xnn_simd_s16_t vy_4 = xnn_clz_s16(vin_4);
    xnn_simd_s16_t vy_5 = xnn_clz_s16(vin_5);
    xnn_simd_s16_t vy_6 = xnn_clz_s16(vin_6);
    xnn_simd_s16_t vy_7 = xnn_clz_s16(vin_7);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    xnn_storeu_s16(output + 2 * xnn_simd_size_s16, vy_2);
    xnn_storeu_s16(output + 3 * xnn_simd_size_s16, vy_3);
    xnn_storeu_s16(output + 4 * xnn_simd_size_s16, vy_4);
    xnn_storeu_s16(output + 5 * xnn_simd_size_s16, vy_5);
    xnn_storeu_s16(output + 6 * xnn_simd_size_s16, vy_6);
    xnn_storeu_s16(output + 7 * xnn_simd_size_s16, vy_7);
    output += 8;
  }
  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin = xnn_loadu_s16(input);
    input += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_clz_s16(vin);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}
