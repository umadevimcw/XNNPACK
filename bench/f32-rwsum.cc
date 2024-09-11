// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-rwsum.yaml
//   Generator: tools/generate-reducewindow-benchmark.py

#include "bench/reducewindow-benchmark.h"
#include "bench/rsum-benchmark.h"
#include "bench/utils.h"
#include <benchmark/benchmark.h>

#include "xnnpack.h"
#include "xnnpack/aligned-allocator.h"
#include "xnnpack/common.h"
#include "xnnpack/reduce.h"
#include "xnnpack/microfnptr.h"
#include "xnnpack/microparams-init.h"


BENCHMARK_CAPTURE(f32_rwsum, scalar_u1,
                  xnn_f32_rwsum_ukernel__scalar_u1,
                  xnn_init_f32_reducewindow_params)
  ->Apply(BenchmarkRWSUM)
  ->UseRealTime();

BENCHMARK_CAPTURE(f32_rdsum, scalar_c4,
                  xnn_f32_rdsum_ukernel_7p7x__scalar_c4,
                  xnn_init_f32_scaleminmax_scalar_params)
  ->Apply(BenchmarkRDSUM)
  ->UseRealTime();

#ifndef XNNPACK_BENCHMARK_NO_MAIN
BENCHMARK_MAIN();
#endif
