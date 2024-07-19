#pragma once

#include "poly/convolution.hpp"
#include "poly/ntt_doubling.hpp"

template <typename T>
vc<T> convolution_all(vc<vc<T>>& polys) {
  if (len(polys) == 0) return {T(1)};
  while (1) {
    int n = len(polys);
    if (n == 1) break;
    int m = ceil(n, 2);
    FOR(i, m) {
      if (2 * i + 1 == n) {
        polys[i] = polys[2 * i];
      } else {
        polys[i] = convolution(polys[2 * i], polys[2 * i + 1]);
      }
    }
    polys.resize(m);
  }
  return polys[0];
}

// product of 1-A[i]x
template <typename mint>
vc<mint> convolution_all_1(vc<mint> A) {
  if (!mint::can_ntt()) {
    vvc<mint> polys;
    for (auto& a: A) polys.eb(vc<mint>({mint(1), -a}));
    return convolution_all(polys);
  }
  int D = 6;
  using poly = vc<mint>;
  int n = 1;
  while (n < len(A)) n *= 2;
  int k = topbit(n);
  vc<mint> F(n), nxt_F(n);
  FOR(i, len(A)) F[i] = -A[i];
  FOR(d, k) {
    int b = 1 << d;
    if (d < D) {
      fill(all(nxt_F), mint(0));
      for (int L = 0; L < n; L += 2 * b) {
        FOR(i, b) FOR(j, b) { nxt_F[L + i + j] += F[L + i] * F[L + b + j]; }
        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L + b + i];
      }
    }
    elif (d == D) {
      for (int L = 0; L < n; L += 2 * b) {
        poly f1 = {F.begin() + L, F.begin() + L + b};
        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};
        f1.resize(2 * b), f2.resize(2 * b), ntt(f1, 0), ntt(f2, 0);
        FOR(i, b) nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];
        FOR(i, b, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - f1[i] - f2[i];
      }
    }
    else {
      for (int L = 0; L < n; L += 2 * b) {
        poly f1 = {F.begin() + L, F.begin() + L + b};
        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};
        ntt_doubling(f1), ntt_doubling(f2);
        FOR(i, b) nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];
        FOR(i, b, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - f1[i] - f2[i];
      }
    }
    swap(F, nxt_F);
  }
  if (k - 1 >= D) ntt(F, 1);
  F.eb(1), reverse(all(F));
  F.resize(len(A) + 1);
  return F;
}