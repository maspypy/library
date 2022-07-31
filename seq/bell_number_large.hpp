#include "seq/coef_of_rational_fps.hpp"

// Bell 数 B_n の計算。O(p logp logn)
template <typename mint>
mint Bell_Number_large(ll n) {
  int p = mint::get_mod();
  vc<mint> f(p);
  FOR(i, p) f[i] = fact_inv<mint>(i);
  f[0] = 0;
  f = fps_exp(f);
  FOR(i, p) f[i] *= fact<mint>(i);
  vc<mint> g(p + 1);
  g[0] = 1;
  g[p - 1] = -1;
  g[p] = -1;
  f = convolution(f, g);
  f.resize(p);
  return coef_of_rational_fps<mint>(f, g, n);
}
