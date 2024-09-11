// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>

#include "bench/reducewindow-benchmark.h"
#include "bench/utils.h"
#include <benchmark/benchmark.h>

#include "xnnpack.h"
#include "xnnpack/aligned-allocator.h"
#include "xnnpack/common.h"
#include "xnnpack/reduce.h"
#include "xnnpack/microfnptr.h"

namespace {
void f32_rwsum(
  benchmark::State& state,
  xnn_f32_reducewindow_ukernel_fn rwsum,
  xnn_init_f32_reducewindow_params_fn init_params,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  if (isa_check != nullptr && !isa_check(state)) {
    return;
  }
  const int32_t rows = state.range(0);
  const int32_t cols = state.range(1);

  std::vector<float, AlignedAllocator<float, 64>> input(rows * cols + XNN_EXTRA_BYTES / sizeof(float));
  float init_value = 0.0;
  std::vector<int32_t> wnddim(2);
  std::vector<int32_t> wndstrd(2);
  std::vector<int32_t> basedil(2);
  std::vector<int32_t> wnddil(2);
  std::vector<int32_t> padding(4);
  std::vector<float> output;
  
  std::iota(input.begin(), input.end(), 0.0f);
  //std::iota(wnddim.begin(), wnddim.end(), 1);
  wnddim[0] = rows;
  wnddim[1] = cols;
  std::iota(wndstrd.begin(), wndstrd.end(), 1);
  std::iota(basedil.begin(), basedil.end(), 1);
  std::iota(wnddil.begin(), wnddil.end(), 1);
  std::iota(padding.begin(), padding.end(), 0);

  int32_t pad_row = rows + padding[0] + std::max((rows-1), 0) * (basedil[0]-1) + padding[1];
  int32_t pad_col = cols + padding[2] + std::max((cols-1), 0) * (basedil[1]-1) + padding[3];    
  int32_t out_row = (pad_row < (wnddim[0] - 1) * wnddil[0] + 1) ? 0 : floor((pad_row - (wnddim[0] - 1) * wnddil[0] - 1) / (float)wndstrd[0]) + 1;
  int32_t out_col = (pad_col < (wnddim[1] - 1) * wnddil[1] + 1) ? 0 : floor((pad_col - (wnddim[1] - 1) * wnddil[1] - 1) / (float)wndstrd[1]) + 1;
      
  if(out_row > 0 &&  out_col > 0)
    output.assign(out_row * out_col, init_value);
      
  // Prepare parameters.
  union xnn_f32_reducewindow_params params;
  init_params(&params, wnddim.data(), wndstrd.data(), basedil.data(), wnddil.data(), padding.data());

  for (auto _ : state) {
    rwsum(rows, cols, input.data(), init_value, output.data(), &params);
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }
}

static void BenchmarkRWSUM(benchmark::internal::Benchmark* b)
{
  b->ArgNames({"rows", "cols"});
  b->Args({8, 1024});
  b->Args({16, 1024});
  b->Args({10240, 1024});
}

}  // namespace
