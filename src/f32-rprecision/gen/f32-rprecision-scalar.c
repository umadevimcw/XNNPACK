// Auto-generated file. Do not edit!
//   Template: src/f32-rprecision/f32-rprecision.c.in
//   Generator: tools/xngen.py
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
#include <assert.h>
#include "xnnpack/common.h"
#include "xnnpack/math.h"
#include "xnnpack/reduce.h"

#define MANTISSA_BITS 23
#define EXPONENT_BIAS 127  

void xnn_f32_rprecision_ukernel__scalar_u1(
  size_t batch,
  const float* input,
  const int exponent_bits,
  const int mantissa_bits,
  float* output,
  const struct xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  
  union mem
  {
      float f;
      int i;
  }Mi,Mo;
  
  const int32_t bias = (1U << (exponent_bits - 1)) - 1;
  const int32_t exp_max = (1U << exponent_bits) - 2 - bias;
  const int32_t exp_min = 1 - bias;

  do 
  {
    Mi.f = *input++;

    int32_t exp_size = (Mi.i >> MANTISSA_BITS) & 0x0FF;                        
    uint32_t mantissa = Mi.i & ((1U << MANTISSA_BITS) - 1);
    mantissa = mantissa >> (MANTISSA_BITS - mantissa_bits);
    if(exp_size != 0x0 && exp_size != 0x0FF)
    {
        exp_size -= EXPONENT_BIAS;                                             
        if (Mi.i & (1U << (MANTISSA_BITS - mantissa_bits -1)))  
        {
            mantissa += 1;
            if( mantissa >= (1U << mantissa_bits))
            {
                mantissa = mantissa & ((1U << mantissa_bits) - 1);
                exp_size += 1;
            }
        }
    }
    Mo.i = (Mi.i & 0x80000000) |  ( mantissa << (MANTISSA_BITS - mantissa_bits));
    if (exp_size < exp_min || exp_size > exp_max)
    {
        Mo.i = Mo.i |  0x7F800000 ;
    }
    else 
    {
        if(exp_size != 0x0)
            exp_size = EXPONENT_BIAS + exp_size;
        Mo.i = Mo.i | ( exp_size << MANTISSA_BITS) ;
    }
    *output++ = Mo.f;
    batch -= sizeof(float);
  }while(batch != 0);
}
void xnn_f32_rprecision_ukernel__scalar_u2(
  size_t batch,
  const float* input,
  const int exponent_bits,
  const int mantissa_bits,
  float* output,
  const struct xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);
  
  union mem
  {
      float f;
      int i;
  }Mi,Mo;
  
  const int32_t bias = (1U << (exponent_bits - 1)) - 1;
  const int32_t exp_max = (1U << exponent_bits) - 2 - bias;
  const int32_t exp_min = 1 - bias;

}
