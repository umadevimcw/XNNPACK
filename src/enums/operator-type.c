// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: src/enums/operator-type.yaml
//   Generator: tools/generate-enum.py

#include <assert.h>
#include <stdint.h>

#include "xnnpack/operator-type.h"

static const uint16_t offset[170] = {
  0, 8, 22, 36, 50, 64, 78, 92, 119, 147, 175, 203, 230, 257, 289, 321, 364, 382, 400, 425, 451, 467, 483, 498, 513,
  543, 565, 588, 611, 634, 657, 680, 703, 726, 749, 772, 790, 813, 836, 860, 878, 901, 925, 949, 973, 997, 1032, 1067,
  1091, 1115, 1139, 1153, 1168, 1183, 1203, 1229, 1255, 1292, 1318, 1348, 1374, 1406, 1438, 1464, 1491, 1518, 1535,
  1552, 1586, 1620, 1634, 1648, 1662, 1676, 1692, 1708, 1734, 1760, 1792, 1824, 1861, 1898, 1935, 1972, 2009, 2046,
  2083, 2109, 2141, 2167, 2182, 2216, 2250, 2284, 2318, 2352, 2386, 2416, 2446, 2466, 2486, 2507, 2528, 2549, 2570,
  2584, 2608, 2632, 2655, 2678, 2696, 2714, 2729, 2744, 2762, 2780, 2799, 2818, 2837, 2856, 2875, 2892, 2909, 2925,
  2941, 2974, 3007, 3035, 3063, 3091, 3119, 3146, 3173, 3190, 3207, 3248, 3289, 3307, 3325, 3343, 3361, 3376, 3392,
  3408, 3426, 3444, 3462, 3488, 3515, 3542, 3559, 3576, 3598, 3620, 3649, 3678, 3697, 3716, 3735, 3754, 3769, 3784,
  3799, 3814, 3833, 3853, 3873, 3893, 3914, 3935
};

