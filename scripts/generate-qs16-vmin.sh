#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VMIN #####################################
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vmin/gen/qs16-vmin-minmax-scalar.c &
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vmin-minmax-sse41.c &
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vmin-minmax-wasmsimd.c &
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vmin-minmax-neon.c &
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vmin/gen/qs16-vmin-minmax-avx2.c &
tools/xngen src/qs16-vmin/qs16-vmin.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vmin/gen/qs16-vmin-minmax-avx512skx.c &

##################################### SIMD VMINC #####################################
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vmin/gen/qs16-vminc-minmax-scalar.c &
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vminc-minmax-sse41.c &
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vminc-minmax-wasmsimd.c &
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vmin/gen/qs16-vminc-minmax-neon.c &
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vmin/gen/qs16-vminc-minmax-avx2.c &
tools/xngen src/qs16-vmin/qs16-vminc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vmin/gen/qs16-vminc-minmax-avx512skx.c &

wait