// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-rprecision.yaml
//   Generator: tools/generate-reduce-test.py


#include <gtest/gtest.h>
#include "xnnpack/common.h"
#include "xnnpack/isa-checks.h"
#include "xnnpack/microparams-init.h"
#include "xnnpack/reduce.h"
#include "rprecision-microkernel-tester.h"


TEST(F32_RPRECISION__SCALAR_U1, batch_eq_1) {
  RPrecisionMicrokernelTester()
    .batch_size(1)
    .Test(xnn_f32_rprecision_ukernel__scalar_u1);
}

TEST(F32_RPRECISION__SCALAR_U1, batch_gt_1) {
  for (size_t batch_size = 2; batch_size < 10; batch_size++) {
    RPrecisionMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rprecision_ukernel__scalar_u1);
  }
}

TEST(F32_RPRECISION__SCALAR_U1, exponent_gt_1) {
  for (int exponent_bits = 2; exponent_bits < 8; exponent_bits++) {
    RPrecisionMicrokernelTester()
      .exponent_bits(exponent_bits)
      .Test(xnn_f32_rprecision_ukernel__scalar_u1);
  }
}

TEST(F32_RPRECISION__SCALAR_U1, mantissa_gt_1) {
  for (int mantissa_bits = 1; mantissa_bits < 23; mantissa_bits++) {
    RPrecisionMicrokernelTester()
      .mantissa_bits(mantissa_bits)
      .Test(xnn_f32_rprecision_ukernel__scalar_u1);
  }
}

TEST(F32_RPRECISION__SCALAR_U1, exponent_and_mantissa_gt_1) {
  for (int exponent_bits = 2; exponent_bits < 8; exponent_bits++) {
    for (int mantissa_bits = 1; mantissa_bits < 23; mantissa_bits++) {
      RPrecisionMicrokernelTester()
        .exponent_bits(exponent_bits)
        .mantissa_bits(mantissa_bits)
        .Test(xnn_f32_rprecision_ukernel__scalar_u1);
    }
  }
}

TEST(F32_RPRECISION__SCALAR_U1, batch_4_exponent_and_mantissa_gt_1) {
  for (int exponent_bits = 2; exponent_bits < 8; exponent_bits++) {
    for (int mantissa_bits = 1; mantissa_bits < 23; mantissa_bits++) {
      RPrecisionMicrokernelTester()
        .batch_size(4)
        .exponent_bits(exponent_bits)
        .mantissa_bits(exponent_bits)
        .Test(xnn_f32_rprecision_ukernel__scalar_u1);
    }
  }
}