#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VROUNDNEARESTAFZ #####################################
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-scalar.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=sse2 -D BATCH_TILES=4,8,12,16  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-sse2.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-wasmsimd.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-neon.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=avx -D BATCH_TILES=8,16,24,32  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-avx.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-avx2.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-avx512f.c &
tools/xngen src/f32-vrndnrtafz/f32-vrndnrtafz.c.in -D ARCH=hvx -D BATCH_TILES=32,64  -o src/f32-vrndnrtafz/gen/f32-vrndnrtafz-hvx.c &


wait