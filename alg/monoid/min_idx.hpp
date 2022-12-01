#pragma once

template <typename T, bool tie_is_left = true>
struct Monoid_Min_Idx {
  using value_type = pair<T, int>;
  using X = value_type;
  static constexpr bool is_small(const X& x, const X& y) {
    if (x.fi < y.fi) return true;
    if (x.fi > y.fi) return false;
    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));
  }
  static X op(X x, X y) { return (is_small(x, y) ? x : y); }
  static constexpr X unit() { return {numeric_limits<T>::max(), -1}; }
  static constexpr bool commute = true;
};