static const char data[] =
  "Invalid\0"
  "Abs (NC, F16)\0"
  "Abs (NC, F32)\0"
  "Add (ND, F16)\0"
  "Add (ND, F32)\0"
  "Add (ND, QS8)\0"
  "Add (ND, QU8)\0"
  "ArgMax Pooling (NHWC, F32)\0"
  "Average Pooling (NHWC, F16)\0"
  "Average Pooling (NHWC, F32)\0"
  "Average Pooling (NHWC, QU8)\0"
  "Bankers Rounding (NC, F16)\0"
  "Bankers Rounding (NC, F32)\0"
  "Batch Matrix Multiply (NC, F16)\0"
  "Batch Matrix Multiply (NC, F32)\0"
  "Batch Matrix Multiply (NC, QD8, F32, QC8W)\0"
  "Ceiling (NC, F16)\0"
  "Ceiling (NC, F32)\0"
  "Channel Shuffle (NC, X8)\0"
  "Channel Shuffle (NC, X32)\0"
  "Clamp (NC, F16)\0"
  "Clamp (NC, F32)\0"
  "Clamp (NC, S8)\0"
  "Clamp (NC, U8)\0"
  "Count Leading Zeros (NC, S32)\0"
  "Constant Pad (ND, X8)\0"
  "Constant Pad (ND, X16)\0"
  "Constant Pad (ND, X32)\0"
  "Convert (NC, F16, F32)\0"
  "Convert (NC, F16, QD8)\0"
  "Convert (NC, F32, F16)\0"
  "Convert (NC, F32, QD8)\0"
  "Convert (NC, F32, QP8)\0"
  "Convert (NC, F32, QS8)\0"
  "Convert (NC, F32, QU8)\0"
  "Convert (NC, QS8)\0"
  "Convert (NC, QS8, F16)\0"
  "Convert (NC, QS8, F32)\0"
  "Convert (NC, QS16, QS8)\0"
  "Convert (NC, QU8)\0"
  "Convert (NC, QU8, F32)\0"
  "Convolution (NCHW, F16)\0"
  "Convolution (NCHW, F32)\0"
  "Convolution (NHWC, F16)\0"
  "Convolution (NHWC, F32)\0"
  "Convolution (NHWC, QD8, F16, QC8W)\0"
  "Convolution (NHWC, QD8, F32, QC8W)\0"
  "Convolution (NHWC, QC8)\0"
  "Convolution (NHWC, QS8)\0"
  "Convolution (NHWC, QU8)\0"
  "Copy (NC, X8)\0"
  "Copy (NC, X16)\0"
  "Copy (NC, X32)\0"
  "Copy Sign (NC, F32)\0"
  "Deconvolution (NHWC, F16)\0"
  "Deconvolution (NHWC, F32)\0"
  "Deconvolution (NHWC, QD8, F32, QC8W)\0"
  "Deconvolution (NHWC, QS8)\0"
  "Deconvolution (NC, QS8, QC8W)\0"
  "Deconvolution (NHWC, QU8)\0"
  "Depth To Space (NCHW2NHWC, X16)\0"
  "Depth To Space (NCHW2NHWC, X32)\0"
  "Depth To Space (NHWC, X8)\0"
  "Depth To Space (NHWC, X16)\0"
  "Depth To Space (NHWC, X32)\0"
  "Divide (ND, F16)\0"
  "Divide (ND, F32)\0"
  "Dynamic Fully Connected (NC, F16)\0"
  "Dynamic Fully Connected (NC, F32)\0"
  "ELU (NC, F16)\0"
  "ELU (NC, F32)\0"
  "ELU (NC, QS8)\0"
  "Exp (NC, F32)\0"
  "Floor (NC, F16)\0"
  "Floor (NC, F32)\0"
  "Fully Connected (NC, F16)\0"
  "Fully Connected (NC, F32)\0"
  "Fully Connected (NC, F32, QC4W)\0"
  "Fully Connected (NC, F32, QC8W)\0"
  "Fully Connected (NC, QD8, F16, QB4W)\0"
  "Fully Connected (NC, QD8, F16, QC4W)\0"
  "Fully Connected (NC, QD8, F16, QC8W)\0"
  "Fully Connected (NC, QD8, F32, QB4W)\0"
  "Fully Connected (NC, QD8, F32, QC4W)\0"
  "Fully Connected (NC, QD8, F32, QC8W)\0"
  "Fully Connected (NC, QP8, F32, QC4W)\0"
  "Fully Connected (NC, QS8)\0"
  "Fully Connected (NC, QS8, QC8W)\0"
  "Fully Connected (NC, QU8)\0"
  "GELU (NC, F32)\0"
  "Global Average Pooling (NCW, F16)\0"
  "Global Average Pooling (NCW, F32)\0"
  "Global Average Pooling (NWC, F16)\0"
  "Global Average Pooling (NWC, F32)\0"
  "Global Average Pooling (NWC, QS8)\0"
  "Global Average Pooling (NWC, QU8)\0"
  "Global Sum Pooling (NWC, F16)\0"
  "Global Sum Pooling (NWC, F32)\0"
  "HardSwish (NC, F16)\0"
  "HardSwish (NC, F32)\0"
  "Leaky ReLU (NC, F16)\0"
  "Leaky ReLU (NC, F32)\0"
  "Leaky ReLU (NC, QS8)\0"
  "Leaky ReLU (NC, QU8)\0"
  "Log (NC, F32)\0"
  "Max Pooling (NHWC, F16)\0"
  "Max Pooling (NHWC, F32)\0"
  "Max Pooling (NHWC, S8)\0"
  "Max Pooling (NHWC, U8)\0"
  "Maximum (ND, F16)\0"
  "Maximum (ND, F32)\0"
  "Mean (ND, F16)\0"
  "Mean (ND, F32)\0"
  "Minimum (ND, F16)\0"
  "Minimum (ND, F32)\0"
  "Multiply (ND, F16)\0"
  "Multiply (ND, F32)\0"
  "Multiply (ND, QS8)\0"
  "Multiply (ND, QU8)\0"
  "Multiply (ND, S32)\0"
  "Negate (NC, F16)\0"
  "Negate (NC, F32)\0"
  "PReLU (NC, F16)\0"
  "PReLU (NC, F32)\0"
  "Reciprocal Square Root (NC, F16)\0"
  "Reciprocal Square Root (NC, F32)\0"
  "Resize Bilinear (NCHW, F16)\0"
  "Resize Bilinear (NCHW, F32)\0"
  "Resize Bilinear (NHWC, F16)\0"
  "Resize Bilinear (NHWC, F32)\0"
  "Resize Bilinear (NHWC, S8)\0"
  "Resize Bilinear (NHWC, U8)\0"
  "RoPE (NTHC, F16)\0"
  "RoPE (NTHC, F32)\0"
  "Scaled Dot-Product Attention (NHTC, F16)\0"
  "Scaled Dot-Product Attention (NHTC, F32)\0"
  "Sigmoid (NC, F16)\0"
  "Sigmoid (NC, F32)\0"
  "Sigmoid (NC, QS8)\0"
  "Sigmoid (NC, QU8)\0"
  "Slice (ND, X8)\0"
  "Slice (ND, X16)\0"
  "Slice (ND, X32)\0"
  "Softmax (NC, F16)\0"
  "Softmax (NC, F32)\0"
  "Softmax (NC, QU8)\0"
  "Space To Depth (NHWC, X8)\0"
  "Space To Depth (NHWC, X16)\0"
  "Space To Depth (NHWC, X32)\0"
  "Square (NC, F16)\0"
  "Square (NC, F32)\0"
  "Square Root (NC, F16)\0"
  "Square Root (NC, F32)\0"
  "Squared Difference (NC, F16)\0"
  "Squared Difference (NC, F32)\0"
  "Subtract (ND, F16)\0"
  "Subtract (ND, F32)\0"
  "Subtract (ND, QS8)\0"
  "Subtract (ND, QU8)\0"
  "Tanh (NC, F16)\0"
  "Tanh (NC, F32)\0"
  "Tanh (NC, QS8)\0"
  "Tanh (NC, QU8)\0"
  "Transpose (ND, X8)\0"
  "Transpose (ND, X16)\0"
  "Transpose (ND, X32)\0"
  "Transpose (ND, X64)\0"
  "Truncation (NC, F16)\0"
  "Truncation (NC, F32)\0"
  "Unpooling (NHWC, X32)";

const char* xnn_operator_type_to_string(enum xnn_operator_type operator_type) {
  assert(operator_type >= xnn_operator_type_invalid);
  assert(operator_type <= xnn_operator_type_unpooling_nhwc_x32);
  return &data[offset[operator_type]];
}
