template <class X, X INF>
struct Monoid_MinMax {
  using P = pair<X, X>;
  using value_type = P;
  static constexpr P op(const P x, const P y) noexcept {
    return {min(x.fi, y.fi), max(x.se, y.se)};
  }
  static constexpr P unit() { return {INF, -INF}; }
  static constexpr bool commute = true;
};
