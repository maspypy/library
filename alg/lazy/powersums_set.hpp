#pragma once

#include "alg/monoid/set.hpp"
#include "alg/monoid/power_sums.hpp"

template <typename mint, int K>
struct Lazy_Power_Sums_Set {
  using MX = Group_power_sums<mint, K>;
  using MA = Monoid_Set<int, -1>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static X act(const X &x, const A &b) {
    if (b == -1) return x;
    mint a = b;
    vc<mint> y(K);
    vc<mint> pow(K);
    pow[0] = mint(1);
    FOR(k, K - 1) pow[k + 1] = pow[k] * a;
    FOR(i, 5) y[i] = x[0] * pow[i];
    return y;
  }
};
