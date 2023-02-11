#include "poly/multipoint.hpp"
// O(Nlog^2N)
// 分母は相異なる 1 次式の積限定とする
// f / prod(ax+b) = sum c/(ax+b) という C を返す
template <typename mint>
vc<mint> partial_frac_decomposition(vc<mint> f, vc<mint> A) {
  assert(len(f) <= len(A));
  if (len(f) == 0) return vc<mint>(len(A));
  SubproductTree<mint> X(A);
  vc<mint> g = X.T[1]; // prod(1-ax)
  g.resize(len(A) + 1);
  reverse(all(g));
  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);
  g.pop_back();

  auto num = X.evaluation(f);
  auto den = X.evaluation(g);
  vc<mint> B(len(A));
  FOR(i, len(A)) B[i] = num[i] / den[i];
  return B;
}
