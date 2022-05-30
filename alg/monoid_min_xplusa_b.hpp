#pragma once

// max(x+a, b) の合成
template <typename T>
struct Monoid_Min_xplusa_b {
  using value_type = pi;
  using X = value_type;
  static constexpr T apply(const X& a, T& x){
    return min(x + a.fi, a.se);
  }
  static constexpr T add(const T& x, const T& y) {
    if (x == numeric_limits<T>::max()) return x;
    if (y == numeric_limits<T>::max()) return y;
    return x + y;
  }
  static constexpr X op(const X& A, const X& B) {
    auto& [a, b] = A;
    auto& [c, d] = B;
    return {add(a, c), min(add(b, c), d)};
  }
  static constexpr X unit() { return {0, numeric_limits<T>::lowest()}; }
  static constexpr bool commute = false;
};