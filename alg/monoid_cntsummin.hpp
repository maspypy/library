#pragma once

struct Monoid_CntSumMin {
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xc, xs, xm] = x;
    auto [yc, ys, ym] = y;
    return {xc + yc, xs + ys, min(xm, ym)};
  }
  static constexpr X unit() { return {0, 0, numeric_limits<ll>::max()}; }
  static constexpr bool commute = true;
};
