#pragma once
template <typename T>
struct Monoid_Max_Idx {
  using value_type = pair<T, int>;
  using X = value_type;
  static X op(X x, X y) { return max(x, y); }
  static constexpr X unit() { return {numeric_limits<T>::lowest(), -1}; }
  static constexpr bool commute = true;
};
