#pragma once

#include "mod/modint.hpp"

template <typename mint>
mint hook_length_formula(vc<int> A) {
  if (len(A) == 0) return 1;
  int H = len(A);
  FOR(i, H - 1) assert(A[i] >= A[i + 1]);
  int N = SUM<int>(A);

  FOR(i, H) A[i] += H - 1 - i;
  mint ANS = fact<mint>(N);
  FOR(j, H) FOR(i, j) ANS *= A[i] - A[j];
  FOR(i, H) ANS *= fact_inv<mint>(A[i]);
  return ANS;
}
