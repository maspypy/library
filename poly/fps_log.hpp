#pragma once

#include "poly/fps_inv.hpp"
#include "poly/count_terms.hpp"

template <typename mint>
vc<mint> fps_log_dense(const vc<mint>& f) {
  assert(f[0] == mint(1));
  ll N = len(f);
  vc<mint> df = f;
  FOR(i, N) df[i] *= mint(i);
  df.erase(df.begin());
  auto f_inv = fps_inv(f);
  auto g = convolution(df, f_inv);
  g.resize(N - 1);
  g.insert(g.begin(), 0);
  FOR(i, N) g[i] *= inv<mint>(i);
  return g;
}

template <typename mint>
vc<mint> fps_log_sparse(const vc<mint>& f) {
  int N = f.size();
  vc<pair<int, mint>> dat;
  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> F(N);
  vc<mint> g(N - 1);
  for (int n = 0; n < N - 1; ++n) {
    mint rhs = mint(n + 1) * f[n + 1];
    for (auto&& [i, fi]: dat) {
      if (i > n) break;
      rhs -= fi * g[n - i];
    }
    g[n] = rhs;
    F[n + 1] = rhs * inv<mint>(n + 1);
  }
  return F;
}

template <typename mint>
vc<mint> fps_log(const vc<mint>& f) {
  assert(f[0] == mint(1));
  int n = count_terms(f);
  int t = (mint::can_ntt() ? 200 : 1200);
  return (n <= t ? fps_log_sparse<mint>(f) : fps_log_dense<mint>(f));
}
