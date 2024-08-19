#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VREM #####################################
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vrem/gen/qs16-vrem-minmax-scalar.c &
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrem-minmax-sse41.c &
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrem-minmax-wasmsimd.c &
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrem-minmax-neon.c &
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vrem/gen/qs16-vrem-minmax-avx2.c &
tools/xngen src/qs16-vrem/qs16-vrem.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vrem/gen/qs16-vrem-minmax-avx512skx.c &

##################################### SIMD VREMC #####################################
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vrem/gen/qs16-vremc-minmax-scalar.c &
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vremc-minmax-sse41.c &
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vremc-minmax-wasmsimd.c &
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vremc-minmax-neon.c &
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vrem/gen/qs16-vremc-minmax-avx2.c &
tools/xngen src/qs16-vrem/qs16-vremc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vrem/gen/qs16-vremc-minmax-avx512skx.c &

##################################### SIMD VRREMC #####################################
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vrem/gen/qs16-vrremc-minmax-scalar.c &
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrremc-minmax-sse41.c &
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrremc-minmax-wasmsimd.c &
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vrem/gen/qs16-vrremc-minmax-neon.c &
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vrem/gen/qs16-vrremc-minmax-avx2.c &
tools/xngen src/qs16-vrem/qs16-vrremc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vrem/gen/qs16-vrremc-minmax-avx512skx.c &

wait