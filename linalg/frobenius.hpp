#pragma once
#include "random/base.hpp"
#include "linalg/matrix_inv.hpp"
#include "linalg/matrix_mul.hpp"
#include "poly/convolution.hpp"
#include "linalg/basis.hpp"
#include "poly/convolution_all.hpp"

// https://codeforces.com/blog/entry/124815
// P^{-1}AP = diag(companion(f0),companion(f1),...)
// without checking: ...|f2|f1|f0.
// time complexity O(N^3). failure prob O(N/mod).
template <typename mint>
struct Frobenius_Form {
  int n; // b : num of blocks
  const vvc<mint> A;
  vvc<mint> P, IP;
  vvc<mint> V;
  vvc<mint> F; // [-a0,-a1,...,-a[k-1]] の形で管理 (x^k と合同なもの)

  Frobenius_Form(vvc<mint>& A) : n(len(A)), A(A) {
    while (!trial()) {}
  }

  // N^3 + N^2log(exp)
  vvc<mint> pow(ll exp) {
    vv(mint, X, n, n);
    int s = 0;
    FOR(k, len(F)) {
      int d = len(F[k]);
      vc<mint> f = powmod(F[k], exp);
      FOR(j, d) {
        FOR(i, len(f)) { X[s + i][s + j] = f[i]; }
        if (j == d - 1) break;
        f.insert(f.begin(), 0);
        divmod_inplace(f, F[k]);
      }
      s += d;
    }
    X = matrix_mul(P, X);
    X = matrix_mul(X, IP);
    return X;
  }

  // p(A)
  vvc<mint> poly_eval(vc<mint>& p) {
    vv(mint, X, n, n);
    int s = 0;
    FOR(k, len(F)) {
      int d = len(F[k]);
      vc<mint> f = p;
      divmod_inplace(f, F[k]);
      FOR(j, d) {
        FOR(i, len(f)) { X[s + i][s + j] = f[i]; }
        if (j == d - 1) break;
        f.insert(f.begin(), 0);
        divmod_inplace(f, F[k]);
      }
      s += d;
    }
    X = matrix_mul(P, X);
    X = matrix_mul(X, IP);
    return X;
  }

  vc<mint> characteristic_poly() {
    vvc<mint> polys;
    for (auto& f: F) {
      vc<mint> g = f;
      for (auto& x: g) x = -x;
      g.eb(1);
      polys.eb(g);
    }
    vc<mint> f = convolution_all(polys);
    return f;
  }

  // x^n mod (x^d-g(x))
  vc<mint> powmod(vc<mint>& g, ll n) {
    if (n < len(g)) {
      vc<mint> f(n + 1);
      f[n] = 1;
      return f;
    }
    vc<mint> f = powmod(g, n / 2);
    f = convolution_naive(f, f);
    if (n & 1) f.insert(f.begin(), 0);
    divmod_inplace(f, g);
    return f;
  }

private:
  bool trial() {
    V.clear(), F.clear();
    Basis<mint> S(n);
    while (1) {
      if (S.rank == n) break;
      int r = S.rank;
      vc<mint> v = random_vector();
      V.eb(v);
      while (1) {
        auto [solved, cf] = S.solve_or_add(v);
        if (!solved) {
          v = apply(v);
          continue;
        }
        vc<mint> f = {cf.begin() + r, cf.end()};
        F.eb(f);
        if (len(V) == 1) break;
        v = V.back();
        int s = 0;
        FOR(k, len(V) - 1) {
          int d = len(F[k]);
          vc<mint> R = {cf.begin() + s, cf.begin() + s + d};
          vc<mint> q = divmod_inplace(R, f);
          if (!R.empty()) {
            return false; // failure
          }
          FOR(i, len(q)) { FOR(j, n) v[j] -= q[i] * S.basis[s + i][j]; }
          s += d;
        }
        S.rollback(r);
        V.back() = v;
        FOR(i, len(f)) {
          S.solve_or_add(v);
          if (i + 1 < len(f)) v = apply(v);
        }
        break;
      }
    }
    P.assign(n, vc<mint>(n));
    FOR(i, n) FOR(j, n) P[i][j] = S.basis[j][i];
    IP = matrix_inv<mint>(P).se;
    return true;
  }

  vc<mint> random_vector() {
    vc<mint> v(n);
    FOR(i, n) v[i] = RNG(0, mint::get_mod());
    return v;
  }

  vc<mint> apply(vc<mint> v) {
    vc<mint> w(n);
    FOR(i, n) FOR(j, n) w[i] += A[i][j] * v[j];
    return w;
  }

  // f mod= (x^d-g(x)) (inplace), return : q
  vc<mint> divmod_inplace(vc<mint>& f, vc<mint>& g) {
    while (len(f) && f.back() == mint(0)) POP(f);
    int d = len(g);
    vc<mint> q;
    FOR_R(i, d, len(f)) {
      q.eb(f[i]);
      FOR(j, len(g)) f[i - d + j] += f[i] * g[j];
      f[i] = 0;
    }
    while (len(f) && f.back() == mint(0)) POP(f);
    reverse(all(q));
    return q;
  }
};