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

#include "xnnpack/simd/f32-hvx.h"

#include "xnnpack/common.h"
#include "xnnpack/microparams.h"
#include "xnnpack/vunary.h"


void xnn_f32_vrndnrtafz_ukernel__hvx_u32(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vx = xnn_load_tail_f32(input, batch >> XNN_LOG2_SIZEOF_FLOAT);

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}

void xnn_f32_vrndnrtafz_ukernel__hvx_u64(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  for (; batch >= 64 * sizeof(float); batch -= 64 * sizeof(float)) {
    xnn_simd_f32_t vx0 = xnn_loadu_f32(input);
    xnn_simd_f32_t vx1 = xnn_loadu_f32(input + 1 * xnn_simd_size_f32);
    input += 64;

    xnn_simd_f32_t vy0 = xnn_rndnrtafz_f32(vx0);
    xnn_simd_f32_t vy1 = xnn_rndnrtafz_f32(vx1);
    xnn_storeu_f32(output, vy0);
    
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy1);
    output += 64;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vx = xnn_loadu_f32(input);
    input += xnn_simd_size_f32;

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vx = xnn_load_tail_f32(input, batch >> XNN_LOG2_SIZEOF_FLOAT);

    xnn_simd_f32_t vy = xnn_rndnrtafz_f32(vx);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}
