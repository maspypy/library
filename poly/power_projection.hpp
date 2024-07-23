#pragma once

#include "poly/convolution.hpp"

template <typename mint>
vc<mint> power_projection_0_ntt(vc<mint> wt, vc<mint> f, int m) {
  assert(len(f) == len(wt) && f[0] == mint(0));

  int n = 1;
  while (n < len(f)) n *= 2;

  for (auto& x: f) x = -x;
  f.resize(n), wt.resize(n);
  reverse(all(wt));
  vc<mint>&P = wt, &Q = f;
  P.resize(4 * n), Q.resize(4 * n);

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

  int k = 1;
  while (n > 1) {
    /*
    FFT step
    04.. -> 048c
    15.. -> 159d
    .... -> 26ae
    .... -> 37bf
    */

    auto doubling_y = [&](vc<mint>& A, int l, int r) -> void {
      mint z = W[k / 2].inverse();
      vc<mint> f(k);
      FOR(i, l, r) {
        FOR(j, k) f[j] = A[2 * n * j + i];
        ntt(f, 1);
        mint r = 1;
        FOR(j, 1, k) r *= z, f[j] *= r;
        ntt(f, 0);
        FOR(j, k) A[2 * n * (k + j) + i] = f[j];
      }
    };

    auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {
      vc<mint> f(2 * n);
      FOR(j, l, r) {
        move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());
        ntt(f, 0);
        move(all(f), A.begin() + 2 * n * j);
      }
    };

    if (n <= k) {
      doubling_y(P, 0, n), doubling_y(Q, 1, n);
      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);
    } else {
      FFT_x(P, 0, k), FFT_x(Q, 0, k);
      doubling_y(P, 0, 2 * n), doubling_y(Q, 0, 2 * n);
    }
    FOR(i, 2 * n * k) Q[i] += 1;
    FOR(i, 2 * n * k, 4 * n * k) Q[i] -= 1;

    /*
    048c -> 0248????
    159d -> ....????
    26ae
    37bf
    */
    vc<mint> F(2 * n), G(2 * n), f(n), g(n);
    FOR(j, 2 * k) {
      move(P.begin() + 2 * n * j, P.begin() + 2 * n * j + 2 * n, F.begin());
      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());
      FOR(i, n) {
        f[i] = W[i] * (F[2 * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);
        g[i] = G[2 * i] * G[2 * i + 1];
      }
      ntt(f, 1), ntt(g, 1);
      fill(f.begin() + n / 2, f.end(), mint(0));
      fill(g.begin() + n / 2, g.end(), mint(0));
      move(all(f), P.begin() + n * j);
      move(all(g), Q.begin() + n * j);
    }
    fill(P.begin() + 2 * n * k, P.end(), mint(0));
    fill(Q.begin() + 2 * n * k, Q.end(), mint(0));
    FOR(j, 4 * k) Q[n * j] = 0;
    n /= 2, k *= 2;
  }
  FOR(i, k) P[i] = P[2 * i];
  P.resize(k);
  mint c = mint(1) / mint(k);
  for (auto& x: P) x *= c;
  ntt(P, 1);
  reverse(all(P));
  P.resize(m + 1);
  return P;
}

