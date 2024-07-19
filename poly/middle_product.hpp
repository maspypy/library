#pragma once

#include "poly/ntt.hpp"
#include "mod/crt3.hpp"
#include "mod/modint.hpp"

// n, m 次多項式 (n>=m) a, b → n-m 次多項式 c
// c[i] = sum_j b[j]a[i+j]
template <typename mint>
vc<mint> middle_product(vc<mint>& a, vc<mint>& b) {
  assert(len(a) >= len(b));
  if (b.empty()) return vc<mint>(len(a) - len(b) + 1);
  if (min(len(b), len(a) - len(b) + 1) <= 60) {
    return middle_product_naive(a, b);
  }
  if (!(mint::can_ntt())) {
    return middle_product_garner(a, b);
  } else {
    int n = 1 << __lg(2 * len(a) - 1);
    vc<mint> fa(n), fb(n);
    copy(a.begin(), a.end(), fa.begin());
    copy(b.rbegin(), b.rend(), fb.begin());
    ntt(fa, 0), ntt(fb, 0);
    FOR(i, n) fa[i] *= fb[i];
    ntt(fa, 1);
    fa.resize(len(a));
    fa.erase(fa.begin(), fa.begin() + len(b) - 1);
    return fa;
  }
}

template <typename mint>
vc<mint> middle_product_garner(vc<mint>& a, vc<mint> b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  static constexpr int p0 = 167772161;
  static constexpr int p1 = 469762049;
  static constexpr int p2 = 754974721;
  using mint0 = modint<p0>;
  using mint1 = modint<p1>;
  using mint2 = modint<p2>;
  vc<mint0> a0(n), b0(m);
  vc<mint1> a1(n), b1(m);
  vc<mint2> a2(n), b2(m);
  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;
  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;
  auto c0 = middle_product<mint0>(a0, b0);
  auto c1 = middle_product<mint1>(a1, b1);
  auto c2 = middle_product<mint2>(a2, b2);
  vc<mint> c(len(c0));
  FOR(i, n - m + 1) {
    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);
  }
  return c;
}

template <typename mint>
vc<mint> middle_product_naive(vc<mint>& a, vc<mint>& b) {
  vc<mint> res(len(a) - len(b) + 1);
  FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];
  return res;
}