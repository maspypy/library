#include "poly/fps_exp.hpp"

template <typename mint>
vc<mint> bell_number(int N) {
  vc<mint> f(N + 1);
  FOR(i, 1, N + 1) f[i] = fact_inv<mint>(i);
  f = fps_exp<mint>(f);
  FOR(i, N + 1) f[i] *= fact<mint>(i);
  return f;
};
