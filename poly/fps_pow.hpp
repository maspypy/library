#pragma once
#include "poly/count_terms.hpp"
#include "poly/fps_exp.hpp"
#include "poly/fps_log.hpp"

// fps の k 乗を求める。k >= 0 の前提である。
// 定数項が 1 で、k が mint の場合には、fps_pow_1 を使うこと。
// ・dense な場合： log, exp を使う O(NlogN)
// ・sparse な場合： O(NK)
template <typename mint>
vc<mint> fps_pow(const vc<mint>& f, ll k) {
  assert(0 <= k);
  int n = len(f);
  if (k == 0) {
    vc<mint> g(n);
    g[0] = mint(1);
    return g;
  }
  int d = n;
  FOR_R(i, n) if (f[i] != 0) d = i;
  // d * k >= n
  if (d >= ceil(n, k)) {
    vc<mint> g(n);
    return g;
  }
  ll off = d * k;
  mint c = f[d];
  mint c_inv = mint(1) / mint(c);
  vc<mint> g(n - off);
  FOR(i, n - off) g[i] = f[d + i] * c_inv;
  g = fps_pow_1(g, mint(k));
  vc<mint> h(n);
  c = c.pow(k);
  FOR(i, len(g)) h[off + i] = g[i] * c;
  return h;
}

template <typename mint>
vc<mint> fps_pow_1_sparse(const vc<mint>& f, mint K) {
  int N = len(f);
  vc<pair<int, mint>> dat;
  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> g(N);
  g[0] = 1;
  FOR(n, N - 1) {
    mint& x = g[n + 1];
    for (auto&& [d, cf]: dat) {
      if (d > n + 1) break;
      mint t = cf * g[n - d + 1];
      x += t * (K * mint(d) - mint(n - d + 1));
    }
    x *= inv<mint>(n + 1);
  }
  return g;
}

template <typename mint>
vc<mint> fps_pow_1_dense(const vc<mint>& f, mint K) {
  assert(f[0] == mint(1));
  auto log_f = fps_log(f);
  FOR(i, len(f)) log_f[i] *= K;
  return fps_exp_dense(log_f);
}

template <typename mint>
vc<mint> fps_pow_1(const vc<mint>& f, mint K) {
  int n = count_terms(f);
  int t = (mint::can_ntt() ? 100 : 1300);
  return (n <= t ? fps_pow_1_sparse(f, K) : fps_pow_1_dense(f, K));
}
