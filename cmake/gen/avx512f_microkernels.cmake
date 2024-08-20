# Copyright 2022 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#
# Description: microkernel filename lists for avx512f
#
# Auto-generated file. Do not edit!
#   Generator: tools/update-microkernels.py


SET(ALL_AVX512F_MICROKERNEL_SRCS
  src/f32-dwconv/gen/f32-dwconv-3p16c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-3p16c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-3p32c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-3p32c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-4p16c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-4p16c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-4p32c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-4p32c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-5f5m5l16c16s1r-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-5f5m5l16c16s1r-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-5f5m5l32c16s1r-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-5f5m5l32c16s1r-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-9p16c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-9p16c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-9p32c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-9p32c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-25p16c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-25p16c-minmax-avx512f.c
  src/f32-dwconv/gen/f32-dwconv-25p32c-minmax-avx512f-acc2.c
  src/f32-dwconv/gen/f32-dwconv-25p32c-minmax-avx512f.c
  src/f32-gemm/gen/f32-gemm-1x16-minmax-avx512f-broadcast.c
  src/f32-gemm/gen/f32-gemm-4x16-minmax-avx512f-broadcast.c
  src/f32-gemm/gen/f32-gemm-5x16-minmax-avx512f-broadcast.c
  src/f32-gemm/gen/f32-gemm-6x16-minmax-avx512f-broadcast.c
  src/f32-gemm/gen/f32-gemm-7x16-minmax-avx512f-broadcast.c
  src/f32-gemm/gen/f32-gemm-8x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-1x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-4x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-5x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-6x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-7x16-minmax-avx512f-broadcast.c
  src/f32-gemminc/gen/f32-gemminc-8x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-1x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-4x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-5x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-6x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-7x16-minmax-avx512f-broadcast.c
  src/f32-igemm/gen/f32-igemm-8x16-minmax-avx512f-broadcast.c
  src/f32-prelu/gen/f32-prelu-avx512f-2x16.c
  src/f32-prelu/gen/f32-prelu-avx512f-2x32.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u64-acc2.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u64-acc4.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u64.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u128-acc2.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u128-acc4.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u128.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u144-acc3.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u144.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u160-acc2.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u160-acc5.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u160.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u192-acc2.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u192-acc3.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u192-acc6.c
  src/f32-raddexpminusmax/gen/f32-raddexpminusmax-avx512f-p5-scalef-u192.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u64-acc2.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u64-acc4.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u64.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u128-acc2.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u128-acc4.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u128.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u144-acc3.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u144.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u160-acc2.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u160-acc5.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u160.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u192-acc2.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u192-acc3.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u192-acc6.c
  src/f32-raddextexp/gen/f32-raddextexp-avx512f-p5-scalef-u192.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u64-acc2.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u64-acc4.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u64.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u128-acc2.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u128-acc4.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u128.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u144-acc3.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u144.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u160-acc2.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u160-acc5.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u160.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u192-acc2.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u192-acc3.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u192-acc6.c
  src/f32-raddstoreexpminusmax/gen/f32-raddstoreexpminusmax-avx512f-rr1-p5-scalef-u192.c
  src/f32-rdsum/gen/f32-rdsum-7p7x-minmax-avx512f-c16.c
  src/f32-rdsum/gen/f32-rdsum-7p7x-minmax-avx512f-c32.c
  src/f32-rdsum/gen/f32-rdsum-7p7x-minmax-avx512f-c64.c
  src/f32-rdsum/gen/f32-rdsum-7p7x-minmax-avx512f-c128.c
  src/f32-rminmax/gen/f32-rmax-avx512f-u16.c
  src/f32-rminmax/gen/f32-rmax-avx512f-u32-acc2.c
  src/f32-rminmax/gen/f32-rmax-avx512f-u48-acc3.c
  src/f32-rminmax/gen/f32-rmax-avx512f-u64-acc2.c
  src/f32-rminmax/gen/f32-rmax-avx512f-u64-acc4.c
  src/f32-rminmax/gen/f32-rmin-avx512f-u16.c
  src/f32-rminmax/gen/f32-rmin-avx512f-u32-acc2.c
  src/f32-rminmax/gen/f32-rmin-avx512f-u48-acc3.c
  src/f32-rminmax/gen/f32-rmin-avx512f-u64-acc2.c
  src/f32-rminmax/gen/f32-rmin-avx512f-u64-acc4.c
  src/f32-rminmax/gen/f32-rminmax-avx512f-u16.c
  src/f32-rminmax/gen/f32-rminmax-avx512f-u32-acc2.c
  src/f32-rminmax/gen/f32-rminmax-avx512f-u48-acc3.c
  src/f32-rminmax/gen/f32-rminmax-avx512f-u64-acc2.c
  src/f32-rminmax/gen/f32-rminmax-avx512f-u64-acc4.c
  src/f32-rsum/gen/f32-rsum-avx512f-u16.c
  src/f32-rsum/gen/f32-rsum-avx512f-u32-acc2.c
  src/f32-rsum/gen/f32-rsum-avx512f-u48-acc3.c
  src/f32-rsum/gen/f32-rsum-avx512f-u64-acc2.c
  src/f32-rsum/gen/f32-rsum-avx512f-u64-acc4.c
  src/f32-vbinary/gen/f32-vadd-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vadd-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vaddc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vaddc-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vdiv-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vdiv-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vdivc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vdivc-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vmaxc-avx512f-u16.c
  src/f32-vbinary/gen/f32-vmaxc-avx512f-u32.c
  src/f32-vbinary/gen/f32-vmin-avx512f-u16.c
  src/f32-vbinary/gen/f32-vmin-avx512f-u32.c
  src/f32-vbinary/gen/f32-vminc-avx512f-u16.c
  src/f32-vbinary/gen/f32-vminc-avx512f-u32.c
  src/f32-vbinary/gen/f32-vmul-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vmul-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vmulc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vmulc-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vrdivc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vrdivc-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vrsubc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vrsubc-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vsqrdiff-avx512f-u16.c
  src/f32-vbinary/gen/f32-vsqrdiff-avx512f-u32.c
  src/f32-vbinary/gen/f32-vsqrdiffc-avx512f-u16.c
  src/f32-vbinary/gen/f32-vsqrdiffc-avx512f-u32.c
  src/f32-vbinary/gen/f32-vsub-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vsub-minmax-avx512f-u32.c
  src/f32-vbinary/gen/f32-vsubc-minmax-avx512f-u16.c
  src/f32-vbinary/gen/f32-vsubc-minmax-avx512f-u32.c
  src/f32-vclamp/gen/f32-vclamp-avx512f-u16.c
  src/f32-vclamp/gen/f32-vclamp-avx512f-u32.c
  src/f32-vcopysign/gen/f32-vcopysign-avx512f.c
  src/f32-vcopysign/gen/f32-vcopysignc-avx512f.c
  src/f32-vcopysign/gen/f32-vrcopysignc-avx512f.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u16.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u32.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u48.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u64.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u80.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u96.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u112.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-lut16-p3-perm-u128.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u16.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u32.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u48.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u64.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u80.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u96.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u112.c
  src/f32-velu/gen/f32-velu-avx512f-rr1-p6-u128.c
  src/f32-vgelu/gen/f32-vgelu-avx512f-rational-12-10-div.c
  src/f32-vgelu/gen/f32-vgelu-avx512f-rational-12-10-nr.c
  src/f32-vhswish/gen/f32-vhswish-avx512f-u16.c
  src/f32-vhswish/gen/f32-vhswish-avx512f-u32.c
  src/f32-vlog/gen/f32-vlog-avx512f-rational-3-3-div.c
  src/f32-vlog/gen/f32-vlog-avx512f-rational-3-3-nr.c
  src/f32-vlrelu/gen/f32-vlrelu-avx512f-u16.c
  src/f32-vlrelu/gen/f32-vlrelu-avx512f-u32.c
  src/f32-vrelu/gen/f32-vrelu-avx512f-u16.c
  src/f32-vrelu/gen/f32-vrelu-avx512f-u32.c
  src/f32-vrnd/gen/f32-vrndd-avx512f-u16.c
  src/f32-vrnd/gen/f32-vrndd-avx512f-u32.c
  src/f32-vrnd/gen/f32-vrndne-avx512f-u16.c
  src/f32-vrnd/gen/f32-vrndne-avx512f-u32.c
  src/f32-vrnd/gen/f32-vrndu-avx512f-u16.c
  src/f32-vrnd/gen/f32-vrndu-avx512f-u32.c
  src/f32-vrnd/gen/f32-vrndz-avx512f-u16.c
  src/f32-vrnd/gen/f32-vrndz-avx512f-u32.c
  src/f32-vrsqrt/gen/f32-vrsqrt-avx512f-rsqrt-u16.c
  src/f32-vrsqrt/gen/f32-vrsqrt-avx512f-rsqrt-u32.c
  src/f32-vrsqrt/gen/f32-vrsqrt-avx512f-rsqrt-u64.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u16.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u32.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u48.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u64.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u80.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u96.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u112.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u128.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u144.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u160.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u176.c
  src/f32-vscaleexpminusmax/gen/f32-vscaleexpminusmax-avx512f-p5-scalef-u192.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u16.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u32.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u48.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u64.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u80.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u96.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u112.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u128.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u144.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u160.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u176.c
  src/f32-vscaleextexp/gen/f32-vscaleextexp-avx512f-p5-scalef-u192.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-div-u128.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-lut16-p3-perm-scalef-nr1fma-u128.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-div-u128.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr1-p5-scalef-nr1fma-u128.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-div-u128.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u16.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u32.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u48.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u64.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u80.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u96.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u112.c
  src/f32-vsigmoid/gen/f32-vsigmoid-avx512f-rr2-lut32-p2-perm2-scalef-nr1fma-u128.c
  src/f32-vsqrt/gen/f32-vsqrt-avx512f-rsqrt-u16.c
  src/f32-vsqrt/gen/f32-vsqrt-avx512f-rsqrt-u32.c
  src/f32-vsqrt/gen/f32-vsqrt-avx512f-rsqrt-u48.c
  src/f32-vtanh/gen/f32-vtanh-avx512f-rational-9-6-div.c
  src/f32-vtanh/gen/f32-vtanh-avx512f-rational-9-6-nr.c
  src/f32-vunary/gen/f32-vabs-avx512f.c
  src/f32-vunary/gen/f32-vneg-avx512f.c
  src/f32-vunary/gen/f32-vsqr-avx512f.c
  src/s32-vlshift/gen/s32-vlshift-avx512f.c
  src/s32-vlshift/gen/s32-vlshiftc-avx512f.c
  src/s32-vmul/gen/s32-vmul-avx512f.c
  src/s32-vmul/gen/s32-vmulc-avx512f.c
  src/x32-packw/gen/x32-packw-x16-gemm-goi-avx512f-u4-prfm.c
  src/x32-packw/gen/x32-packw-x16-gemm-goi-avx512f-u4.c)
