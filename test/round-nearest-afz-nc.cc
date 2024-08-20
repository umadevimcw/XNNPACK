// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <cmath>

#include "unary-operator-tester.h"

namespace xnnpack {

class RoundNearestAFZOperatorTester : public UnaryOperatorTester {
 public:
  RoundNearestAFZOperatorTester() : UnaryOperatorTester() {
    range_f32_ = {-1.0f, 1.0f};
  }

 protected:
  // Computes the expected result for some input `x`. Subclasses should override
  // this function with their own reference function.
  float RefFunc(float x) const override { return x > 0.0f ? std::floor(x + 0.5f) : std::ceil(x - 0.5f); }

  CREATE_OP_OVERRIDES_F32(roundnearestafz);
};

CREATE_UNARY_FLOAT_TESTS(F32, RoundNearestAFZOperatorTester);
CREATE_UNARY_FLOAT_TESTS(RunF32, RoundNearestAFZOperatorTester);

};  // namespace xnnpack
