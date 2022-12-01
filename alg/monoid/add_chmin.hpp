#pragma once

// min(x+a,b) と表せる関数の合成
template <typename E>
struct Monoid_Add_Chmin {
  using value_type = pair<E, E>;
  using X = value_type;
  static constexpr E R_INF = numeric_limits<E>::max();

  static X op(X x, X y) {
    auto [a, b] = x;
    auto [d, e] = y;
    a = a + d;
    b = (b == R_INF ? b : b + d);
    b = min(b, e);
    return {a, b};
  }

  static E eval(X f, E x) { return min(x + f.fi, f.se); }

  static X add(E a) { return {a, R_INF}; }
  static X chmin(E b) { return {0, b}; }

  static constexpr X unit() { return {0, R_INF}; }
  static constexpr bool commute = 0;
};