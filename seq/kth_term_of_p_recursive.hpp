#include "poly/prefix_product_of_poly.hpp"

// a0, ..., a_{r-1} および f_0, ..., f_r を与える
// a_r f_0(0) + a_{r-1}f_1(0) + ... = 0
// a_{r+1} f_0(1) + a_{r}f_1(1) + ... = 0
template <typename T>
T kth_term_of_p_recursive(vc<T> a, vc<vc<T>>& fs, ll k) {
  int r = len(a);
  assert(len(fs) == r + 1);
  if (k < r) return a[k];

  vc<vc<vc<T>>> A;
  A.resize(r);
  FOR(i, r) A[i].resize(r);
  FOR(i, r) {
    // A[0][i] = -fs[i + 1];
    for (auto&& x: fs[i + 1]) A[0][i].eb(-x);
  }
  FOR3(i, 1, r) A[i][i - 1] = fs[0];
  vc<T> den = fs[0];
  auto res = prefix_product_of_poly_matrix(A, k - r + 1);
  reverse(all(a));
  T ANS = 0;
  FOR(j, r) ANS += res[0][j] * a[j];
  ANS /= prefix_product_of_poly(den, k - r + 1);
  return ANS;
}
