#include "poly/sum_of_power_of_roots.hpp"
#include "poly/fps_exp.hpp"

// https://codeforces.com/blog/entry/103136
// f(x) = prod(1-a_i x), g(x) = prod(1-b_j x) のとき
// prod_{i,j} (1-(a_ib_j)x) を計算する。
template <typename mint>
vc<mint> composed_product(vc<mint> f, vc<mint> g) {
  int n = len(f) - 1, m = len(g) - 1;
  vc<mint> A = sum_of_power_of_roots(f, n * m);
  vc<mint> B = sum_of_power_of_roots(g, n * m);
  A = convolution(A, B);
  A.resize(n * m + 1);
  FOR(i, len(A)) A[i] = -A[i];
  A[0] += mint(n * m);
  // A.erase(A.begin()); -> f'/f = (log f)'
  FOR(i, 1, n * m + 1) A[i] *= inv<mint>(i);
  return fps_exp(A);
}