// \sum_jwt[j][x^j]f^i を i=0,1,...,m
template <typename mint>
vc<mint> power_projection_0_garner(vc<mint> wt, vc<mint> f, int m) {
  assert(len(f) == len(wt) && f[0] == mint(0));
  int n = 1;
  while (n < len(f)) n *= 2;
  f.resize(n), wt.resize(n);
  reverse(all(wt));

  constexpr u32 p[] = {167772161, 469762049, 754974721};
  using mint0 = modint<p[0]>;
  using mint1 = modint<p[1]>;
  using mint2 = modint<p[2]>;
  vc<mint0> W0(2 * n);
  vc<mint1> W1(2 * n);
  vc<mint2> W2(2 * n);
  {
    // bit reverse order
    vc<int> btr(2 * n);
    int log = topbit(2 * n);
    FOR(i, 2 * n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }
    {
      int t = mint0::ntt_info().fi;
      mint0 r = mint0::ntt_info().se;
      mint0 dw = r.inverse().pow((1 << t) / (4 * n));
      mint0 w = 1;
      for (auto& i: btr) { W0[i] = w, w *= dw; }
    }
    {
      int t = mint1::ntt_info().fi;
      mint1 r = mint1::ntt_info().se;
      mint1 dw = r.inverse().pow((1 << t) / (4 * n));
      mint1 w = 1;
      for (auto& i: btr) { W1[i] = w, w *= dw; }
    }
    {
      int t = mint2::ntt_info().fi;
      mint2 r = mint2::ntt_info().se;
      mint2 dw = r.inverse().pow((1 << t) / (4 * n));
      mint2 w = 1;
      for (auto& i: btr) { W2[i] = w, w *= dw; }
    }
  }

  int k = 1;
  vc<mint> P(2 * n), Q(2 * n);
  FOR(i, n) P[i] = wt[i], Q[i] = -f[i];

  while (n > 1) {
    vc<mint0> P0(4 * n * k), Q0(4 * n * k);
    vc<mint1> P1(4 * n * k), Q1(4 * n * k);
    vc<mint2> P2(4 * n * k), Q2(4 * n * k);
    FOR(i, 2 * n * k) P0[i] = P[i].val, Q0[i] = Q[i].val;
    FOR(i, 2 * n * k) P1[i] = P[i].val, Q1[i] = Q[i].val;
    FOR(i, 2 * n * k) P2[i] = P[i].val, Q2[i] = Q[i].val;
    Q0[2 * n * k] = 1, Q1[2 * n * k] = 1, Q2[2 * n * k] = 1;
    ntt(P0, 0), ntt(Q0, 0), ntt(P1, 0), ntt(Q1, 0), ntt(P2, 0), ntt(Q2, 0);
    FOR(i, 2 * n * k) {
      P0[i] = inv<mint0>(2) * W0[i]
              * (P0[2 * i] * Q0[2 * i + 1] - P0[2 * i + 1] * Q0[2 * i]);
      Q0[i] = Q0[2 * i] * Q0[2 * i + 1];
      P1[i] = inv<mint1>(2) * W1[i]
              * (P1[2 * i] * Q1[2 * i + 1] - P1[2 * i + 1] * Q1[2 * i]);
      Q1[i] = Q1[2 * i] * Q1[2 * i + 1];
      P2[i] = inv<mint2>(2) * W2[i]
              * (P2[2 * i] * Q2[2 * i + 1] - P2[2 * i + 1] * Q2[2 * i]);
      Q2[i] = Q2[2 * i] * Q2[2 * i + 1];
    }
    P0.resize(2 * n * k), Q0.resize(2 * n * k);
    P1.resize(2 * n * k), Q1.resize(2 * n * k);
    P2.resize(2 * n * k), Q2.resize(2 * n * k);
    ntt(P0, 1), ntt(Q0, 1), ntt(P1, 1), ntt(Q1, 1), ntt(P2, 1), ntt(Q2, 1);

    constexpr i128 K = u128(p[0]) * p[1] * p[2];
    auto get = [&](mint0 a, mint1 b, mint2 c) -> mint {
      i128 x = CRT3<u128, p[0], p[1], p[2]>(a.val, b.val, c.val);
      i128 y = K - x;
      return (x < y ? mint(x) : -mint(y));
    };

    fill(all(P), mint(0));
    fill(all(Q), mint(0));
    FOR(j, 2 * k) FOR(i, n / 2) {
      int k = n * j + i;
      P[k] = get(P0[k], P1[k], P2[k]);
      Q[k] = get(Q0[k], Q1[k], Q2[k]);
    }
    Q[0] = 0;
    n /= 2, k *= 2;
  }
  vc<mint> F(k);
  FOR(i, k) F[i] = P[2 * i];
  reverse(all(F));
  F.resize(m + 1);
  return F;
}

// \sum_j[x^j]f^i を i=0,1,...,m
template <typename mint>
vc<mint> power_projection(vc<mint> wt, vc<mint> f, int m) {
  assert(len(f) == len(wt));
  if (f.empty()) { return vc<mint>(m + 1, mint(0)); }
  if (f[0] != mint(0)) {
    mint c = f[0];
    f[0] = 0;
    vc<mint> A = power_projection(wt, f, m);
    FOR(p, m + 1) A[p] *= fact_inv<mint>(p);
    vc<mint> B(m + 1);
    mint pow = 1;
    FOR(q, m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;
    A = convolution<mint>(A, B);
    A.resize(m + 1);
    FOR(i, m + 1) A[i] *= fact<mint>(i);
    return A;
  }
  if (mint::can_ntt()) { return power_projection_0_ntt(wt, f, m); }
  return power_projection_0_garner(wt, f, m);
}
