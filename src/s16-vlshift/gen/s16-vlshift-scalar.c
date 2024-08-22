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

#include "xnnpack/simd/s16-scalar.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vbinary.h"


void xnn_s16_vlshift_ukernel__scalar_u1(
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
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= xnn_simd_bytes_s16; batch -= xnn_simd_bytes_s16) {
    xnn_simd_s16_t vin1 = xnn_loadu_s16(input_a);
    input_a += xnn_simd_size_s16;

    xnn_simd_s16_t vin2 = xnn_loadu_s16(input_b);
    input_b += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}

void xnn_s16_vlshift_ukernel__scalar_u2(
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
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 2 * sizeof(int16_t); batch -= 2 * sizeof(int16_t)) {
    xnn_simd_s16_t vin1_0 = xnn_loadu_s16(input_a);
    xnn_simd_s16_t vin1_1 = xnn_loadu_s16(input_a + 1 * xnn_simd_size_s16);
    input_a += 2;

    xnn_simd_s16_t vin2_0 = xnn_loadu_s16(input_b);
    xnn_simd_s16_t vin2_1 = (xnn_loadu_s16(input_b + 1 * xnn_simd_size_s16));
    input_b += 2;

    xnn_simd_s16_t vy_0 = xnn_sllv_s16(vin1_0, vin2_0);
    xnn_simd_s16_t vy_1 = xnn_sllv_s16(vin1_1, vin2_1);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    output += 2;
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
}

void xnn_s16_vlshift_ukernel__scalar_u4(
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
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 4 * sizeof(int16_t); batch -= 4 * sizeof(int16_t)) {
    xnn_simd_s16_t vin1_0 = xnn_loadu_s16(input_a);
    xnn_simd_s16_t vin1_1 = xnn_loadu_s16(input_a + 1 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_2 = xnn_loadu_s16(input_a + 2 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_3 = xnn_loadu_s16(input_a + 3 * xnn_simd_size_s16);
    input_a += 4;

    xnn_simd_s16_t vin2_0 = xnn_loadu_s16(input_b);
    xnn_simd_s16_t vin2_1 = (xnn_loadu_s16(input_b + 1 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_2 = (xnn_loadu_s16(input_b + 2 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_3 = (xnn_loadu_s16(input_b + 3 * xnn_simd_size_s16));
    input_b += 4;

    xnn_simd_s16_t vy_0 = xnn_sllv_s16(vin1_0, vin2_0);
    xnn_simd_s16_t vy_1 = xnn_sllv_s16(vin1_1, vin2_1);
    xnn_simd_s16_t vy_2 = xnn_sllv_s16(vin1_2, vin2_2);
    xnn_simd_s16_t vy_3 = xnn_sllv_s16(vin1_3, vin2_3);

    xnn_storeu_s16(output, vy_0);
    xnn_storeu_s16(output + 1 * xnn_simd_size_s16, vy_1);
    xnn_storeu_s16(output + 2 * xnn_simd_size_s16, vy_2);
    xnn_storeu_s16(output + 3 * xnn_simd_size_s16, vy_3);
    output += 4;
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
}

void xnn_s16_vlshift_ukernel__scalar_u8(
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
  assert(xnn_simd_size_s16 == 1);

  for (; batch >= 8 * sizeof(int16_t); batch -= 8 * sizeof(int16_t)) {
    xnn_simd_s16_t vin1_0 = xnn_loadu_s16(input_a);
    xnn_simd_s16_t vin1_1 = xnn_loadu_s16(input_a + 1 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_2 = xnn_loadu_s16(input_a + 2 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_3 = xnn_loadu_s16(input_a + 3 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_4 = xnn_loadu_s16(input_a + 4 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_5 = xnn_loadu_s16(input_a + 5 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_6 = xnn_loadu_s16(input_a + 6 * xnn_simd_size_s16);
    xnn_simd_s16_t vin1_7 = xnn_loadu_s16(input_a + 7 * xnn_simd_size_s16);
    input_a += 8;

    xnn_simd_s16_t vin2_0 = xnn_loadu_s16(input_b);
    xnn_simd_s16_t vin2_1 = (xnn_loadu_s16(input_b + 1 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_2 = (xnn_loadu_s16(input_b + 2 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_3 = (xnn_loadu_s16(input_b + 3 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_4 = (xnn_loadu_s16(input_b + 4 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_5 = (xnn_loadu_s16(input_b + 5 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_6 = (xnn_loadu_s16(input_b + 6 * xnn_simd_size_s16));
    xnn_simd_s16_t vin2_7 = (xnn_loadu_s16(input_b + 7 * xnn_simd_size_s16));
    input_b += 8;

    xnn_simd_s16_t vy_0 = xnn_sllv_s16(vin1_0, vin2_0);
    xnn_simd_s16_t vy_1 = xnn_sllv_s16(vin1_1, vin2_1);
    xnn_simd_s16_t vy_2 = xnn_sllv_s16(vin1_2, vin2_2);
    xnn_simd_s16_t vy_3 = xnn_sllv_s16(vin1_3, vin2_3);
    xnn_simd_s16_t vy_4 = xnn_sllv_s16(vin1_4, vin2_4);
    xnn_simd_s16_t vy_5 = xnn_sllv_s16(vin1_5, vin2_5);
    xnn_simd_s16_t vy_6 = xnn_sllv_s16(vin1_6, vin2_6);
    xnn_simd_s16_t vy_7 = xnn_sllv_s16(vin1_7, vin2_7);

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
    xnn_simd_s16_t vin1 = xnn_loadu_s16(input_a);
    input_a += xnn_simd_size_s16;

    xnn_simd_s16_t vin2 = xnn_loadu_s16(input_b);
    input_b += xnn_simd_size_s16;

    xnn_simd_s16_t vy = xnn_sllv_s16(vin1, vin2);

    xnn_storeu_s16(output, vy);
    output += xnn_simd_size_s16;
  }
}
