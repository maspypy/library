#pragma once

#include "seq/find_linear_rec.hpp"
#include "seq/coef_of_rational_fps.hpp"

template <typename mint>
mint interpolate_linear_rec(vector<mint>& A, ll N) {
  auto G = find_linear_rec(A);
  auto F = convolution(A, G);
  F.resize(len(G) - 1);
  return coef_of_rational_fps(F, G, N);
}
