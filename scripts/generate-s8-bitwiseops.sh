#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

##################################### SIMD VAND #####################################
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=scalar -D OP=AND -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vand-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=sse41  -D OP=AND -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vand-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=wasmsimd -D OP=AND  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vand-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=neon  -D OP=AND  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vand-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx2  -D OP=AND  -D BATCH_TILES=32,64  -o src/s8-vbitwise/gen/s8-vand-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx512bw  -D OP=AND -D BATCH_TILES=64,128 -o src/s8-vbitwise/gen/s8-vand-avx512skx.c &

##################################### SIMD VANDC #####################################
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=scalar -D OP=AND -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vandc-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=sse41 -D OP=AND -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vandc-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=wasmsimd  -D OP=AND -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vandc-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=neon -D OP=AND  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vandc-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx2  -D OP=AND -D BATCH_TILES=32,64  -o src/s8-vbitwise/gen/s8-vandc-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx512bw  -D OP=AND -D BATCH_TILES=64,128  -o src/s8-vbitwise/gen/s8-vandc-avx512skx.c &

##################################### SIMD VOR #####################################
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=scalar -D OP=OR -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vor-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=sse41  -D OP=OR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vor-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=wasmsimd -D OP=OR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vor-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=neon  -D OP=OR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vor-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx2  -D OP=OR  -D BATCH_TILES=32,64  -o src/s8-vbitwise/gen/s8-vor-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx512bw  -D OP=OR -D BATCH_TILES=64,128  -o src/s8-vbitwise/gen/s8-vor-avx512skx.c &

##################################### SIMD VORC #####################################
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=scalar -D OP=OR -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vorc-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=sse41 -D OP=OR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vorc-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=wasmsimd  -D OP=OR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vorc-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=neon -D OP=OR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vorc-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx2  -D OP=OR -D BATCH_TILES=32,64  -o src/s8-vbitwise/gen/s8-vorc-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx512bw  -D OP=OR -D BATCH_TILES=64,128  -o src/s8-vbitwise/gen/s8-vorc-avx512skx.c &

##################################### SIMD VXOR #####################################
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=scalar -D OP=XOR -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vxor-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=sse41  -D OP=XOR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxor-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=wasmsimd -D OP=XOR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxor-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=neon  -D OP=XOR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxor-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx2  -D OP=XOR  -D BATCH_TILES=32,64 -o src/s8-vbitwise/gen/s8-vxor-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwise.c.in -D ARCH=avx512bw  -D OP=XOR -D BATCH_TILES=64,128  -o src/s8-vbitwise/gen/s8-vxor-avx512skx.c &

##################################### SIMD VXORC #####################################
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=scalar -D OP=XOR -D BATCH_TILES=1,2,4,8  -o src/s8-vbitwise/gen/s8-vxorc-scalar.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=sse41 -D OP=XOR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxorc-sse41.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=wasmsimd  -D OP=XOR -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxorc-wasmsimd.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=neon -D OP=XOR  -D BATCH_TILES=16,32  -o src/s8-vbitwise/gen/s8-vxorc-neon.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx2  -D OP=XOR -D BATCH_TILES=32,64  -o src/s8-vbitwise/gen/s8-vxorc-avx2.c &
tools/xngen src/s8-vbitwise/s8-vbitwisec.c.in -D ARCH=avx512bw  -D OP=XOR -D BATCH_TILES=64,128  -o src/s8-vbitwise/gen/s8-vxorc-avx512skx.c &

wait