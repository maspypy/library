#pragma once

// 最小値、最小値の個数
template <typename E>
struct Monoid_MinMincnt {
  using value_type = tuple<E, E, E>;
  using X = value_type;
  static X from_element(E x) { return {x, 1}; }
  static X op(X x, X y) {
    auto [xmin, xmincnt] = x;
    auto [ymin, ymincnt] = y;
    if (xmin > ymin) return {ymin, ymincnt};
    if (xmin == ymin) return {xmin, xmincnt + ymincnt};
    return {xmin, xmincnt};
  }
  static constexpr X unit() { return {numeric_limits<E>::max(), 0}; }
  static constexpr bool commute = true;
};