// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <random>
#include <vector>

#include <gtest/gtest.h>
#include <fp16/fp16.h>
#include "xnnpack.h"
#include "xnnpack/aligned-allocator.h"
#include "xnnpack/microfnptr.h"
#include "xnnpack/microparams.h"
#include "xnnpack/requantization.h"
#include "replicable_random_device.h"

class ReduceWindowMicrokernelTester {
 public:
  enum class OpType {
    Sum,
  };

  ReduceWindowMicrokernelTester& rows(int32_t rows) {
    assert(rows != 0);
    this->rows_ = rows;
    return *this;
  }

  int32_t rows() const {
    return this->rows_;
  }

  ReduceWindowMicrokernelTester& cols(int32_t cols) {
    assert(cols != 0);
    this->cols_ = cols;
    return *this;
  }

  int32_t cols() const {
    return this->cols_;
  }
  

  ReduceWindowMicrokernelTester& iterations(int32_t iterations) {
    this->iterations_ = iterations;
    return *this;
  }

  int32_t iterations() const {
    return this->iterations_;
  }


  void Test(xnn_f32_reducewindow_ukernel_fn reducewindow, OpType op_type, xnn_init_f32_reducewindow_params_fn init_params) const {
    xnnpack::ReplicableRandomDevice rng;
    std::uniform_real_distribution<float> f32dist;
    std::uniform_int_distribution<int32_t> s32dist(1, 10);
    
    std::vector<float> input(rows() * cols() + XNN_EXTRA_BYTES / sizeof(float));
    float init_value = 0.0;
    std::vector<int32_t> wnddim(2);
    std::vector<int32_t> wndstrd(2);
    std::vector<int32_t> basedil(2);
    std::vector<int32_t> wnddil(2);
    std::vector<int32_t> padding(4);

    std::vector<float> output;
    std::vector<float> output_ref;

    for (int32_t iteration = 0; iteration < iterations(); iteration++) {
      std::generate(input.begin(), input.end(), [&]() { return f32dist(rng); });
      
      std::generate(wnddim.begin(), wnddim.end(), [&]() { return s32dist(rng); });
      std::generate(wndstrd.begin(), wndstrd.end(), [&]() { return s32dist(rng); });
      std::generate(basedil.begin(), basedil.end(), [&]() { return s32dist(rng); });
      std::generate(wnddil.begin(), wnddil.end(), [&]() { return s32dist(rng); });
      std::generate(padding.begin(), padding.end(), [&]() { return s32dist(rng); });

      int32_t pad_row = rows() + padding[0] + max((rows()-1), 0) * (basedil[0]-1) + padding[1];
      int32_t pad_col = cols() + padding[2] + max((cols()-1), 0) * (basedil[1]-1) + padding[3];    
      int32_t out_row = (pad_row < (wnddim[0] - 1) * wnddil[0] + 1) ? 0 : floor((pad_row - (wnddim[0] - 1) * wnddil[0] - 1) / (float)wndstrd[0]) + 1;
      int32_t out_col = (pad_col < (wnddim[1] - 1) * wnddil[1] + 1) ? 0 : floor((pad_col - (wnddim[1] - 1) * wnddil[1] - 1) / (float)wndstrd[1]) + 1;
      
      if(out_row > 0 &&  out_col > 0)
      {
        output.assign(out_row * out_col, init_value);
        output_ref.assign(out_row * out_col, init_value);
      }
      
      // Prepare parameters.
      union xnn_f32_reducewindow_params params;
      if (init_params != nullptr) {
      init_params(&params, wnddim.data(), wndstrd.data(), basedil.data(), wnddil.data(), padding.data());
      }
      // Compute reference results.
      int32_t win_row = ceil(((wnddim[0] - 1) * wnddil[0] + 1) / (float)wnddil[0]);
      int32_t win_col = ceil(((wnddim[1] - 1) * wnddil[1] + 1) / (float)wnddil[1]);
      
      for (int32_t out_r = 0; out_r < out_row; out_r++){
        for(int32_t out_c = 0; out_c < out_col; out_c++){
            
          output_ref[out_r * out_col + out_c ] = init_value;  // 0;
          for(int32_t i =0; i<win_row; i++)
          {
            for(int32_t j=0; j<win_col; j++)
            {
              int32_t r = out_r * wndstrd[0] + i * wnddil[0];
              int32_t c = out_c * wndstrd[1] + j * wnddil[1];

              int32_t ir = (r - padding[0]) / basedil[0];
              int32_t ic = (c - padding[2]) / basedil[1];
              // reduction    
              switch (op_type) {
                case OpType::Sum:{
                  if( r < padding[0] || r >= pad_row - padding[1] || c < padding[2] || c >= pad_col - padding[3])
                    output_ref[out_r * out_col + out_c ] += init_value;

                  else if ( 0 <= ir && ir < rows() && 0 <= ic  && ic < cols())
                  {
                    if ((r - padding[0]) % basedil[0] == 0 && (c - padding[2]) % basedil[1] == 0 )
                      output_ref[out_r * out_col + out_c ] += input[ ir * cols()  + ic];
                    else 
                      output_ref[out_r * out_col + out_c ] += init_value; //0;
                  }
                  break;
                }
                default:
                  break;
              }                   
            }
          }
        }
      }
      
      // Call optimized micro-kernel.
      reducewindow(rows(), cols(), input.data(), init_value, output.data(), &params);
      
      // Verify results.
      for (int32_t i = 0; i < out_row * out_col; i++) {
        EXPECT_EQ(output[i], output_ref[i])
          << "at " << i << " / " << out_row * out_col;
      }
    }
  }

 private:
  int32_t rows_{1};
  int32_t cols_{1};
  int32_t iterations_{1};  
};
