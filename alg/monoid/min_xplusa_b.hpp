#pragma once

// min(x+a, b) の合成
template <typename T>
struct Monoid_Min_xplusa_b {
  using value_type = pair<T, T>;
  using X = value_type;
  static const T LIM = numeric_limits<T>::max();

  static X add(T x) { return {x, LIM}; }
  static X chmin(T x) { return {0, x}; }

  static T op_add(T x, T y) {
    if (x == LIM) return LIM;
    if (y == LIM) return LIM;
    return x + y;
  }
  static T eval(X f, T x) {
    auto [a, b] = f;
    return min(x + a, b);
  }

  static X op(X A, X B) {
    auto [a, b] = A;
    auto [c, d] = B;
    return {op_add(a, c), min(op_add(b, c), d)};
  }
  static constexpr X unit() { return {0, LIM}; }
  static constexpr bool commute = false;
};