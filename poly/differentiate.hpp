#pragma once

template <typename mint>
vc<mint> differentiate(const vc<mint>& f) {
  if (len(f) <= 1) return {};
  vc<mint> g(len(f) - 1);
  FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);
  return g;
}