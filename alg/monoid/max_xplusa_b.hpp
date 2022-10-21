#pragma once

// max(x+a, b) の合成
template <typename T>
struct Monoid_Max_xplusa_b {
  using value_type = pi;
  using X = value_type;
  static const T LIM = numeric_limits<T>::lowest();
  static T add(T x, T y) {
    if (x == LIM) return LIM;
    if (y == LIM) return LIM;
    return x + y;
  }
  static T eval(X f, T x) {
    auto [a, b] = f;
    return max(x + a, b);
  }

  static X op(X A, X B) {
    auto [a, b] = A;
    auto [c, d] = B;
    return {add(a, c), max(add(b, c), d)};
  }
  static constexpr X unit() { return {0, LIM}; }
  static constexpr bool commute = false;
};