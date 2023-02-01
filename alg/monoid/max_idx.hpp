#pragma once

template <typename T, bool tie_is_left = true>
struct Monoid_Max_Idx {
  using value_type = pair<T, int>;
  using X = value_type;
  static X op(X x, X y) {
    if (x.fi > y.fi) return x;
    if (x.fi < y.fi) return y;
    if (x.se > y.se) swap(x, y);
    return (tie_is_left ? x : y);
  }
  static constexpr X unit() { return {-INF, -1}; }
  static constexpr bool commute = true;
};
