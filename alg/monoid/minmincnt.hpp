#pragma once

// 最小値、最小値の個数
template <typename E>
struct Monoid_MinMincnt {
  using value_type = pair<E, E>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xmin, xmincnt] = x;
    auto [ymin, ymincnt] = y;
    if (xmin > ymin) return {ymin, ymincnt};
    if (xmin == ymin) return {xmin, xmincnt + ymincnt};
    return {xmin, xmincnt};
  }
  static constexpr X unit() { return {infty<E>, 0}; }
  static constexpr bool commute = true;
};