#include "poly/count_terms.hpp"
#include "poly/convolution.hpp"

template <typename mint>
vc<mint> fps_inv_sparse(const vc<mint>& f) {
  int N = len(f);
  vc<pair<int, mint>> dat;
  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> g(N);
  mint g0 = mint(1) / f[0];
  g[0] = g0;
  FOR(n, 1, N) {
    mint rhs = 0;
    for (auto&& [k, fk] : dat) {
      if (k > n) break;
      rhs -= fk * g[n - k];
    }
    g[n] = rhs * g0;
  }
  return g;
}

template <typename mint>
vc<mint> fps_inv_dense_ntt(const vc<mint>& F) {
  vc<mint> G = {mint(1) / F[0]};
  ll N = len(F), n = 1;
  G.reserve(N);
  while (n < N) {
    vc<mint> f(2 * n), g(2 * n);
    FOR(i, min(N, 2 * n)) f[i] = F[i];
    FOR(i, n) g[i] = G[i];
    ntt(f, false), ntt(g, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR(i, n) f[i] = 0;
    ntt(f, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);
    n *= 2;
  }
  return G;
}

vc<modint<2>> fps_inv_mod_2(const vc<modint<2>>& F) {
  using mint = modint<2>;
  auto dfs = [&](auto& dfs, int n) -> vc<mint> {
    // 1/f を [0,n] で求める
    if (n == 0) {
      return {mint(1)};
    }
    int m = n / 2;
    vc<mint> g = dfs(dfs, m);
    g.resize(n + 1);
    FOR_R(i, n + 1) g[i] = (i % 2 == 0 ? g[i / 2] : 0);
    // g=[0,n] of 1/f(x)^2
    vc<mint> h(n + 1);
    FOR(i, n + 1) h[i] = F[i];
    g = convolution(g, h);
    g.resize(n + 1);
    return g;
  };
  return dfs(dfs, len(F) - 1);
}

template <typename mint>
vc<mint> fps_inv_dense(const vc<mint>& F) {
  if (mint::can_ntt()) return fps_inv_dense_ntt(F);
  if constexpr (is_same_v<mint, modint<2>>) {
    return fps_inv_mod_2(F);
  }
  const int N = len(F);
  vc<mint> R = {mint(1) / F[0]};
  vc<mint> p;
  int m = 1;
  while (m < N) {
    p = convolution(R, R);
    p.resize(m + m);
    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};
    p = convolution(p, f);
    R.resize(m + m);
    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];
    m += m;
  }
  R.resize(N);
  return R;
}

template <typename mint>
vc<mint> fps_inv(const vc<mint>& f) {
  assert(f[0] != mint(0));
  int n = count_terms(f);
  int t = (mint::can_ntt() ? 160 : 820);
  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));
}
