#pragma once
// 全体の個数、最小値、最小値の個数
template <ll INF>
struct Monoid_CntMinMincnt {
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xcnt, xmin, xmincnt] = x;
    auto [ycnt, ymin, ymincnt] = y;
    if (xmin > ymin) return {xcnt + ycnt, ymin, ymincnt};
    if (xmin == ymin) return {xcnt + ycnt, xmin, xmincnt + ymincnt};
    return {xcnt + ycnt, xmin, xmincnt};
  }
  static constexpr X unit() { return {0, INF, 0}; }
  static constexpr bool commute = true;
};