#include "linalg/det_mod.hpp"

template <typename mint>
mint det(vvc<mint>& A) {
  const int n = len(A);
  vv(int, B, n, n);
  FOR(i, n) FOR(j, n) B[i][j] = A[i][j].val;
  return det_mod(B, mint::get_mod());
}
