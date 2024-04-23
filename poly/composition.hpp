#pragma once

#include "poly/convolution.hpp"
#include "poly/poly_taylor_shift.hpp"
#include "poly/transposed_ntt.hpp"

template <typename mint>
vc<mint> composition_old(vc<mint>& Q, vc<mint>& P) {
  int n = len(P);
  assert(len(P) == len(Q));
  int k = 1;
  while (k * k < n) ++k;
  // compute powers of P
  vv(mint, pow1, k + 1);
  pow1[0] = {1};
  pow1[1] = P;
  FOR3(i, 2, k + 1) {
    pow1[i] = convolution(pow1[i - 1], pow1[1]);
    pow1[i].resize(n);
  }
  vv(mint, pow2, k + 1);
  pow2[0] = {1};
  pow2[1] = pow1[k];
  FOR3(i, 2, k + 1) {
    pow2[i] = convolution(pow2[i - 1], pow2[1]);
    pow2[i].resize(n);
  }
  vc<mint> ANS(n);
  FOR(i, k + 1) {
    vc<mint> f(n);
    FOR(j, k) {
      if (k * i + j < len(Q)) {
        mint coef = Q[k * i + j];
        FOR(d, len(pow1[j])) f[d] += pow1[j][d] * coef;
      }
    }
    f = convolution(f, pow2[i]);
    f.resize(n);
    FOR(d, n) ANS[d] += f[d];
  }
  return ANS;
}

// f(g(x)), O(Nlog^2N)
template <typename mint>
vc<mint> composition(vc<mint> f, vc<mint> g) {
  assert(len(f) == len(g));
  if (f.empty()) return {};

  // [x^0]g=0 に帰着しておく
  if (g[0] != mint(0)) {
    f = poly_taylor_shift<mint>(f, g[0]);
    g[0] = 0;
  }

  int n0 = len(f);
  int n = 1;
  while (n < len(f)) n *= 2;
  f.resize(n), g.resize(n);

  vc<mint> W(n);
  {
    // bit reverse order
    vc<int> btr(n);
    int log = topbit(n);
    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }
    int t = mint::ntt_info().fi;
    mint r = mint::ntt_info().se;
    mint dw = r.inverse().pow((1 << t) / (2 * n));
    mint w = 1;
    for (auto& i: btr) { W[i] = w, w *= dw; }
  }

  auto rec = [&](auto& rec, int n, int k, vc<mint>& Q) -> vc<mint> {
    if (n == 1) {
      reverse(all(f));
      transposed_ntt(f, 1);
      mint c = mint(1) / mint(k);
      for (auto& x: f) x *= c;
      vc<mint> p(4 * k);
      FOR(i, k) p[2 * i] = f[i];
      return p;
    }
    auto doubling_y = [&](vc<mint>& A, int l, int r, bool t) -> void {
      mint z = W[k / 2].inverse();
      vc<mint> f(k);
      if (!t) {
        FOR(i, l, r) {
          FOR(j, k) f[j] = A[2 * n * j + i];
          ntt(f, 1);
          mint r = 1;
          FOR(j, 1, k) r *= z, f[j] *= r;
          ntt(f, 0);
          FOR(j, k) A[2 * n * (k + j) + i] = f[j];
        }
      } else {
        FOR(i, l, r) {
          FOR(j, k) f[j] = A[2 * n * (k + j) + i];
          transposed_ntt(f, 0);
          mint r = 1;
          FOR(j, 1, k) r *= z, f[j] *= r;
          transposed_ntt(f, 1);
          FOR(j, k) A[2 * n * j + i] += f[j];
        }
      }
    };

    auto FFT_x = [&](vc<mint>& A, int l, int r, bool t) -> void {
      vc<mint> f(2 * n);
      if (!t) {
        FOR(j, l, r) {
          move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());
          ntt(f, 0);
          move(all(f), A.begin() + 2 * n * j);
        }
      } else {
        FOR(j, l, r) {
          move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());
          transposed_ntt(f, 0);
          move(all(f), A.begin() + 2 * n * j);
        }
      }
    };

    if (n <= k) doubling_y(Q, 1, n, 0), FFT_x(Q, 0, 2 * k, 0);
    if (n > k) FFT_x(Q, 0, k, 0), doubling_y(Q, 0, 2 * n, 0);

    FOR(i, 2 * n * k) Q[i] += 1;
    FOR(i, 2 * n * k, 4 * n * k) Q[i] -= 1;

    vc<mint> nxt_Q(4 * n * k);
    vc<mint> F(2 * n), G(2 * n), f(n), g(n);
    FOR(j, 2 * k) {
      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());
      FOR(i, n) { g[i] = G[2 * i] * G[2 * i + 1]; }
      ntt(g, 1);
      move(g.begin(), g.begin() + n / 2, nxt_Q.begin() + n * j);
    }
    FOR(j, 4 * k) nxt_Q[n * j] = 0;

    vc<mint> p = rec(rec, n / 2, k * 2, nxt_Q);
    FOR_R(j, 2 * k) {
      move(p.begin() + n * j, p.begin() + n * j + n / 2, f.begin());
      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());
      fill(f.begin() + n / 2, f.end(), mint(0));
      transposed_ntt(f, 1);
      FOR(i, n) {
        f[i] *= W[i];
        F[2 * i] = G[2 * i + 1] * f[i], F[2 * i + 1] = -G[2 * i] * f[i];
      }
      move(F.begin(), F.end(), p.begin() + 2 * n * j);
    }
    if (n <= k) FFT_x(p, 0, 2 * k, 1), doubling_y(p, 0, n, 1);
    if (n > k) doubling_y(p, 0, 2 * n, 1), FFT_x(p, 0, k, 1);
    return p;
  };

  vc<mint> Q(4 * n);
  FOR(i, n) Q[i] = -g[i];

  vc<mint> p = rec(rec, n, 1, Q);
  p.resize(n);
  reverse(all(p));
  p.resize(n0);
  return p;
}
