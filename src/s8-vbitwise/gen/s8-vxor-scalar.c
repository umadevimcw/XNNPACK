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

#include "xnnpack/simd/s8-scalar.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_s8_vxor_ukernel__scalar_u1(
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
  assert(xnn_simd_size_s8 == 1);

  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_xor_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
}

void xnn_s8_vxor_ukernel__scalar_u2(
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
  assert(xnn_simd_size_s8 == 1);

  for (; batch >= 2 * sizeof(int8_t); batch -= 2 * sizeof(int8_t)) {
    xnn_simd_s8_t vin1_0 = xnn_loadu_s8(input_a);
    xnn_simd_s8_t vin1_1 = xnn_loadu_s8(input_a + 1 * xnn_simd_size_s8);
    input_a += 2;

    xnn_simd_s8_t vin2_0 = xnn_loadu_s8(input_b);
    xnn_simd_s8_t vin2_1 = (xnn_loadu_s8(input_b + 1 * xnn_simd_size_s8));
    input_b += 2;

    xnn_simd_s8_t vy_0 = xnn_xor_s8(vin1_0, vin2_0);
    xnn_simd_s8_t vy_1 = xnn_xor_s8(vin1_1, vin2_1);

    xnn_storeu_s8(output, vy_0);
    xnn_storeu_s8(output + 1 * xnn_simd_size_s8, vy_1);
    output += 2;
  }
  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_xor_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
}

void xnn_s8_vxor_ukernel__scalar_u4(
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
  assert(xnn_simd_size_s8 == 1);

  for (; batch >= 4 * sizeof(int8_t); batch -= 4 * sizeof(int8_t)) {
    xnn_simd_s8_t vin1_0 = xnn_loadu_s8(input_a);
    xnn_simd_s8_t vin1_1 = xnn_loadu_s8(input_a + 1 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_2 = xnn_loadu_s8(input_a + 2 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_3 = xnn_loadu_s8(input_a + 3 * xnn_simd_size_s8);
    input_a += 4;

    xnn_simd_s8_t vin2_0 = xnn_loadu_s8(input_b);
    xnn_simd_s8_t vin2_1 = (xnn_loadu_s8(input_b + 1 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_2 = (xnn_loadu_s8(input_b + 2 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_3 = (xnn_loadu_s8(input_b + 3 * xnn_simd_size_s8));
    input_b += 4;

    xnn_simd_s8_t vy_0 = xnn_xor_s8(vin1_0, vin2_0);
    xnn_simd_s8_t vy_1 = xnn_xor_s8(vin1_1, vin2_1);
    xnn_simd_s8_t vy_2 = xnn_xor_s8(vin1_2, vin2_2);
    xnn_simd_s8_t vy_3 = xnn_xor_s8(vin1_3, vin2_3);

    xnn_storeu_s8(output, vy_0);
    xnn_storeu_s8(output + 1 * xnn_simd_size_s8, vy_1);
    xnn_storeu_s8(output + 2 * xnn_simd_size_s8, vy_2);
    xnn_storeu_s8(output + 3 * xnn_simd_size_s8, vy_3);
    output += 4;
  }
  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_xor_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
}

void xnn_s8_vxor_ukernel__scalar_u8(
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
  assert(xnn_simd_size_s8 == 1);

  for (; batch >= 8 * sizeof(int8_t); batch -= 8 * sizeof(int8_t)) {
    xnn_simd_s8_t vin1_0 = xnn_loadu_s8(input_a);
    xnn_simd_s8_t vin1_1 = xnn_loadu_s8(input_a + 1 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_2 = xnn_loadu_s8(input_a + 2 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_3 = xnn_loadu_s8(input_a + 3 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_4 = xnn_loadu_s8(input_a + 4 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_5 = xnn_loadu_s8(input_a + 5 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_6 = xnn_loadu_s8(input_a + 6 * xnn_simd_size_s8);
    xnn_simd_s8_t vin1_7 = xnn_loadu_s8(input_a + 7 * xnn_simd_size_s8);
    input_a += 8;

    xnn_simd_s8_t vin2_0 = xnn_loadu_s8(input_b);
    xnn_simd_s8_t vin2_1 = (xnn_loadu_s8(input_b + 1 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_2 = (xnn_loadu_s8(input_b + 2 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_3 = (xnn_loadu_s8(input_b + 3 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_4 = (xnn_loadu_s8(input_b + 4 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_5 = (xnn_loadu_s8(input_b + 5 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_6 = (xnn_loadu_s8(input_b + 6 * xnn_simd_size_s8));
    xnn_simd_s8_t vin2_7 = (xnn_loadu_s8(input_b + 7 * xnn_simd_size_s8));
    input_b += 8;

    xnn_simd_s8_t vy_0 = xnn_xor_s8(vin1_0, vin2_0);
    xnn_simd_s8_t vy_1 = xnn_xor_s8(vin1_1, vin2_1);
    xnn_simd_s8_t vy_2 = xnn_xor_s8(vin1_2, vin2_2);
    xnn_simd_s8_t vy_3 = xnn_xor_s8(vin1_3, vin2_3);
    xnn_simd_s8_t vy_4 = xnn_xor_s8(vin1_4, vin2_4);
    xnn_simd_s8_t vy_5 = xnn_xor_s8(vin1_5, vin2_5);
    xnn_simd_s8_t vy_6 = xnn_xor_s8(vin1_6, vin2_6);
    xnn_simd_s8_t vy_7 = xnn_xor_s8(vin1_7, vin2_7);

    xnn_storeu_s8(output, vy_0);
    xnn_storeu_s8(output + 1 * xnn_simd_size_s8, vy_1);
    xnn_storeu_s8(output + 2 * xnn_simd_size_s8, vy_2);
    xnn_storeu_s8(output + 3 * xnn_simd_size_s8, vy_3);
    xnn_storeu_s8(output + 4 * xnn_simd_size_s8, vy_4);
    xnn_storeu_s8(output + 5 * xnn_simd_size_s8, vy_5);
    xnn_storeu_s8(output + 6 * xnn_simd_size_s8, vy_6);
    xnn_storeu_s8(output + 7 * xnn_simd_size_s8, vy_7);
    output += 8;
  }
  for (; batch >= xnn_simd_bytes_s8; batch -= xnn_simd_bytes_s8) {
    xnn_simd_s8_t vin1 = xnn_loadu_s8(input_a);
    input_a += xnn_simd_size_s8;

    xnn_simd_s8_t vin2 = xnn_loadu_s8(input_b);
    input_b += xnn_simd_size_s8;

    xnn_simd_s8_t vy = xnn_xor_s8(vin1, vin2);

    xnn_storeu_s8(output, vy);
    output += xnn_simd_size_s8;
  }
}
