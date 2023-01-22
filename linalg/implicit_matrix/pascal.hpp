#include "poly/convolution.hpp"

// g[i] = sum binom(i, j) f[j]
template <typename mint>
vc<mint> pascal_1(vc<mint> f, bool inverse) {
  int n = len(f);
  vc<mint> g(n);
  FOR(i, n) g[i] = fact_inv<mint>(i);
  if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];
  FOR(i, n) f[i] *= fact_inv<mint>(i);
  f = convolution(f, g);
  f.resize(n);
  FOR(i, n) f[i] *= fact<mint>(i);
  return f;
}

// g[i] = sum binom(j, i) f[j]
template <typename mint>
vc<mint> pascal_2(vc<mint> f, bool inverse) {
  int n = len(f);
  FOR(i, n) f[i] *= fact<mint>(i);
  reverse(all(f));
  vc<mint> g(n);
  FOR(i, n) g[i] = fact_inv<mint>(i);
  if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];
  f = convolution(f, g);
  f.resize(n);
  reverse(all(f));
  FOR(i, n) f[i] *= fact_inv<mint>(i);
  return f;
}