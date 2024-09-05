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


TEST(F32_RWSUM__SCALAR_U1, rows_eq_1_cols_eq_1) {
  ReduceWindowMicrokernelTester()
    .rows(1)
    .cols(1)
    .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
}

TEST(F32_RWSUM__SCALAR_U1, rows_eq_1_cols_eq_n) {
  for (size_t col_size = 1; col_size < INT32_MAX ; col_size++) {
    ReduceWindowMicrokernelTester()
      .rows(1)
      .cols(col_size)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}

TEST(F32_RWSUM__SCALAR_U1, rows_eq_n_cols_eq_1) {
  for (size_t row_size = 1; row_size < INT32_MAX ; row_size++) {
    ReduceWindowMicrokernelTester()
      .rows(row_size)
      .cols(1)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}

TEST(F32_RWSUM__SCALAR_U1, rows_eq_cols) {
  for (size_t size = 1; size < INT16_MAX ; size++) {
    ReduceWindowMicrokernelTester()
      .rows(size)
      .cols(size)
      .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
  }
}
TEST(F32_RWSUM__SCALAR_U1, rows_cols_from_1_to_n) {
  for (size_t row_size = 1; row_size < INT16_MAX ; row_size++) {
    for (size_t col_size = 1; col_size < INT16_MAX ; col_size++) {
      ReduceWindowMicrokernelTester()
        .rows(row_size)
        .cols(col_size)
        .Test(xnn_f32_rwsum_ukernel__scalar_u1, ReduceWindowMicrokernelTester::OpType::Sum, xnn_init_f32_reducewindow_params);
    }
  }
}