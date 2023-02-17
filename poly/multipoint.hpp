#pragma once

#include "poly/fps_inv.hpp"
#include "poly/middle_product.hpp"

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
// https://noshi91.github.io/algorithm-encyclopedia/chirp-z-transform#noredirect
template <typename mint>
vc<mint> multipoint_eval_on_geom_seq(vc<mint> f, mint a, mint r, int m) {
  const int n = len(f);
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
  reverse(all(f));
  f = convolution(f, A);
  f = {f.begin() + n - 1, f.end()};
  f.resize(m);
  FOR(i, m) f[i] *= B[i];
  return f;
}