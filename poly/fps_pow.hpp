#include "poly/fps_exp.hpp"
#include "poly/fps_log.hpp"

// fps の k 乗を求める。k >= 0 の前提である。
// ・dense な場合： log, exp を使う O(NlogN)
// ・sparse な場合： O(NK)
template <typename mint>
vc<mint> fps_pow(const vc<mint>& f, ll k, bool force_sparse = 0) {
  int n = len(f);
  int d = n;
  FOR_R(i, n) if (f[i] != 0) d = i;
  ll off = d * k;
  if (off >= n) return vc<mint>(n, 0);
  mint c = f[d];
  mint c_inv = mint(1) / mint(c);
  vc<mint> g(n - off);
  FOR(i, n - off) g[i] = f[d + i] * c_inv;
  g = fps_pow_1(g, mint(k), force_sparse);
  vc<mint> h(n);
  c = c.pow(k);
  FOR(i, len(g)) h[off + i] = g[i] * c;
  return h;
}

// 定数項が 1 の場合限定。指数は modint なので、負数や有理数でも可。
// ・dense な場合： log, exp を使う O(NlogN)
// ・sparse な場合： O(NK)
template <typename mint>
vc<mint> fps_pow_1(const vc<mint>& f, mint K, bool force_sparse = 0) {
  assert(f[0] == mint(1));
  int terms = 0;
  FOR(i, len(f)) if (f[i] != mint(0))++ terms;
  bool is_sparse = (terms <= 50) || force_sparse;
  if (!is_sparse) {
    auto log_f = fps_log(f);
    FOR(i, len(f)) log_f[i] *= K;
    return fps_exp(log_f);
  }

  // sparse pow
  int N = len(f);
  vc<pair<int, mint>> dat;
  FOR3(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> g(N);
  g[0] = 1;
  FOR(n, N - 1) {
    for (auto&& [d, cf]: dat) {
      if (d == 0 || d > n + 1) continue;
      mint t = cf * g[n - d + 1];
      g[n + 1] += t * (K * mint(d) - mint(n - d + 1));
    }
    g[n + 1] *= inv<mint>(n + 1);
  }
  return g;
}
