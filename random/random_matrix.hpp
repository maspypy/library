
#include "random/base.hpp"
#include "linalg/det.hpp"
#include "linalg/matrix_mul.hpp"

template <typename mint>
vvc<mint> random_matrix(int n, int m, int rk) {
  if (n == m && m == rk) {
    while (1) {
      vv(mint, A, n, n);
      FOR(i, n) FOR(j, n) A[i][j] = RNG(0, mint::get_mod());
      if (det(A) == mint(0)) continue;
      return A;
    }
  }
  vvc<mint> L = random_matrix<mint>(n, n, n);
  vvc<mint> R = random_matrix<mint>(m, m, m);
  vv(mint, A, n, m);
  FOR(i, rk) A[i][i] = 1;
  A = matrix_mul<mint>(L, A, n, n, m);
  A = matrix_mul<mint>(A, R, n, m, m);
  return A;
}
