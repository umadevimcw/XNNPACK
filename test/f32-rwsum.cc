// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-rwsum.yaml
//   Generator: tools/generate-reducewindow-test.py


#include <gtest/gtest.h>
#include "xnnpack/common.h"
#include "xnnpack/isa-checks.h"
#include "xnnpack/microparams-init.h"
#include "xnnpack/reduce.h"
#include "reducewindow-microkernel-tester.h"


TEST(F32_RWSUM__SCALAR_U1, size_1_x_1) {
  ReduceWindowMicrokernelTester()
    .rows(1)
    .cols(1)
    .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
}

TEST(F32_RWSUM__SCALAR_U1, size_1_x_1024) {
  for (size_t col_size = 1; col_size < 1024 ; col_size++) {
    ReduceWindowMicrokernelTester()
      .rows(1)
      .cols(col_size)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}

TEST(F32_RWSUM__SCALAR_U1, size_1024_x_1) {
  for (size_t row_size = 1; row_size < 1024 ; row_size++) {
    ReduceWindowMicrokernelTester()
      .rows(row_size)
      .cols(1)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}

TEST(F32_RWSUM__SCALAR_U1, square_mat_size_1_x_512) {
  for (size_t size = 1; size < 512 ; size++) {
    ReduceWindowMicrokernelTester()
      .rows(size)
      .cols(size)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}
TEST(F32_RWSUM__SCALAR_U1, size_512_x_512) {
  for (size_t row_size = 1; row_size < 1024; row_size++) {
    for (size_t col_size = 1; col_size < 1024 ; col_size++) {
      ReduceWindowMicrokernelTester()
        .rows(row_size)
        .cols(col_size)
        .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
    }
  }
}