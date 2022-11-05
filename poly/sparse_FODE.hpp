#pragma once

// a(x)F'(x) + b(x)F(x) = 0 の形の微分方程式を解く
// [x^0]a=1 を仮定、[x^0]F=1 となる解を求める
// a, b が sparse であるとして、O(NK) 時間
template <typename mint>
vc<mint> sparse_FODE(const vc<mint>& a, const vc<mint>& b) {
  const int N = len(a);
  assert(len(b) == N);
  assert(a[0] == mint(1));
  using P = pair<int, mint>;

  vc<P> dat_a, dat_b;
  FOR(i, 1, N) if (a[i] != mint(0)) dat_a.eb(i, a[i]);
  FOR(i, 0, N) if (b[i] != mint(0)) dat_b.eb(i, b[i]);

  vc<mint> f(N);
  vc<mint> df(N - 1);
  f[0] = mint(1);
  FOR(n, N - 1) {
    mint v = 0;
    for (auto&& [i, ai]: dat_a) {
      if (i > n) break;
      v += ai * df[n - i];
    }
    for (auto&& [i, bi]: dat_b) {
      if (i > n) break;
      v += bi * f[n - i];
    }
    df[n] = -v;
    f[n + 1] = df[n] * inv<mint>(n + 1);
  }
  return f;
}