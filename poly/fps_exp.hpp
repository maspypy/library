#pragma once
#include "poly/convolution.hpp"
template <typename mint>
vc<mint> fps_exp(vc<mint>& f) {
  const int n = len(f);
  assert(n > 0 && f[0] == mint(0));
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
