#!/bin/sh
# Copyright 2024 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
##################################### RPRECISION #####################################
tools/xngen.py src/f32-rprecision/f32-rprecision.c.in -D ARCH=scalar -D BATCH_TILES=1,2  -o src/f32-rprecision/gen/f32-rprecision-scalar.c &

wait