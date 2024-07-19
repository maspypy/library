#pragma once

#include "poly/convolution.hpp"
#include "poly/ntt_doubling.hpp"

// 有理式の和を計算する。分割統治 O(Nlog^2N)。N は次数の和。
template <typename mint>
pair<vc<mint>, vc<mint>> sum_of_rationals(vc<pair<vc<mint>, vc<mint>>> dat) {
  if (len(dat) == 0) {
    vc<mint> f = {0}, g = {1};
    return {f, g};
  }
  using P = pair<vc<mint>, vc<mint>>;
  auto add = [&](P& a, P& b) -> P {
    int na = len(a.fi) - 1, da = len(a.se) - 1;
    int nb = len(b.fi) - 1, db = len(b.se) - 1;
    int n = max(na + db, da + nb);
    vc<mint> num(n + 1);
    {
      auto f = convolution(a.fi, b.se);
      FOR(i, len(f)) num[i] += f[i];
    }
    {
      auto f = convolution(a.se, b.fi);
      FOR(i, len(f)) num[i] += f[i];
    }
    auto den = convolution(a.se, b.se);
    return {num, den};
  };

  while (len(dat) > 1) {
    int n = len(dat);
    FOR(i, 1, n, 2) { dat[i - 1] = add(dat[i - 1], dat[i]); }
    FOR(i, ceil(n, 2)) dat[i] = dat[2 * i];
    dat.resize(ceil(n, 2));
  }
  return dat[0];
}

// sum wt[i]/(1-A[i]x)
template <typename mint>
pair<vc<mint>, vc<mint>> sum_of_rationals_1(vc<mint> A, vc<mint> wt) {
  using poly = vc<mint>;
  if (!mint::can_ntt()) {
    vc<pair<poly, poly>> rationals;
    FOR(i, len(A)) rationals.eb(poly({wt[i]}), poly({mint(1), -A[i]}));
    return sum_of_rationals(rationals);
  }
  int n = 1;
  while (n < len(A)) n *= 2;
  int k = topbit(n);
  vc<mint> F(n), G(n);
  vc<mint> nxt_F(n), nxt_G(n);
  FOR(i, len(A)) F[i] = -A[i], G[i] = wt[i];
  int D = 6;

  FOR(d, k) {
    int b = 1 << d;
    if (d < D) {
      fill(all(nxt_F), mint(0)), fill(all(nxt_G), mint(0));
      for (int L = 0; L < n; L += 2 * b) {
        FOR(i, b) FOR(j, b) nxt_F[L + i + j] += F[L + i] * F[L + b + j];
        FOR(i, b) FOR(j, b) nxt_G[L + i + j] += F[L + i] * G[L + b + j];
        FOR(i, b) FOR(j, b) nxt_G[L + i + j] += F[L + b + i] * G[L + j];
        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L + b + i];
        FOR(i, b) nxt_G[L + b + i] += G[L + i] + G[L + b + i];
      }
    }
    elif (d == D) {
      for (int L = 0; L < n; L += 2 * b) {
        poly f1 = {F.begin() + L, F.begin() + L + b};
        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};
        poly g1 = {G.begin() + L, G.begin() + L + b};
        poly g2 = {G.begin() + L + b, G.begin() + L + 2 * b};
        f1.resize(2 * b), f2.resize(2 * b), g1.resize(2 * b), g2.resize(2 * b);
        ntt(f1, 0), ntt(f2, 0), ntt(g1, 0), ntt(g2, 0);
        FOR(i, b) f1[i] += 1, f2[i] += 1;
        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;
        FOR(i, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - 1;
        FOR(i, 2 * b) nxt_G[L + i] = g1[i] * f2[i] + g2[i] * f1[i];
      }
    }
    else {
      for (int L = 0; L < n; L += 2 * b) {
        poly f1 = {F.begin() + L, F.begin() + L + b};
        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};
        poly g1 = {G.begin() + L, G.begin() + L + b};
        poly g2 = {G.begin() + L + b, G.begin() + L + 2 * b};
        ntt_doubling(f1), ntt_doubling(f2), ntt_doubling(g1), ntt_doubling(g2);
        FOR(i, b) f1[i] += 1, f2[i] += 1;
        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;
        FOR(i, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - 1;
        FOR(i, 2 * b) nxt_G[L + i] = g1[i] * f2[i] + g2[i] * f1[i];
      }
    }
    swap(F, nxt_F), swap(G, nxt_G);
  }
  if (k - 1 >= D) ntt(F, 1), ntt(G, 1);
  F.eb(1);
  reverse(all(F)), reverse(all(G));
  F.resize(len(A) + 1);
  G.resize(len(A));
  return {G, F};
}
