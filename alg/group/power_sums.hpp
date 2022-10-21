#pragma once

// 0 乗和から K-1 乗和まで
template <typename mint, int K>
struct Group_power_sums {
  using value_type = vc<mint>;
  using X = value_type;
  static X op(X x, X y) {
    vc<mint> z(K);
    FOR(i, K) z[i] = x[i] + y[i];
    return z;
  }
  static X from_element(mint x) {
    vc<mint> a(K);
    a[0] = 1;
    FOR(i, K - 1) a[i + 1] = a[i] * x;
  }
  static X unit() { return vc<mint>(K, mint(0)); }
  static constexpr bool commute = 1;
};
