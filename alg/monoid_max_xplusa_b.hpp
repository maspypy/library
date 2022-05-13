#pragma once

// max(x+a, b) の合成
template <typename T>
struct Monoid_Max_xplusa_b {
  using value_type = pi;
  using X = value_type;
  static T add(T x, T y) {
    if (x == numeric_limits<T>::lowest()) return x;
    if (y == numeric_limits<T>::lowest()) return y;
    return x + y;
  }
  static X op(X A, X B) {
    auto [a, b] = A;
    auto [c, d] = B;
    return {add(a, c), max(add(b, c), d)};
  }
  static constexpr X unit() { return {0, numeric_limits<T>::lowest()}; }
  static constexpr bool commute = false;
};