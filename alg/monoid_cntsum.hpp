struct Monoid_CntSum {
  static constexpr ll INF = 1LL << 60;
  using value_type = pi;
  using X = value_type;
  static X op(X x, X y) {
    auto [xc, xs] = x;
    auto [yc, ys] = y;
    return {xc + yc, xs + ys};
  }
  static constexpr X unit() { return {0, 0}; }
  static constexpr bool commute = true;
};
