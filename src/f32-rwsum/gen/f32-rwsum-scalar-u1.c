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

    // padding size
    int32_t pad_row = rows + params->padding[0] + MAX((rows-1), 0) * (params->base_dilations[0] - 1) + params->padding[1];
    int32_t pad_col = cols + params->padding[2] + MAX((cols-1), 0) * (params->base_dilations[1] - 1) + params->padding[3];

    // output size 
    int32_t out_row = (pad_row < (params->window_dimensions[0] - 1) * params->window_dilations[0] + 1) ? 0 : FLOOR((pad_row - (params->window_dimensions[0] - 1) * params->window_dilations[0] - 1) / (float)params->window_strides[0]) + 1;
    int32_t out_col = (pad_col < (params->window_dimensions[1] - 1) * params->window_dilations[1] + 1) ? 0 : FLOOR((pad_col - (params->window_dimensions[1] - 1) * params->window_dilations[1] - 1) / (float)params->window_strides[1]) + 1;
       
    for (int i = 0; i < out_row; i++) {
        for (int j = 0; j < out_col; j++) {
            float sum = init_value;

            for (int k = 0; k < params->window_dimensions[0]; k++) {
                int win_row = i * params->window_strides[0] + k * params->window_dilations[0];
                win_row -= params->padding[0];
                if (win_row < 0 || win_row >= rows * params->base_dilations[0] || win_row % params->base_dilations[0] != 0) {
                    sum += init_value;
                    continue;
                }
                win_row /= params->base_dilations[0];

                for (int l = 0; l < params->window_dimensions[1]; l++) {
                    int win_col = j * params->window_strides[1] + l * params->window_dilations[1];
                    win_col -= params->padding[2];
                    if (win_col < 0 || win_col >= cols * params->base_dilations[1] || win_col % params->base_dilations[1] != 0) {
                        sum += init_value;
                        continue;
                    }
                    win_col /= params->base_dilations[1];

                    sum += input[win_row * cols + win_col];
                }
            }
            output[i * out_col + j] = sum;
        }
    }
}
