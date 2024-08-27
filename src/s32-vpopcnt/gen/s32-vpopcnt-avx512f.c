// Auto-generated file. Do not edit!
//   Template: src/s32-vpopcnt/s32-vpopcnt.c.in
//   Generator: .\tools\xngen.py
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/simd/s32-avx512f.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_s32_vpopcnt_ukernel__avx512f_u16(
    size_t batch,
    const int32_t* input,
    int32_t* output,
    const union xnn_s32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int32_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s32 == 16);

  for (; batch >= xnn_simd_bytes_s32; batch -= xnn_simd_bytes_s32) {
    xnn_simd_s32_t vin = xnn_loadu_s32(input);
    input += xnn_simd_size_s32;

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_storeu_s32(output, vy);
    output += xnn_simd_size_s32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s32_t vin = xnn_load_tail_s32(input, batch >> XNN_LOG2_SIZEOF_INT32_T);

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_store_tail_s32(output, vy, batch >> XNN_LOG2_SIZEOF_INT32_T);
  }
}

void xnn_s32_vpopcnt_ukernel__avx512f_u32(
    size_t batch,
    const int32_t* input,
    int32_t* output,
    const union xnn_s32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int32_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s32 == 16);

  for (; batch >= 32 * sizeof(int32_t); batch -= 32 * sizeof(int32_t)) {
    xnn_simd_s32_t vin_0 = xnn_loadu_s32(input);
    xnn_simd_s32_t vin_1 = xnn_loadu_s32(input + 1 * xnn_simd_size_s32);
    input += 32;

    xnn_simd_s32_t vy_0 = xnn_popcnt_s32(vin_0);
    xnn_simd_s32_t vy_1 = xnn_popcnt_s32(vin_1);

    xnn_storeu_s32(output, vy_0);
    xnn_storeu_s32(output + 1 * xnn_simd_size_s32, vy_1);
    output += 32;
  }
  for (; batch >= xnn_simd_bytes_s32; batch -= xnn_simd_bytes_s32) {
    xnn_simd_s32_t vin = xnn_loadu_s32(input);
    input += xnn_simd_size_s32;

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_storeu_s32(output, vy);
    output += xnn_simd_size_s32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s32_t vin = xnn_load_tail_s32(input, batch >> XNN_LOG2_SIZEOF_INT32_T);

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_store_tail_s32(output, vy, batch >> XNN_LOG2_SIZEOF_INT32_T);
  }
}

void xnn_s32_vpopcnt_ukernel__avx512f_u48(
    size_t batch,
    const int32_t* input,
    int32_t* output,
    const union xnn_s32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int32_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s32 == 16);

  for (; batch >= 48 * sizeof(int32_t); batch -= 48 * sizeof(int32_t)) {
    xnn_simd_s32_t vin_0 = xnn_loadu_s32(input);
    xnn_simd_s32_t vin_1 = xnn_loadu_s32(input + 1 * xnn_simd_size_s32);
    xnn_simd_s32_t vin_2 = xnn_loadu_s32(input + 2 * xnn_simd_size_s32);
    input += 48;

    xnn_simd_s32_t vy_0 = xnn_popcnt_s32(vin_0);
    xnn_simd_s32_t vy_1 = xnn_popcnt_s32(vin_1);
    xnn_simd_s32_t vy_2 = xnn_popcnt_s32(vin_2);

    xnn_storeu_s32(output, vy_0);
    xnn_storeu_s32(output + 1 * xnn_simd_size_s32, vy_1);
    xnn_storeu_s32(output + 2 * xnn_simd_size_s32, vy_2);
    output += 48;
  }
  for (; batch >= xnn_simd_bytes_s32; batch -= xnn_simd_bytes_s32) {
    xnn_simd_s32_t vin = xnn_loadu_s32(input);
    input += xnn_simd_size_s32;

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_storeu_s32(output, vy);
    output += xnn_simd_size_s32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s32_t vin = xnn_load_tail_s32(input, batch >> XNN_LOG2_SIZEOF_INT32_T);

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_store_tail_s32(output, vy, batch >> XNN_LOG2_SIZEOF_INT32_T);
  }
}

void xnn_s32_vpopcnt_ukernel__avx512f_u64(
    size_t batch,
    const int32_t* input,
    int32_t* output,
    const union xnn_s32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(int32_t) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_s32 == 16);

  for (; batch >= 64 * sizeof(int32_t); batch -= 64 * sizeof(int32_t)) {
    xnn_simd_s32_t vin_0 = xnn_loadu_s32(input);
    xnn_simd_s32_t vin_1 = xnn_loadu_s32(input + 1 * xnn_simd_size_s32);
    xnn_simd_s32_t vin_2 = xnn_loadu_s32(input + 2 * xnn_simd_size_s32);
    xnn_simd_s32_t vin_3 = xnn_loadu_s32(input + 3 * xnn_simd_size_s32);
    input += 64;

    xnn_simd_s32_t vy_0 = xnn_popcnt_s32(vin_0);
    xnn_simd_s32_t vy_1 = xnn_popcnt_s32(vin_1);
    xnn_simd_s32_t vy_2 = xnn_popcnt_s32(vin_2);
    xnn_simd_s32_t vy_3 = xnn_popcnt_s32(vin_3);

    xnn_storeu_s32(output, vy_0);
    xnn_storeu_s32(output + 1 * xnn_simd_size_s32, vy_1);
    xnn_storeu_s32(output + 2 * xnn_simd_size_s32, vy_2);
    xnn_storeu_s32(output + 3 * xnn_simd_size_s32, vy_3);
    output += 64;
  }
  for (; batch >= xnn_simd_bytes_s32; batch -= xnn_simd_bytes_s32) {
    xnn_simd_s32_t vin = xnn_loadu_s32(input);
    input += xnn_simd_size_s32;

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_storeu_s32(output, vy);
    output += xnn_simd_size_s32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_s32_t vin = xnn_load_tail_s32(input, batch >> XNN_LOG2_SIZEOF_INT32_T);

    xnn_simd_s32_t vy = xnn_popcnt_s32(vin);

    xnn_store_tail_s32(output, vy, batch >> XNN_LOG2_SIZEOF_INT32_T);
  }
}
