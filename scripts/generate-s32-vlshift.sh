#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VLSHIFT #####################################
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s32-vlshift/gen/s32-vlshift-scalar.c &
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=sse41 -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshift-sse41.c &
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshift-wasmsimd.c &
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshift-neon.c &
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/s32-vlshift/gen/s32-vlshift-avx2.c &
tools/xngen src/s32-vlshift/s32-vlshift.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/s32-vlshift/gen/s32-vlshift-avx512f.c &

##################################### SIMD VLSHIFTC #####################################
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s32-vlshift/gen/s32-vlshiftc-scalar.c &
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=sse41 -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshiftc-sse41.c &
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=wasmsimd -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshiftc-wasmsimd.c &
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=neon -D BATCH_TILES=4,8,12,16  -o src/s32-vlshift/gen/s32-vlshiftc-neon.c &
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=avx2 -D BATCH_TILES=8,16,24,32  -o src/s32-vlshift/gen/s32-vlshiftc-avx2.c &
tools/xngen src/s32-vlshift/s32-vlshiftc.c.in -D ARCH=avx512f -D BATCH_TILES=16,32,48,64  -o src/s32-vlshift/gen/s32-vlshiftc-avx512f.c &

wait
