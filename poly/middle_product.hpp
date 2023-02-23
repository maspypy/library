#pragma once

#include "poly/ntt.hpp"

// n, m 次多項式 (n>=m) a, b → n-m 次多項式 c
// c[i] = sum_j b[j]a[i+j]
template <typename mint>
vc<mint> middle_product(vc<mint>& a, vc<mint>& b) {
  assert(len(a) >= len(b));
  if (b.empty()) return vc<mint>(len(a) - len(b) + 1);
  if constexpr (mint::ntt_info().fi == -1) {
    return middle_product_naive(a, b);
  } else {
    if (min(len(b), len(a) - len(b) + 1) <= 60) {
      return middle_product_naive(a, b);
    }
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
vc<mint> middle_product_naive(vc<mint>& a, vc<mint>& b) {
  vc<mint> res(len(a) - len(b) + 1);
  FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];
  return res;
}