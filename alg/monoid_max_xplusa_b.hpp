#pragma once

// max(x+a, b) の合成
template <typename T, T INF>
struct Monoid_Max_xplusa_b {
  using value_type = pi;
  using X = value_type;
  static X op(X A, X B) {
    auto [a, b] = A;
    auto [c, d] = B;
    ll e = a + c, f = max(b + c, d);
    chmax(e, -INF);
    chmax(f, -INF);
    return {e, f};
  }
  static constexpr X unit() { return {0, -INF}; }
  static constexpr bool commute = false;
};