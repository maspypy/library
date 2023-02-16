#pragma once

#include "seq/kth_term_of_p_recursive.hpp"

// 対数微分 F'/F = a(x)/b(x) から F を復元する。
// a, b が sparse であれば、O(N(K1+K2)) 時間でできる
// [0, N] を計算
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

// F'/F = a/b の解の、[x^K]F を求める。右辺は低次の有理式。
template <typename mint>
mint from_log_differentiation_kth(int K, vc<mint>& a, vc<mint>& b) {
  assert(b[0] == mint(1));
  int r = max(len(a), len(b) - 1);
  vvc<mint> c(r + 1);
  FOR(i, r + 1) {
    mint c0 = 0, c1 = 0;
    if (i < len(b)) c0 += mint(r - i) * b[i];
    if (i < len(b)) c1 += b[i];
    if (0 <= i - 1 && i - 1 < len(b)) c0 -= a[i - 1];
    c[i] = {c0, c1};
  }
  auto f = from_log_differentiation(r - 1, a, b);
  mint ANS = kth_term_of_p_recursive(f, c, K);
  return ANS;
}