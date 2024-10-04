// Copyright 2023 Google LLC
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
#include <numeric>
#include <random>
#include <vector>

#include <gtest/gtest.h>
#include "xnnpack.h"
#include "xnnpack/microfnptr.h"
#include "xnnpack/microparams.h"
#include "xnnpack/requantization.h"
#include "replicable_random_device.h"

class RPrecisionMicrokernelTester {
 public:
  RPrecisionMicrokernelTester& batch_size(size_t batch_size) {
    assert(batch_size != 0);
    this->batch_size_ = batch_size;
    return *this;
  }

  size_t batch_size() const {
    return this->batch_size_;
  }

  RPrecisionMicrokernelTester& iterations(size_t iterations) {
    this->iterations_ = iterations;
    return *this;
  }

  size_t iterations() const {
    return this->iterations_;
  }

  RPrecisionMicrokernelTester& exponent_bits(int32_t exponent_bits) {
    this->exponent_bits_ = exponent_bits;
    return *this;
  }

  int32_t exponent_bits() const {
    return this->exponent_bits_;
  }

  RPrecisionMicrokernelTester& mantissa_bits(int32_t mantissa_bits) {
    this->mantissa_bits_ = mantissa_bits;
    return *this;
  }

  int32_t mantissa_bits() const {
    return this->mantissa_bits_;
  }

  void Test(xnn_f32_rprecision_ukernel_fn rprecision) const {
    xnnpack::ReplicableRandomDevice rng;
    std::uniform_real_distribution<float> f32dist(1.175494351E-38, 3.402823466E+38);

    std::vector<float> input(batch_size() + XNN_EXTRA_BYTES / sizeof(float));
    std::vector<float> output(batch_size());
    std::vector<float> output_ref(batch_size());
    for (size_t iteration = 0; iteration < iterations(); iteration++) {
      std::generate(input.begin(), input.end(), [&]() { return f32dist(rng); });

      // Compute reference results.
      union mem
      {
        float f;
        int i;
      }Mi,Mo; 
      int MANTISSA_BITS = 23;
      int EXPONENT_BIAS = 127;
      const int32_t bias = (1U << (exponent_bits() - 1)) - 1;
      const int32_t exp_max = (1U << exponent_bits()) - 2 - bias;
      const int32_t exp_min = 1 - bias;

      for(int i=0; i < batch_size(); i++)
      {
        Mi.f = input[i];

        int32_t exp_size = (Mi.i >> MANTISSA_BITS) & 0x0FF;                        // actual exponent
        uint32_t mantissa = Mi.i & ((1U << MANTISSA_BITS) - 1);
        
        mantissa = mantissa >> (MANTISSA_BITS - mantissa_bits());
        if(exp_size != 0x0 && exp_size != 0x0FF)
        {
            exp_size -= EXPONENT_BIAS;                                                // exponent size
            if (Mi.i & (1U << (MANTISSA_BITS - mantissa_bits() -1)))                    // truncate and round  
            {
                mantissa += 1;
                if( mantissa >= (1U << mantissa_bits()))
                {
                    mantissa = mantissa & ((1U << mantissa_bits()) - 1);
                    exp_size += 1;
                }
            }
        }
        Mo.i = (Mi.i & 0x80000000) |  ( mantissa << (MANTISSA_BITS - mantissa_bits()));
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

        output_ref[i] = Mo.f;   
      }
      // Call optimized micro-kernel.
      rprecision(batch_size() * sizeof(float), input.data(), exponent_bits(), mantissa_bits(), output.data(), nullptr);

      // Verify results.
      for (size_t i = 0; i < batch_size(); i++) {
        if( !(isnanf(output[i]) && isnanf(output_ref[i])) )
        {
          //printf("Prasad i = %d, input = %f, output_ref = %f, output = %f\n", i, input[i], output_ref[i], output[i]);
          EXPECT_FLOAT_EQ(output[i], output_ref[i])
            << "at " << i << " / " << batch_size();
        }
      }
    }
  }

 private:
  size_t batch_size_{1};
  size_t iterations_{5};
  int32_t exponent_bits_{1};
  int32_t mantissa_bits_{0};
};
