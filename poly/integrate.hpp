#pragma once

// 不定積分：integrate(f)
// 定積分：integrate(f, L, R)
template <typename mint>
vc<mint> integrate(const vc<mint>& f) {
  vc<mint> g(len(f) + 1);
  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);
  return g;
}

// 不定積分：integrate(f)
// 定積分：integrate(f, L, R)
template <typename mint>
mint integrate(const vc<mint>& f, mint L, mint R) {
  mint I = 0;
  mint pow_L = 1, pow_R = 1;
  FOR(i, len(f)) {
    pow_L *= L, pow_R *= R;
    I += inv<mint>(i + 1) * f[i] * (pow_R - pow_L);
  }
  return I;
}