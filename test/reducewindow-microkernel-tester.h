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

  ReduceWindowMicrokernelTester& rows(size_t rows) {
    assert(rows != 0);
    this->rows_ = rows;
    return *this;
  }

  size_t rows() const {
    return this->rows_;
  }

  ReduceWindowMicrokernelTester& cols(size_t cols) {
    assert(cols != 0);
    this->cols_ = cols;
    return *this;
  }

  size_t cols() const {
      return this->cols_;
    }
  }

  ReduceWindowMicrokernelTester& iterations(size_t iterations) {
    this->iterations_ = iterations;
    return *this;
  }

  size_t iterations() const {
    return this->iterations_;
  }


  void Test(xnn_f32_reducewindow_ukernel_fn reducewindow, pType op_type, xnn_init_f32_reducewindow_params_fn init_params) const {
    xnnpack::ReplicableRandomDevice rng;
    std::uniform_real_distribution<float> f32dist;
    std::uniform_real_distribution<long> dist;

    std::vector<float> input(rows() * cols() + XNN_EXTRA_BYTES / sizeof(float));
    float init_value = 0.0;

    std::vector<size_t> wnddim(2);
    std::vector<size_t> wndstrd(2);
    std::vector<size_t> basedil(2);
    std::vector<size_t> wnddil(2);
    std::vector<long> padding(4);

    size_t pad_row = rows() + padding[0] + max((rows()-1), 0) * (base_dilations[0]-1) + padding[1];
    size_t pad_col = cols() + padding[2] + max((cols()-1), 0) * (base_dilations[1]-1) + padding[3];    
    size_t out_row = (pad_row - (window_dimensions[0] - 1) * window_dilations[0] - 1) / window_strides[0] + 1;
    size_t out_col = (pad_col - (window_dimensions[1] - 1) * window_dilations[1] - 1) / window_strides[1] + 1;

    std::vector<float> output(out_row * out_col);
    std::vector<float> output_ref(out_row * out_col);

    for (size_t iteration = 0; iteration < iterations(); iteration++) {
      std::generate(input.begin(), input.end(), [&]() { return f32dist(rng); });
      std::generate(output.begin(), output.end(), [&]() { return f32dist(rng); });
      output_ref = output;

      std::generate(wnddim.begin(), wnddim.end(), [&]() { return dist(rng); });
      std::generate(wndstrd.begin(), wndstrd.end(), [&]() { return dist(rng); });
      std::generate(basedil.begin(), basedil.end(), [&]() { return dist(rng); });
      std::generate(wnddil.begin(), wnddil.end(), [&]() { return dist(rng); });
      std::generate(padding.begin(), padding.end(), [&]() { return dist(rng); });

      // Prepare parameters.
      union xnn_f32_reducewindow_params params;
      if (init_params != nullptr) {
      init_params(&params, wnddim.data(), wndstrd.data(), basedil.data(), wnddil.data(), padding.data());
      }

      // Compute reference results.
      size_t win_row = ceil(((wnddim[0] - 1) * wnddil[0] + 1) / (float)wnddil[0]);
      size_t win_col = ceil(((wnddim[1] - 1) * wnddil[1] + 1) / (float)wnddil[1]);
      for (size_t out_r = 0; out_r < out_row ; out_r++){
        for(size_t out_c = 0; out_c < out_col; out_c++){
            
            output[out_r * out_col + out_c ] = init_value;  // 0;
            for(size_t i =0; i<win_row; i++)
            {
                for(size_t j=0; j<win_col; j++)
                {
                    size_t r = out_r * wndstrd[0] + i * wnddil[0];
                    size_t c = out_c * wndstrd[1] + j * wnddil[1];

                    size_t ir = (r - padding[0]) / basedil[0];
                    size_t ic = (c - padding[2]) / basedil[1];
                    
                    // reduction    
                    switch (op_type) {
                      case OpType::Sum:
                          if( r < padding[0] || r >= pad_row - padding[1] || c < padding[2] || c >= pad_col - padding[3])
                            output[out_r * out_col + out_c ] += init_value;

                          else if ( 0 <= ir && ir < rows() && 0 <= ic  && ic < cols())
                          {
                            if ((r - padding[0]) % basedil[0] == 0 &&(c - padding[2]) % basedil[1] == 0 )
                              output[out_r * out_col + out_c ] += input[ ir * cols()  + ic];
                            else 
                              output[out_r * out_col + out_c ] += init_value; //0;
                          }
                          break;
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
      for (size_t c = 0; c < channels(); c++) {
        EXPECT_NEAR(output[c], output_ref[c], std::abs(output_ref[c]) * 1.0e-6f)
          << "at position " << c << ", rows = " << rows() << ", channels = " << channels();
      }
    }
  }


 private:
  size_t rows_{1};
  size_t cols_{1};
  size_t iterations_{3};

  uint32_t wnddim_[2]{1, 1};
  uint32_t wndstrd_[2]{1, 1}; 
  uint32_t basedil_[2]{1, 1};
  uint32_t wnddil_[2]{1, 1};
  int32_t padding_[4]{0, 0, 0, 0};
  
};
