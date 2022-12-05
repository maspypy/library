#pragma once
#include "linalg/mat_mul.hpp"
#include "poly/lagrange_interpolate_iota.hpp"

// A[k-1]...A[0] を計算する
// アルゴリズム参考：https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/polynomial_matrix_prod.rs
// 実装参考：https://nyaannyaan.github.io/library/matrix/polynomial-matrix-prefix-prod.hpp
template <typename T>
vc<vc<T>> prefix_product_of_poly_matrix(vc<vc<vc<T>>>& A, ll k) {
  int n = len(A);

  using MAT = vc<vc<T>>;
  auto shift = [&](vc<MAT>& G, T x) -> vc<MAT> {
    int d = len(G);
    vvv(T, H, d, n, n);
    FOR(i, n) FOR(j, n) {
      vc<T> g(d);
      FOR(l, d) g[l] = G[l][i][j];
      auto h = lagrange_interpolate_iota(g, x, d);
      FOR(l, d) H[l][i][j] = h[l];
    }
    return H;
  };

  auto evaluate = [&](vc<T>& f, T x) -> T {
    T res = 0;
    T p = 1;
    FOR(i, len(f)) {
      res += f[i] * p;
      p *= x;
    }
    return res;
  };

  ll deg = 1;
  FOR(i, n) FOR(j, n) chmax(deg, len(A[i][j]) - 1);

  vc<MAT> G(deg + 1);
  ll v = 1;
  while (deg * v * v < k) v *= 2;
  T iv = T(1) / T(v);

  FOR(i, len(G)) {
    T x = T(v) * T(i);
    vv(T, mat, n, n);
    FOR(j, n) FOR(k, n) mat[j][k] = evaluate(A[j][k], x);
    G[i] = mat;
  }

  for (ll w = 1; w != v; w *= 2) {
    T W = w;
    auto G1 = shift(G, W * iv);
    auto G2 = shift(G, (W * T(deg) * T(v) + T(v)) * iv);
    auto G3 = shift(G, (W * T(deg) * T(v) + T(v) + W) * iv);
    FOR(i, w * deg + 1) {
      G[i] = mat_mul(G1[i], G[i]);
      G2[i] = mat_mul(G3[i], G2[i]);
    }
    copy(G2.begin(), G2.end() - 1, back_inserter(G));
  }

  vv(T, res, n, n);
  FOR(i, n) res[i][i] = 1;
  ll i = 0;
  while (i + v <= k) res = mat_mul(G[i / v], res), i += v;
  while (i < k) {
    vv(T, mat, n, n);
    FOR(j, n) FOR(k, n) mat[j][k] = evaluate(A[j][k], i);
    res = mat_mul(mat, res);
    ++i;
  }
  return res;
}

// f[k-1]...f[0] を計算する
template <typename T>
T prefix_product_of_poly(vc<T>& f, ll k) {
  vc<vc<vc<T>>> A(1);
  A[0].resize(1);
  A[0][0] = f;
  auto res = prefix_product_of_poly_matrix(A, k);
  return res[0][0];
}