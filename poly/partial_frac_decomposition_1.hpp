#include "poly/multipoint.hpp"

// f(x) / prod(1-a_ix) = sum b_i/1-a_ix
template <typename mint>
vc<mint> partial_frac_decomposition_1(vc<mint> f, vc<mint> A) {
  int N = len(A);
  assert(len(f) <= N);
  f.resize(N);
  SubproductTree<mint> X(A);
  vc<mint> g = X.T[1]; // prod(1-ax)
  g.resize(N + 1);
  reverse(all(f));
  reverse(all(g));
  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);
  g.pop_back();
  auto num = X.evaluation(f);
  auto den = X.evaluation(g);
  vc<mint> B(len(A));
  FOR(i, len(A)) B[i] = num[i] / den[i];
  return B;
}
