#pragma once
#include "poly/fps_inv.hpp"

template <typename mint>
vc<mint> fps_log(const vc<mint>& f) {
  assert(f[0] == mint(1));
  ll N = len(f);
  vc<mint> df = f;
  FOR(i, N) df[i] *= mint(i);
  df.erase(df.begin());
  auto f_inv = fps_inv(f);
  auto g = convolution(df, f_inv);
  g.resize(N - 1);
  g.insert(g.begin(), 0);
  FOR(i, N) g[i] *= inv<mint>(i);
  return g;
}
