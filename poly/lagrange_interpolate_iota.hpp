#pragma once
#include "alg/monoid/mul.hpp"
#include "ds/sliding_window_aggregation.hpp"
#include "poly/convolution.hpp"

// Input: f(0), ..., f(n-1) and c, m
// Return: f(c), f(c+1), ..., f(c+m-1)
// Complexity: M(n, n + m)
template <typename mint>
vc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {
  if (m <= 60) {
    vc<mint> ANS(m);
    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f, c + mint(i));
    return ANS;
  }
  ll n = len(f);
  auto a = f;
  FOR(i, n) {
    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);
    if ((n - 1 - i) & 1) a[i] = -a[i];
  }
  // x = c, c+1, ... に対して a0/x + a1/(x-1) + ... を求めておく
  vc<mint> b(n + m - 1);
  FOR(i, n + m - 1) b[i] = mint(1) / (c + mint(i - n + 1));
  a = convolution(a, b);

  Sliding_Window_Aggregation<Monoid_Mul<mint>> swag;
  vc<mint> ANS(m);
  ll L = 0, R = 0;
  FOR(i, m) {
    while (L < i) { swag.pop(), ++L; }
    while (R - L < n) { swag.push(c + mint((R++) - n + 1)); }
    auto coef = swag.prod();
    if (coef == 0) {
      ANS[i] = f[(c + i).val];
    } else {
      ANS[i] = a[i + n - 1] * coef;
    }
  }
  return ANS;
}

// Input: f(0), ..., f(n-1) and c
// Return: f(c)
// Complexity: O(n)
template <typename mint>
mint lagrange_interpolate_iota(vc<mint> &f, mint c) {
  int n = len(f);
  if (int(c.val) < n) return f[c.val];
  auto a = f;
  FOR(i, n) {
    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);
    if ((n - 1 - i) & 1) a[i] = -a[i];
  }
  vc<mint> lp(n + 1), rp(n + 1);
  lp[0] = rp[n] = 1;
  FOR(i, n) lp[i + 1] = lp[i] * (c - i);
  FOR_R(i, n) rp[i] = rp[i + 1] * (c - i);
  mint ANS = 0;
  FOR(i, n) ANS += a[i] * lp[i] * rp[i + 1];
  return ANS;
}
