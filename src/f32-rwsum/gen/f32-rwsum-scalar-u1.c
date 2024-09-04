// Auto-generated file. Do not edit!
//   Template: src/f32-rdsum/scalar.c.in
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
#define CEILING(X) ( ((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X) )


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

  // padding size
    int pad_row = rows + params->padding[0] + MAX((rows-1), 0) * (params->base_dilations[0] - 1) + params->padding[1];
    int pad_col = cols + params->padding[2] + MAX((cols-1), 0) * (params->base_dilations[1] - 1) + params->padding[3];

    // output size 
    int out_row = (pad_row - (params->window_dimensions[0] - 1) * params->window_dilations[0] - 1) / params->window_strides[0] + 1;
    int out_col = (pad_col - (params->window_dimensions[1] - 1) * params->window_dilations[1] - 1) / params->window_strides[1] + 1;
    
    // slice
    int win_row = CEILING(((params->window_dimensions[0] - 1) * params->window_dilations[0] + 1) / (float)params->window_dilations[0]);
    int win_col = CEILING(((params->window_dimensions[1] - 1) * params->window_dilations[1] + 1) / (float)params->window_dilations[1]);
    
    for (int out_r = 0; out_r < out_row ; out_r++)
    {
        for(int out_c = 0; out_c < out_col; out_c++)
        {
            output[out_r * out_col + out_c ] = init_value;  // 0   
            for(int i =0; i<win_row; i++)
            {
                for(int j=0; j<win_col; j++)
                {
                    int r = out_r * params->window_strides[0] + i * params->window_dilations[0];
                    int c = out_c * params->window_strides[1] + j * params->window_dilations[1];

                    int ir = (r - params->padding[0]) / params->base_dilations[0];
                    int ic = (c - params->padding[2]) / params->base_dilations[1];

                    // reduction    
                    if( r < params->padding[0] || r >= pad_row - params->padding[1] || c < params->padding[2] || c >= pad_col - params->padding[3])
                        output[out_r * out_col + out_c ] += init_value;

                    else if ( 0 <= ir && ir < rows && 0 <= ic  && ic < cols)
                    {
                        if ((r - params->padding[0]) % params->base_dilations[0] == 0 &&(c - params->padding[2]) % params->base_dilations[1] == 0 )
                            output[out_r * out_col + out_c ] += input[ ir * cols  + ic];
                        else 
                           output[out_r * out_col + out_c ] += init_value; //0;
                    }                   

                }
            }
        }
    }
}
