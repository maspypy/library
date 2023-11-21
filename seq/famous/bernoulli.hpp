#include "poly/fps_inv.hpp"

template <typename mint>
vc<mint> bernoulli_number(int n) {
  vc<mint> f(n + 1);
  FOR(i, n + 1) f[i] = fact_inv<mint>(1 + i);
  f = fps_inv<mint>(f);
  FOR(i, n + 1) f[i] *= fact<mint>(i);
  return f;
}
