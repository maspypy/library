#pragma once

#include "poly/fps_inv.hpp"
#include "poly/middle_product.hpp"
#include "mod/all_inverse.hpp"

template <typename mint>
struct SubproductTree {
  int m;
  int sz;
  vc<vc<mint>> T;
  SubproductTree(const vc<mint>& x) {
    m = len(x);
    sz = 1;
    while (sz < m) sz *= 2;
    T.resize(2 * sz);
    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};
    FOR3_R(i, 1, sz) T[i] = convolution(T[2 * i], T[2 * i + 1]);
  }

  vc<mint> evaluation(vc<mint> f) {
    int n = len(f);
    if (n == 0) return vc<mint>(m, mint(0));
    f.resize(2 * n - 1);
    vc<vc<mint>> g(2 * sz);
    g[1] = T[1];
    g[1].resize(n);
    g[1] = fps_inv(g[1]);
    g[1] = middle_product(f, g[1]);
    g[1].resize(sz);

    FOR3(i, 1, sz) {
      g[2 * i] = middle_product(g[i], T[2 * i + 1]);
      g[2 * i + 1] = middle_product(g[i], T[2 * i]);
    }
    vc<mint> vals(m);
    FOR(i, m) vals[i] = g[sz + i][0];
    return vals;
  }

  vc<mint> interpolation(vc<mint>& y) {
    assert(len(y) == m);
    vc<mint> a(m);
    FOR(i, m) a[i] = T[1][m - i - 1] * (i + 1);

    a = evaluation(a);
    vc<vc<mint>> t(2 * sz);
    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};
    FOR3_R(i, 1, sz) {
      t[i] = convolution(t[2 * i], T[2 * i + 1]);
      auto tt = convolution(t[2 * i + 1], T[2 * i]);
      FOR(k, len(t[i])) t[i][k] += tt[k];
    }
    t[1].resize(m);
    reverse(all(t[1]));
    return t[1];
  }
};

template <typename mint>
vc<mint> multipoint_eval(vc<mint>& f, vc<mint>& x) {
  if (x.empty()) return {};
  SubproductTree<mint> F(x);
  return F.evaluation(f);
}

template <typename mint>
vc<mint> multipoint_interpolate(vc<mint>& x, vc<mint>& y) {
  if (x.empty()) return {};
  SubproductTree<mint> F(x);
  return F.interpolation(y);
}

// calculate f(ar^k) for 0 <= k < m
template <typename mint>
vc<mint> multipoint_eval_on_geom_seq(vc<mint> f, mint a, mint r, int m) {
  const int n = len(f);
  if (m == 0) return {};

  auto eval = [&](mint x) -> mint {
    mint fx = 0;
    mint pow = 1;
    FOR(i, n) fx += f[i] * pow, pow *= x;
    return fx;
  };

  if (r == mint(0)) {
    vc<mint> res(m);
    FOR(i, 1, m) res[i] = f[0];
    res[0] = eval(a);
    return res;
  }
  if (n < 60 || m < 60) {
    vc<mint> res(m);
    FOR(i, m) res[i] = eval(a), a *= r;
    return res;
  }
  assert(r != mint(0));
  // a == 1 に帰着
  mint pow_a = 1;
  FOR(i, n) f[i] *= pow_a, pow_a *= a;

  auto calc = [&](mint r, int m) -> vc<mint> {
    // r^{t_i} の計算
    vc<mint> res(m);
    mint pow = 1;
    res[0] = 1;
    FOR(i, m - 1) {
      res[i + 1] = res[i] * pow;
      pow *= r;
    }
    return res;
  };

  vc<mint> A = calc(r, n + m - 1), B = calc(r.inverse(), max(n, m));
  FOR(i, n) f[i] *= B[i];
  f = middle_product(A, f);
  FOR(i, m) f[i] *= B[i];
  return f;
}

// Y[i] = f(ar^i)
template <typename mint>
vc<mint> multipoint_interpolate_on_geom_seq(vc<mint> Y, mint a, mint r) {
  const int n = len(Y);
  if (n == 0) return {};
  if (n == 1) return {Y[0]};
  assert(r != mint(0));
  mint ir = r.inverse();

  vc<mint> POW(n + n - 1), tPOW(n + n - 1);
  POW[0] = tPOW[0] = mint(1);
  FOR(i, n + n - 2) POW[i + 1] = POW[i] * r, tPOW[i + 1] = tPOW[i] * POW[i];

  vc<mint> iPOW(n + n - 1), itPOW(n + n - 1);
  iPOW[0] = itPOW[0] = mint(1);
  FOR(i, n) iPOW[i + 1] = iPOW[i] * ir, itPOW[i + 1] = itPOW[i] * iPOW[i];

  // prod_[1,i] 1-r^k
  vc<mint> S(n);
  S[0] = mint(1);
  FOR(i, 1, n) S[i] = S[i - 1] * (mint(1) - POW[i]);
  vc<mint> iS = all_inverse<mint>(S);
  mint sn = S[n - 1] * (mint(1) - POW[n]);

  FOR(i, n) {
    Y[i] = Y[i] * tPOW[n - 1 - i] * itPOW[n - 1] * iS[i] * iS[n - 1 - i];
    if (i % 2 == 1) Y[i] = -Y[i];
  }

  // sum_i Y[i] / 1-r^ix
  FOR(i, n) Y[i] *= itPOW[i];
  vc<mint> f = middle_product(tPOW, Y);
  FOR(i, n) f[i] *= itPOW[i];

  // prod 1-r^ix
  vc<mint> g(n);
  g[0] = mint(1);
  FOR(i, 1, n) {
    g[i] = tPOW[i] * sn * iS[i] * iS[n - i];
    if (i % 2 == 1) g[i] = -g[i];
  }
  f = convolution<mint>(f, g);
  f.resize(n);

  reverse(all(f));
  mint ia = a.inverse();
  mint pow = 1;
  FOR(i, n) f[i] *= pow, pow *= ia;
  return f;
}
