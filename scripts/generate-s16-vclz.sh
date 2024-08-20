#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VCLZ #####################################
tools/xngen src/s16-vclz/s16-vclz.c.in -D ARCH=scalar -D BATCH_TILES=1,2,4,8  -o src/s16-vclz/gen/s16-vclz-scalar.c &
tools/xngen src/s16-vclz/s16-vclz.c.in -D ARCH=sse41 -D BATCH_TILES=8,16  -o src/s16-vclz/gen/s16-vclz-sse41.c &
tools/xngen src/s16-vclz/s16-vclz.c.in -D ARCH=neon -D BATCH_TILES=8,16  -o src/s16-vclz/gen/s16-vclz-neon.c &
tools/xngen src/s16-vclz/s16-vclz.c.in -D ARCH=avx2 -D BATCH_TILES=16,32  -o src/s16-vclz/gen/s16-vclz-avx2.c &
tools/xngen src/s16-vclz/s16-vclz.c.in -D ARCH=avx512bw -D BATCH_TILES=32,64  -o src/s16-vclz/gen/s16-vclz-avx512skx.c &

wait
