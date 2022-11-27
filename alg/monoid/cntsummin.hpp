#pragma once

template <typename E>
struct Monoid_CntSumMin {
  using value_type = tuple<E, E, E>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xc, xs, xm] = x;
    auto [yc, ys, ym] = y;
    return {xc + yc, xs + ys, max(xm, ym)};
  }
  static X from_element(E x) { return {1, x, x}; }
  static constexpr X unit() { return {0, 0, numeric_limits<ll>::max()}; }
  static constexpr bool commute = true;
};
