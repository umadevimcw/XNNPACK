#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VLSHIFT #####################################
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s16-vlshift/gen/s16-vlshift-scalar.c &
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshift-sse41.c &
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshift-wasmsimd.c &
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshift-neon.c &
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/s16-vlshift/gen/s16-vlshift-avx2.c &
tools/xngen src/s16-vlshift/s16-vlshift.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/s16-vlshift/gen/s16-vlshift-avx512skx.c &

##################################### SIMD VLSHIFTC #####################################
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s16-vlshift/gen/s16-vlshiftc-scalar.c &
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshiftc-sse41.c &
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshiftc-wasmsimd.c &
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vlshiftc-neon.c &
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/s16-vlshift/gen/s16-vlshiftc-avx2.c &
tools/xngen src/s16-vlshift/s16-vlshiftc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/s16-vlshift/gen/s16-vlshiftc-avx512skx.c &

##################################### SIMD VRLSHIFTC #####################################
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s16-vlshift/gen/s16-vrlshiftc-scalar.c &
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vrlshiftc-sse41.c &
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=wasmsimd -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vrlshiftc-wasmsimd.c &
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/s16-vlshift/gen/s16-vrlshiftc-neon.c &
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/s16-vlshift/gen/s16-vrlshiftc-avx2.c &
tools/xngen src/s16-vlshift/s16-vrlshiftc.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/s16-vlshift/gen/s16-vrlshiftc-avx512skx.c &

wait
