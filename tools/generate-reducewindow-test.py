#!/usr/bin/env python
# Copyright 2023 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

import argparse
import codecs
import math
import os
import re
import sys
import yaml

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xngen
import xnncommon


parser = argparse.ArgumentParser(
  description='Reduce window microkernel test generator')
parser.add_argument("-t", "--tester", metavar="TESTER", required=True,
                    choices=["ReduceWindowMicrokernelTester"],
                    help="Tester class to be used in the generated test")
parser.add_argument("-s", "--spec", metavar="FILE", required=True,
                    help="Specification (YAML) file")
parser.add_argument("-o", "--output", metavar="FILE", required=True,
                    help='Output (C++ source) file')
parser.set_defaults(defines=list())


def split_ukernel_name(name):
  match = re.fullmatch(r"xnn_(f32)_rw(sum)(_minmax_(fp32))?_ukernel__(.+)_u(\d+)(v)?(_acc\d+)?", name)
  if match is None:
    raise ValueError("Unexpected microkernel name: " + name)
  op_type = {
    "sum": "Sum",
  }[match.group(2)]
  requantization_type = match.group(4)
  batch_tile = int(match.group(6))
  vector_tile = bool(match.group(7))
  target_name = match.group(5)
  arch, isa, assembly = xnncommon.parse_target_name(target_name=target_name)
  return requantization_type, op_type, batch_tile, vector_tile, arch, isa


REDUCE_TEST_TEMPLATE = """\
TEST(${TEST_NAME}, rows_eq_1_cols_eq_1) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  ${TESTER}()
    .rows(1)
    .cols(1)
    .Test(${", ".join(TEST_ARGS)});
}

TEST(${TEST_NAME}, rows_eq_1_cols_eq_n) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t col_size = 1; col_size < UINT32_MAX ; col_size++) {
    ${TESTER}()
      .rows(1)
      .cols(col_size)
      .Test(${", ".join(TEST_ARGS)});
  }
}

TEST(${TEST_NAME}, rows_eq_n_cols_eq_1) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t row_size = 1; row_size < UINT32_MAX ; row_size++) {
    ${TESTER}()
      .rows(row_size)
      .cols(1)
      .Test(${", ".join(TEST_ARGS)});
  }
}

TEST(${TEST_NAME}, rows_eq_cols) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t size = 1; size < UINT32_MAX ; size++) {
    ${TESTER}()
      .rows(size)
      .cols(size)
      .Test(${", ".join(TEST_ARGS)});
  }
}
TEST(${TEST_NAME}, rows_cols_from_1_to_n) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t row_size = 1; row_size < UINT32_MAX ; row_size++) {
    for (size_t col_size = 1; col_size < UINT32_MAX ; col_size++) {
      ${TESTER}()
        .rows(size)
        .cols(size)
        .Test(${", ".join(TEST_ARGS)});
    }
  }
}
"""


def generate_test_cases(ukernel, op_type, init_fn, requantization_type, tester, batch_tile, vector_tile, isa):
  """Generates all tests cases for a Vector Binary Operation micro-kernel.

  Args:
    ukernel: C name of the micro-kernel function.
    op_type: Operation type (MAX/MIN/SUM/etc).
    init_fn: C name of the function to initialize microkernel parameters.
    requantization_type: Requantization type (FP32/RNDNU).
    tester: C++ name of the tester class.
    batch_tile: Number of batch elements processed per one iteration of the
                inner loop of the micro-kernel.
    vector_tile: Indicates if batch tile is specified in vectors rather than
                 elements.
    isa: instruction set required to run the micro-kernel. Generated unit test
         will skip execution if the host processor doesn't support this ISA.

  Returns:
    Code for the test case.
  """
  _, test_name = ukernel.split("_", 1)
  _, datatype, _ = ukernel.split("_", 2)
  test_args = [ukernel]
  if tester == "ReduceWindowMicrokernelTester":
    test_args.append("ReduceWindowMicrokernelTester::OpType::%s" % op_type)
  if init_fn:
    test_args.append(init_fn)
  batch_scale = ""
  if requantization_type:
    test_args.append("xnn_qs8_requantize_%s" % \
      requantization_type.lower())
  if vector_tile:
    ctype = {"u8": "uint8_t", "f16": "uint16_t", "f32": "float"}[datatype]
    batch_scale = {
      "rvv": " * xnn_init_hardware_config()->vlenb / sizeof(%s)" % ctype,
      "rvvfp16arith": " * xnn_init_hardware_config()->vlenb / sizeof(%s)" % ctype,
    }[isa]
  return xngen.preprocess(REDUCE_TEST_TEMPLATE, {
      "TEST_NAME": test_name.upper().replace("UKERNEL_", ""),
      "TEST_ARGS": test_args,
      "TESTER": tester,
      "DATATYPE": datatype.upper(),
      "BATCH_TILE": batch_tile,
      "BATCH_SCALE": batch_scale,
      "BATCH_SUFFIX": "v" if vector_tile else "",
      "OP_TYPE": op_type,
      "ISA_CHECK": xnncommon.generate_isa_check_macro(isa),
    })


def main(args):
  options = parser.parse_args(args)

  with codecs.open(options.spec, "r", encoding="utf-8") as spec_file:
    spec_yaml = yaml.safe_load(spec_file)
    if not isinstance(spec_yaml, list):
      raise ValueError("expected a list of micro-kernels in the spec")

    spec_name = os.path.splitext(os.path.split(options.spec)[1])[0]
    tester_header = {
      "ReduceWindowMicrokernelTester": "reducewindow-microkernel-tester.h",
    }[options.tester]
    tests = """\
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: {specification}
//   Generator: {generator}


#include <gtest/gtest.h>
#include "xnnpack/common.h"
#include "xnnpack/isa-checks.h"
#include "xnnpack/microparams-init.h"
#include "xnnpack/reduce.h"
#include "{tester_header}"
""".format(specification=options.spec, generator=sys.argv[0],
           tester_header=tester_header)

    for ukernel_spec in spec_yaml:
      name = ukernel_spec["name"]
      init_fn = ukernel_spec.get("init")
      requantization_type, op_type, batch_tile, vector_tile, arch, isa = split_ukernel_name(name)

      test_case = generate_test_cases(name, op_type, init_fn, requantization_type,
                                      options.tester, batch_tile, vector_tile, isa)
      tests += "\n\n" + xnncommon.postprocess_test_case(test_case, arch, isa)

    xnncommon.overwrite_if_changed(options.output, tests)


if __name__ == "__main__":
  main(sys.argv[1:])
