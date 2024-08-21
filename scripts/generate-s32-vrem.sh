#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VREM #####################################
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s32-vrem/gen/s32-vrem-scalar.c &
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=sse41 -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrem-sse41.c &
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrem-wasmsimd.c &
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrem-neon.c &
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/s32-vrem/gen/s32-vrem-avx2.c &
tools/xngen src/s32-vrem/s32-vrem.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/s32-vrem/gen/s32-vrem-avx512f.c &

##################################### SIMD VREMC #####################################
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s32-vrem/gen/s32-vremc-scalar.c &
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=sse41 -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vremc-sse41.c &
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vremc-wasmsimd.c &
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vremc-neon.c &
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/s32-vrem/gen/s32-vremc-avx2.c &
tools/xngen src/s32-vrem/s32-vremc.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/s32-vrem/gen/s32-vremc-avx512f.c &

##################################### SIMD VRREMC #####################################
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s32-vrem/gen/s32-vrremc-scalar.c &
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=sse41 -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrremc-sse41.c &
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrremc-wasmsimd.c &
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/s32-vrem/gen/s32-vrremc-neon.c &
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/s32-vrem/gen/s32-vrremc-avx2.c &
tools/xngen src/s32-vrem/s32-vrremc.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/s32-vrem/gen/s32-vrremc-avx512f.c &

wait
