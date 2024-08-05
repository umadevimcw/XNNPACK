#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VMAX #####################################
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vmax/gen/qs16-vmax-minmax-scalar.c &
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmax-minmax-sse41.c &
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmax-minmax-wasmsimd.c &
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmax-minmax-neon.c &
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vmax/gen/qs16-vmax-minmax-avx2.c &
tools/xngen src/qs16-vmax/qs16-vmax.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vmax/gen/qs16-vmax-minmax-avx512skx.c &

##################################### SIMD VMAXC #####################################
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-scalar.c &
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-sse41.c &
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-wasmsimd.c &
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-neon.c &
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-avx2.c &
tools/xngen src/qs16-vmax/qs16-vmaxc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/qs16-vmax/gen/qs16-vmaxc-minmax-avx512skx.c &

wait