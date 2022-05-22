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
  static X unit() { return vc<mint>(K, mint(0)); }
  static constexpr bool commute = 1;
};