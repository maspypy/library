#pragma once
#include "poly/count_terms.hpp"
#include "poly/convolution.hpp"

template <typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv(
    const vc<mint>& f) {
  if (count_terms(f) <= 200) return fps_inv_sparse(f);
  return fps_inv_dense(f);
}

template <typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_inv(
    const vc<mint>& f) {
  if (count_terms(f) <= 700) return fps_inv_sparse(f);
  return fps_inv_dense(f);
}

template <typename mint>
vc<mint> fps_inv_sparse(const vc<mint>& f) {
  assert(f[0] != mint(0));
  int N = len(f);
  vc<pair<int, mint>> dat;
  FOR3(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> g(N);
  mint g0 = mint(1) / f[0];
  g[0] = g0;
  FOR3(n, 1, N) {
    mint rhs = 0;
    for (auto&& [k, fk]: dat) {
      if (k > n) break;
      rhs -= fk * g[n - k];
    }
    g[n] = rhs * g0;
  }
  return g;
}

template <typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(
    const vc<mint>& F) {
  assert(F[0] != mint(0));
  vc<mint> G = {mint(1) / F[0]};
  G.reserve(len(F));
  ll N = len(F), n = 1;
  while (n < N) {
    vc<mint> f(2 * n), g(2 * n);
    FOR(i, min(N, 2 * n)) f[i] = F[i];
    FOR(i, n) g[i] = G[i];
    ntt(f, false);
    ntt(g, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR(i, n) f[i] = 0;
    ntt(f, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR3(i, n, 2 * n) G.eb(f[i] * mint(-1));
    n *= 2;
  }
  G.resize(N);
  return G;
}

template <typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(
    const vc<mint>& F) {
  int N = len(F);
  assert(F[0] != mint(0));
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
