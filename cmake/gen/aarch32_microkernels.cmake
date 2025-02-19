# Copyright 2022 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#
# Description: microkernel filename lists for aarch32
#
# Auto-generated file. Do not edit!
#   Generator: tools/update-microkernels.py


SET(PROD_AARCH32_ASM_MICROKERNEL_SRCS
  src/f32-gemm/gen/f32-gemm-1x8-minmax-asm-aarch32-neon-cortex-a53-prfm.S
  src/f32-gemm/gen/f32-gemm-1x8-minmax-asm-aarch32-neon-cortex-a53.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a7.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a53-prfm.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a53.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a55.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a75-prfm.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-cortex-a75.S
  src/f32-igemm/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a55.S
  src/f32-igemm/gen/f32-igemm-1x8-minmax-asm-aarch32-neon-cortex-a53-prfm.S
  src/f32-igemm/gen/f32-igemm-1x8-minmax-asm-aarch32-neon-cortex-a53.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a7.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a53-prfm.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a53.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a75-prfm.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-cortex-a75.S
  src/qd8-f16-qc8w-gemm/gen/qd8-f16-qc8w-gemm-4x8c4-minmax-asm-aarch32-neondotfp16arith-cortex-a55.S
  src/qd8-f16-qc8w-igemm/gen/qd8-f16-qc8w-igemm-4x8c4-minmax-asm-aarch32-neondotfp16arith-cortex-a55.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f32-qc8w-gemm-4x8-minmax-asm-aarch32-neonmlal-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f32-qc8w-gemm-4x8c4-minmax-asm-aarch32-neondot-cortex-a55.S
  src/qd8-f32-qc8w-igemm/gen/qd8-f32-qc8w-igemm-4x8c4-minmax-asm-aarch32-neondot-cortex-a55.S
  src/qs8-qc8w-dwconv/qs8-qc8w-dwconv-3p16c-minmax-fp32-asm-aarch32-neonv8-mla8-cortex-a35.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-1x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-1x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-1x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-1x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-ld64.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a53-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a53.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-ld64-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-ld64.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8c4-minmax-fp32-asm-aarch32-neondot-cortex-a55.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8c4-minmax-fp32-asm-aarch32-neondot-ld64.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-1x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-1x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-1x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-1x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-ld64.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a53-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a53.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-ld64-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-ld64.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8c4-minmax-fp32-asm-aarch32-neondot-cortex-a55.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8c4-minmax-fp32-asm-aarch32-neondot-ld64.S
  src/qu8-gemm/gen/qu8-gemm-1x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qu8-gemm/gen/qu8-gemm-1x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a53-prfm.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a53.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-ld64-prfm.S
  src/qu8-gemm/gen/qu8-gemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-ld64.S
  src/qu8-igemm/gen/qu8-igemm-1x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qu8-igemm/gen/qu8-igemm-1x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7-prfm.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a53-prfm.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-cortex-a53.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-ld64-prfm.S
  src/qu8-igemm/gen/qu8-igemm-4x8-minmax-rndnu-asm-aarch32-neon-mlal-lane-ld64.S)

SET(NON_PROD_AARCH32_ASM_MICROKERNEL_SRCS
  src/f32-gemm/gen/f32-gemm-4x4-asm-aarch32-vfp-ld64.S
  src/f32-gemm/gen/f32-gemm-4x4-minmax-asm-aarch32-vfp-ld64.S
  src/f32-gemm/gen/f32-gemm-4x8-minmax-asm-aarch32-neon-ld64.S
  src/f32-igemm/gen/f32-igemm-4x8-minmax-asm-aarch32-neon-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f16-qc8w-gemm-1x8-minmax-asm-aarch32-neonfp16arith-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f16-qc8w-gemm-2x8-minmax-asm-aarch32-neonfp16arith-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f16-qc8w-gemm-3x8-minmax-asm-aarch32-neonfp16arith-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f16-qc8w-gemm-4x8-minmax-asm-aarch32-neonfp16arith-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f32-qc8w-gemm-1x8-minmax-asm-aarch32-neonmlal-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f32-qc8w-gemm-2x8-minmax-asm-aarch32-neonmlal-ld64.S
  src/qd8-f32-qc8w-gemm/gen/qd8-f32-qc8w-gemm-3x8-minmax-asm-aarch32-neonmlal-ld64.S
  src/qs8-qc8w-dwconv/qs8-qc8w-dwconv-3p8c-minmax-fp32-asm-aarch32-neonv8-mla8-cortex-a35.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a53-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a53.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-ld64-prfm.S
  src/qs8-qc8w-gemm/gen/qs8-qc8w-gemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a7.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a53-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-cortex-a53.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neon-mlal-lane-ld64-prfm.S
  src/qs8-qc8w-igemm/gen/qs8-qc8w-igemm-4x8-minmax-fp32-asm-aarch32-neonv8-mlal-lane-cortex-a35-prfm.S)

SET(ALL_AARCH32_ASM_MICROKERNEL_SRCS ${PROD_AARCH32_ASM_MICROKERNEL_SRCS} + ${NON_PROD_AARCH32_ASM_MICROKERNEL_SRCS})
