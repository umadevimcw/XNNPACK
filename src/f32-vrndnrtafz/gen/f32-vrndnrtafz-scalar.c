// Auto-generated file. Do not edit!
//   Template: src/f32-vrndnrtafz/f32-vrndnrtafz.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/simd/f32-scalar.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_f32_vrndnrtafz_ukernel__scalar_u1(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 1);

  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
}

void xnn_f32_vrndnrtafz_ukernel__scalar_u2(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 1);

  for (; batch >= 2 * sizeof(float); batch -= 2 * sizeof(float)) {
    xnn_simd_f32_t vx0 = xnn_loadu_f32(input);
    xnn_simd_f32_t vx1 = xnn_loadu_f32(input + 1 * xnn_simd_size_f32);
    input += 2;

    xnn_simd_f32_t vy0 = xnn_rndnrtafz_f32(vx0);
    xnn_simd_f32_t vy1 = xnn_rndnrtafz_f32(vx1);
    xnn_storeu_f32(output, vy0);
    
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy1);
    output += 2;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
}

void xnn_f32_vrndnrtafz_ukernel__scalar_u4(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 1);

  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    xnn_simd_f32_t vx0 = xnn_loadu_f32(input);
    xnn_simd_f32_t vx1 = xnn_loadu_f32(input + 1 * xnn_simd_size_f32);
    xnn_simd_f32_t vx2 = xnn_loadu_f32(input + 2 * xnn_simd_size_f32);
    xnn_simd_f32_t vx3 = xnn_loadu_f32(input + 3 * xnn_simd_size_f32);
    input += 4;

    xnn_simd_f32_t vy0 = xnn_rndnrtafz_f32(vx0);
    xnn_simd_f32_t vy1 = xnn_rndnrtafz_f32(vx1);
    xnn_simd_f32_t vy2 = xnn_rndnrtafz_f32(vx2);
    xnn_simd_f32_t vy3 = xnn_rndnrtafz_f32(vx3);
    xnn_storeu_f32(output, vy0);
    
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy1);
    xnn_storeu_f32(output + 2 * xnn_simd_size_f32, vy2);
    xnn_storeu_f32(output + 3 * xnn_simd_size_f32, vy3);
    output += 4;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
}

void xnn_f32_vrndnrtafz_ukernel__scalar_u8(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 1);

  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    xnn_simd_f32_t vx0 = xnn_loadu_f32(input);
    xnn_simd_f32_t vx1 = xnn_loadu_f32(input + 1 * xnn_simd_size_f32);
    xnn_simd_f32_t vx2 = xnn_loadu_f32(input + 2 * xnn_simd_size_f32);
    xnn_simd_f32_t vx3 = xnn_loadu_f32(input + 3 * xnn_simd_size_f32);
    xnn_simd_f32_t vx4 = xnn_loadu_f32(input + 4 * xnn_simd_size_f32);
    xnn_simd_f32_t vx5 = xnn_loadu_f32(input + 5 * xnn_simd_size_f32);
    xnn_simd_f32_t vx6 = xnn_loadu_f32(input + 6 * xnn_simd_size_f32);
    xnn_simd_f32_t vx7 = xnn_loadu_f32(input + 7 * xnn_simd_size_f32);
    input += 8;

    xnn_simd_f32_t vy0 = xnn_rndnrtafz_f32(vx0);
    xnn_simd_f32_t vy1 = xnn_rndnrtafz_f32(vx1);
    xnn_simd_f32_t vy2 = xnn_rndnrtafz_f32(vx2);
    xnn_simd_f32_t vy3 = xnn_rndnrtafz_f32(vx3);
    xnn_simd_f32_t vy4 = xnn_rndnrtafz_f32(vx4);
    xnn_simd_f32_t vy5 = xnn_rndnrtafz_f32(vx5);
    xnn_simd_f32_t vy6 = xnn_rndnrtafz_f32(vx6);
    xnn_simd_f32_t vy7 = xnn_rndnrtafz_f32(vx7);
    xnn_storeu_f32(output, vy0);
    
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy1);
    xnn_storeu_f32(output + 2 * xnn_simd_size_f32, vy2);
    xnn_storeu_f32(output + 3 * xnn_simd_size_f32, vy3);
    xnn_storeu_f32(output + 4 * xnn_simd_size_f32, vy4);
    xnn_storeu_f32(output + 5 * xnn_simd_size_f32, vy5);
    xnn_storeu_f32(output + 6 * xnn_simd_size_f32, vy6);
    xnn_storeu_f32(output + 7 * xnn_simd_size_f32, vy7);
    output += 8;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
}
