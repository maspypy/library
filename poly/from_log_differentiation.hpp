#pragma once

// 対数微分 F'/F = a(x)/b(x) から F を復元する。
// a, b が sparse であれば、O(N(K1+K2)) 時間でできる
template <typename mint>
vc<mint> from_log_differentiation(int N, const vc<mint>& a, const vc<mint>& b) {
  assert(b[0] == mint(1));
  using P = pair<int, mint>;

  vc<P> dat_a, dat_b;
  FOR(i, len(a)) if (a[i] != mint(0)) dat_a.eb(i, a[i]);
  FOR(i, 1, len(b)) if (b[i] != mint(0)) dat_b.eb(i, b[i]);

  vc<mint> f(N + 1);
  vc<mint> df(N);
  f[0] = mint(1);
  FOR(n, N) {
    mint v = 0;
    for (auto&& [i, bi]: dat_b) {
      if (i > n) break;
      v -= bi * df[n - i];
    }
    for (auto&& [i, ai]: dat_a) {
      if (i > n) break;
      v += ai * f[n - i];
    }
    df[n] = v;
    f[n + 1] = df[n] * inv<mint>(n + 1);
  }
  return f;
}