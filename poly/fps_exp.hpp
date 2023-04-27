#pragma once
#include "poly/convolution.hpp"
#include "poly/integrate.hpp"
#include "poly/differentiate.hpp"
#include "poly/count_terms.hpp"

template <typename mint>
vc<mint> fps_exp_sparse(vc<mint>& f) {
  if (len(f) == 0) return {mint(1)};
  assert(f[0] == 0);
  int N = len(f);
  // df を持たせる
  vc<pair<int, mint>> dat;
  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i - 1, mint(i) * f[i]);
  vc<mint> F(N);
  F[0] = 1;
  FOR(n, 1, N) {
    mint rhs = 0;
    for (auto&& [k, fk]: dat) {
      if (k > n - 1) break;
      rhs += fk * F[n - 1 - k];
    }
    F[n] = rhs * inv<mint>(n);
  }
  return F;
}

template <typename mint>
vc<mint> fps_exp_dense(vc<mint>& h) {
  const int n = len(h);
  assert(n > 0 && h[0] == mint(0));
  if (mint::can_ntt()) {
    vc<mint>& f = h;
    vc<mint> b = {1, (1 < n ? f[1] : 0)};
    vc<mint> c = {1}, z1, z2 = {1, 1};
    while (len(b) < n) {
      int m = len(b);
      auto y = b;
      y.resize(2 * m);
      ntt(y, 0);
      z1 = z2;
      vc<mint> z(m);
      FOR(i, m) z[i] = y[i] * z1[i];
      ntt(z, 1);
      FOR(i, m / 2) z[i] = 0;
      ntt(z, 0);
      FOR(i, m) z[i] *= -z1[i];
      ntt(z, 1);
      c.insert(c.end(), z.begin() + m / 2, z.end());
      z2 = c;
      z2.resize(2 * m);
      ntt(z2, 0);

      vc<mint> x(f.begin(), f.begin() + m);
      FOR(i, len(x) - 1) x[i] = x[i + 1] * mint(i + 1);
      x.back() = 0;
      ntt(x, 0);
      FOR(i, m) x[i] *= y[i];
      ntt(x, 1);

      FOR(i, m - 1) x[i] -= b[i + 1] * mint(i + 1);

      x.resize(m + m);
      FOR(i, m - 1) x[m + i] = x[i], x[i] = 0;
      ntt(x, 0);
      FOR(i, m + m) x[i] *= z2[i];
      ntt(x, 1);
      FOR_R(i, len(x) - 1) x[i + 1] = x[i] * inv<mint>(i + 1);
      x[0] = 0;

      FOR3(i, m, min(n, m + m)) x[i] += f[i];
      FOR(i, m) x[i] = 0;
      ntt(x, 0);
      FOR(i, m + m) x[i] *= y[i];
      ntt(x, 1);
      b.insert(b.end(), x.begin() + m, x.end());
    }
    b.resize(n);
    return b;
  }

  const int L = len(h);
  assert(L > 0 && h[0] == mint(0));
  int LOG = 0;
  while (1 << LOG < L) ++LOG;
  h.resize(1 << LOG);
  auto dh = differentiate(h);
  vc<mint> f = {1}, g = {1};
  int m = 1;

  vc<mint> p;

  FOR(LOG) {
    p = convolution(f, g);
    p.resize(m);
    p = convolution(p, g);
    p.resize(m);
    g.resize(m);
    FOR(i, m) g[i] += g[i] - p[i];
    p = {dh.begin(), dh.begin() + m - 1};
    p = convolution(f, p);
    p.resize(m + m - 1);
    FOR(i, m + m - 1) p[i] = -p[i];
    FOR(i, m - 1) p[i] += mint(i + 1) * f[i + 1];
    p = convolution(p, g);

    p.resize(m + m - 1);
    FOR(i, m - 1) p[i] += dh[i];
    p = integrate(p);
    FOR(i, m + m) p[i] = h[i] - p[i];
    p[0] += mint(1);
    f = convolution(f, p);
    f.resize(m + m);
    m += m;
  }
  f.resize(L);
  return f;
}

template <typename mint>
vc<mint> fps_exp(vc<mint>& f) {
  int n = count_terms(f);
  int t = (mint::can_ntt() ? 320 : 3000);
  return (n <= t ? fps_exp_sparse<mint>(f) : fps_exp_dense<mint>(f));
}
