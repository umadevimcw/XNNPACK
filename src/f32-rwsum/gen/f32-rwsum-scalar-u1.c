// Auto-generated file. Do not edit!
//   Template: src/f32-rwsum/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "xnnpack/common.h"
#include "xnnpack/reduce.h"

#define MAX(X,Y) (X > Y ? X : Y)
#define CEILING_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))
#define CEILING_NEG(X) (int)(X)
#define CEIL(X) ( ((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X) )

#define FLOORING_POS(X) (int)(X)
#define FLOORING_NEG(X) ((X-(int)(X)) > 0 ? (int)(X-1) : (int)(X))
#define FLOOR(X) ( ((X) > 0) ? FLOORING_POS(X) : FLOORING_NEG(X) )

void xnn_f32_rwsum_ukernel__scalar_u1(
    size_t rows,
    size_t cols,
    const float* input,
    const float init_value,
    float* output,
    const union xnn_f32_reducewindow_params params[restrict XNN_MIN_ELEMENTS(1)])
{
    assert(rows != 0);
    assert(cols != 0);
    assert(input != NULL);
    assert(output != NULL);
    assert(0 < params->window_dimensions[0]);
    assert(0 < params->window_dimensions[1]);
    assert(0 < params->window_strides[0]);
    assert(0 < params->window_strides[1]);
    assert(0 < params->base_dilations[0]);
    assert(0 < params->base_dilations[1]);
    assert(0 < params->window_dilations[0]);
    assert(0 < params->window_dilations[1]);

    // padding size
    int32_t pad_row = rows + params->padding[0] + MAX((rows-1), 0) * (params->base_dilations[0] - 1) + params->padding[1];
    int32_t pad_col = cols + params->padding[2] + MAX((cols-1), 0) * (params->base_dilations[1] - 1) + params->padding[3];

    // output size 
    int32_t out_row = (pad_row < (params->window_dimensions[0] - 1) * params->window_dilations[0] + 1) ? 0 : FLOOR((pad_row - (params->window_dimensions[0] - 1) * params->window_dilations[0] - 1) / (float)params->window_strides[0]) + 1;
    int32_t out_col = (pad_col < (params->window_dimensions[1] - 1) * params->window_dilations[1] + 1) ? 0 : FLOOR((pad_col - (params->window_dimensions[1] - 1) * params->window_dilations[1] - 1) / (float)params->window_strides[1]) + 1;
      
    // slice
    int32_t win_row = CEIL(((params->window_dimensions[0] - 1) * params->window_dilations[0] + 1) / (float)params->window_dilations[0]);
    int32_t win_col = CEIL(((params->window_dimensions[1] - 1) * params->window_dilations[1] + 1) / (float)params->window_dilations[1]);
    
    for (int32_t out_r = 0; out_r < out_row ; out_r++)
    {
        for(int32_t out_c = 0; out_c < out_col; out_c++)
        {
            output[out_r * out_col + out_c ] = init_value;  // 0   
            for(int32_t i = 0; i < win_row; i++)
            {
                for(int32_t j = 0; j < win_col; j++)
                {
                    int32_t r = out_r * params->window_strides[0] + i * params->window_dilations[0];
                    int32_t c = out_c * params->window_strides[1] + j * params->window_dilations[1];

                    int32_t ir = (r - params->padding[0]) / params->base_dilations[0];
                    int32_t ic = (c - params->padding[2]) / params->base_dilations[1];

                    // reduction    
                    if( r < params->padding[0] || r >= pad_row - params->padding[1] || c < params->padding[2] || c >= pad_col - params->padding[3])
                        output[out_r * out_col + out_c ] += init_value;

                    else if ( 0 <= ir && ir < rows && 0 <= ic  && ic < cols)
                    {
                        if ((r - params->padding[0]) % params->base_dilations[0] == 0 && (c - params->padding[2]) % params->base_dilations[1] == 0 )
                            output[out_r * out_col + out_c ] += input[ ir * cols  + ic];
                        else 
                           output[out_r * out_col + out_c ] += init_value; //0;
                    }                   

                }
            }
        }
    }
}
