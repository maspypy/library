#pragma once

template <class X>
struct Monoid_MinMax {
  using P = pair<X, X>;
  using value_type = P;
  static constexpr P op(const P x, const P y) noexcept {
    return {min(x.fi, y.fi), max(x.se, y.se)};
  }
  static constexpr P from_element(const X x) { return {x, x}; }
  static constexpr P unit() { return {infty<X>, -infty<X>}; }
  static constexpr bool commute = true;
};
