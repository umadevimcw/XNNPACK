// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/multipass-avx.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "xnnpack/dwconv.h"
#include "xnnpack/math.h"


void xnn_f32_dwconv_minmax_ukernel_6f6m7l8c8s4r__avx(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const float* zero,
    size_t kernel_size,
    float* buffer,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(channels != 0);
  assert(output_width != 0);
  assert(kernel_size > 6);

  static const int32_t mask_table[14] = {-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0};

  const __m256 vmin = _mm256_load_ps(params->avx.min);
  const __m256 vmax = _mm256_load_ps(params->avx.max);
  do {
    const float* w = weights;

    // First pass to process 6 inputs.
    {
      float* b = buffer;
      const float* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const float*) ((uintptr_t) i0 + input_offset);
      }
      const float* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const float*) ((uintptr_t) i1 + input_offset);
      }
      const float* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const float*) ((uintptr_t) i2 + input_offset);
      }
      const float* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const float*) ((uintptr_t) i3 + input_offset);
      }
      const float* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const float*) ((uintptr_t) i4 + input_offset);
      }
      const float* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const float*) ((uintptr_t) i5 + input_offset);
      }
      input += 6;

      // Process c channels and write to buffer.
      size_t c = round_up_po2(channels, 4);

      for (; c >= 8; c -= 8) {
        __m256 vacc01234567p0 = _mm256_load_ps(w);


        const __m256 vi0x01234567 = _mm256_loadu_ps(i0);
        i0 += 8;

        const __m256 vk0x01234567 = _mm256_load_ps(w + 8);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_loadu_ps(i1);
        i1 += 8;

        const __m256 vk1x01234567 = _mm256_load_ps(w + 16);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_loadu_ps(i2);
        i2 += 8;

        const __m256 vk2x01234567 = _mm256_load_ps(w + 24);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_loadu_ps(i3);
        i3 += 8;

        const __m256 vk3x01234567 = _mm256_load_ps(w + 32);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_loadu_ps(i4);
        i4 += 8;

        const __m256 vk4x01234567 = _mm256_load_ps(w + 40);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_loadu_ps(i5);
        i5 += 8;

        const __m256 vk5x01234567 = _mm256_load_ps(w + 48);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        w += 56;


        _mm256_store_ps(b, vacc01234567p0);
        b += 8;
      }

      if (c != 0) {
        assert(c >= 1);
        assert(c <= 7);
        const __m256i vmask = _mm256_loadu_si256((const __m256i*) &mask_table[7 - c]);
        __m256 vacc01234567p0 = _mm256_load_ps(w);


        const __m256 vi0x01234567 = _mm256_maskload_ps(i0, vmask);

        const __m256 vk0x01234567 = _mm256_load_ps(w + 8);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_maskload_ps(i1, vmask);

        const __m256 vk1x01234567 = _mm256_load_ps(w + 16);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_maskload_ps(i2, vmask);

        const __m256 vk2x01234567 = _mm256_load_ps(w + 24);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_maskload_ps(i3, vmask);

        const __m256 vk3x01234567 = _mm256_load_ps(w + 32);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_maskload_ps(i4, vmask);

        const __m256 vk4x01234567 = _mm256_load_ps(w + 40);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_maskload_ps(i5, vmask);

        const __m256 vk5x01234567 = _mm256_load_ps(w + 48);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        w += 56;


        _mm256_store_ps(b, vacc01234567p0);
      }
    }

    // Middle pass to process 6 inputs in each iteration.
    for (size_t ks = kernel_size - 6; ks > 7; ks -= 6) {
      float* b = buffer;
      const float* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const float*) ((uintptr_t) i0 + input_offset);
      }
      const float* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const float*) ((uintptr_t) i1 + input_offset);
      }
      const float* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const float*) ((uintptr_t) i2 + input_offset);
      }
      const float* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const float*) ((uintptr_t) i3 + input_offset);
      }
      const float* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const float*) ((uintptr_t) i4 + input_offset);
      }
      const float* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const float*) ((uintptr_t) i5 + input_offset);
      }
      input += 6;

      size_t c = round_up_po2(channels, 4);

      for (; c >= 8; c -= 8) {
        __m256 vacc01234567p0 = _mm256_load_ps(b);


        const __m256 vi0x01234567 = _mm256_loadu_ps(i0);
        i0 += 8;

        const __m256 vk0x01234567 = _mm256_load_ps(w);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_loadu_ps(i1);
        i1 += 8;

        const __m256 vk1x01234567 = _mm256_load_ps(w + 8);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_loadu_ps(i2);
        i2 += 8;

        const __m256 vk2x01234567 = _mm256_load_ps(w + 16);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_loadu_ps(i3);
        i3 += 8;

        const __m256 vk3x01234567 = _mm256_load_ps(w + 24);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_loadu_ps(i4);
        i4 += 8;

        const __m256 vk4x01234567 = _mm256_load_ps(w + 32);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_loadu_ps(i5);
        i5 += 8;

        const __m256 vk5x01234567 = _mm256_load_ps(w + 40);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        w += 48;


        _mm256_store_ps(b, vacc01234567p0);
        b += 8;
      }

      if (c != 0) {
        assert(c >= 1);
        assert(c <= 7);
        const __m256i vmask = _mm256_loadu_si256((const __m256i*) &mask_table[7 - c]);
        __m256 vacc01234567p0 = _mm256_load_ps(b);


        const __m256 vi0x01234567 = _mm256_maskload_ps(i0, vmask);

        const __m256 vk0x01234567 = _mm256_load_ps(w);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_maskload_ps(i1, vmask);

        const __m256 vk1x01234567 = _mm256_load_ps(w + 8);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_maskload_ps(i2, vmask);

        const __m256 vk2x01234567 = _mm256_load_ps(w + 16);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_maskload_ps(i3, vmask);

        const __m256 vk3x01234567 = _mm256_load_ps(w + 24);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_maskload_ps(i4, vmask);

        const __m256 vk4x01234567 = _mm256_load_ps(w + 32);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_maskload_ps(i5, vmask);

        const __m256 vk5x01234567 = _mm256_load_ps(w + 40);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        w += 48;


        _mm256_store_ps(b, vacc01234567p0);
      }
    }

    // Last pass to process up to 7 inputs.
    {
      float* b = buffer;
      const float* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const float*) ((uintptr_t) i0 + input_offset);
      }
      const float* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const float*) ((uintptr_t) i1 + input_offset);
      }
      const float* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const float*) ((uintptr_t) i2 + input_offset);
      }
      const float* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const float*) ((uintptr_t) i3 + input_offset);
      }
      const float* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const float*) ((uintptr_t) i4 + input_offset);
      }
      const float* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const float*) ((uintptr_t) i5 + input_offset);
      }
      const float* i6 = input[6];
      assert(i6 != NULL);
      if XNN_UNPREDICTABLE(i6 != zero) {
        i6 = (const float*) ((uintptr_t) i6 + input_offset);
      }

      size_t c = channels;


      for (; c >= 8; c -= 8) {
        __m256 vacc01234567p0 = _mm256_load_ps(b);
        b += 8;


        const __m256 vi0x01234567 = _mm256_loadu_ps(i0);
        i0 += 8;

        __m256 vk0x01234567 = _mm256_load_ps(w);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_loadu_ps(i1);
        i1 += 8;

        __m256 vk1x01234567 = _mm256_load_ps(w + 8);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_loadu_ps(i2);
        i2 += 8;

        __m256 vk2x01234567 = _mm256_load_ps(w + 16);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_loadu_ps(i3);
        i3 += 8;

        __m256 vk3x01234567 = _mm256_load_ps(w + 24);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_loadu_ps(i4);
        i4 += 8;

        __m256 vk4x01234567 = _mm256_load_ps(w + 32);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_loadu_ps(i5);
        i5 += 8;

        __m256 vk5x01234567 = _mm256_load_ps(w + 40);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        const __m256 vi6x01234567 = _mm256_loadu_ps(i6);
        i6 += 8;

        __m256 vk6x01234567 = _mm256_load_ps(w + 48);

        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi6x01234567, vk6x01234567));

        w += 56;



        __m256 vacc01234567 = _mm256_max_ps(vmin, vacc01234567p0);

        vacc01234567 = _mm256_min_ps(vmax, vacc01234567);

        _mm256_storeu_ps(output, vacc01234567);
        output += 8;
      }

      if XNN_UNLIKELY(c != 0) {
        assert(c >= 1);
        assert(c <= 7);
        __m256 vacc01234567p0 = _mm256_load_ps(b);
        const __m256i vmask = _mm256_loadu_si256((const __m256i*) &mask_table[7 - c]);

        const __m256 vi0x01234567 = _mm256_maskload_ps(i0, vmask);
        __m256 vk0x01234567 = _mm256_load_ps(w);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

        const __m256 vi1x01234567 = _mm256_maskload_ps(i1, vmask);
        __m256 vk1x01234567 = _mm256_load_ps(w + 8);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

        const __m256 vi2x01234567 = _mm256_maskload_ps(i2, vmask);
        __m256 vk2x01234567 = _mm256_load_ps(w + 16);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

        const __m256 vi3x01234567 = _mm256_maskload_ps(i3, vmask);
        __m256 vk3x01234567 = _mm256_load_ps(w + 24);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

        const __m256 vi4x01234567 = _mm256_maskload_ps(i4, vmask);
        __m256 vk4x01234567 = _mm256_load_ps(w + 32);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

        const __m256 vi5x01234567 = _mm256_maskload_ps(i5, vmask);
        __m256 vk5x01234567 = _mm256_load_ps(w + 40);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

        const __m256 vi6x01234567 = _mm256_maskload_ps(i6, vmask);
        __m256 vk6x01234567 = _mm256_load_ps(w + 48);
        vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi6x01234567, vk6x01234567));


        __m256 vacc01234567 = _mm256_max_ps(vmin, vacc01234567p0);
        vacc01234567 = _mm256_min_ps(vmax, vacc01234567);

        __m128 vacc0123 = _mm256_castps256_ps128(vacc01234567);
        if (c & 4) {
          _mm_storeu_ps(output, vacc0123);
          vacc0123 = _mm256_extractf128_ps(vacc01234567, 1);
          output += 4;
        }
        if (c & 2) {
          _mm_storel_pi((__m64*) output, vacc0123);
          vacc0123 = _mm_movehl_ps(vacc0123, vacc0123);
          output += 2;
        }
        if (c & 1) {
          _mm_store_ss(output, vacc0123);
          output += 1;
        }
      }

    }
    input = (const float**) ((uintptr_t) input + input_stride);
    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
