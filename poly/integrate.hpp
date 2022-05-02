#pragma once

template <typename mint>
vc<mint> integrate(const vc<mint>& f) {
  vc<mint> g(len(f) + 1);
  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);
  return g;
}