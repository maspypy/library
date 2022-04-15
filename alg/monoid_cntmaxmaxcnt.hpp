#pragma once
// 全体の個数、最大値、最大値の個数
template <ll INF>
struct Monoid_CntMaxMaxcnt {
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xcnt, xmax, xmaxcnt] = x;
    auto [ycnt, ymax, ymaxcnt] = y;
    if (xmax < ymax) return {xcnt + ycnt, ymax, ymaxcnt};
    if (xmax == ymax) return {xcnt + ycnt, xmax, xmaxcnt + ymaxcnt};
    return {xcnt + ycnt, xmax, xmaxcnt};
  }
  static constexpr X unit() { return {0, -INF, 0}; }
  static constexpr bool commute = true;
};