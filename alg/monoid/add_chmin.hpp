#pragma once

// min(x+a,b) と表せる関数の合成
template <typename E>
struct Monoid_Add_Chmin {
  using value_type = pair<E, E>;
  using X = value_type;

  static X op(X x, X y) {
    auto [a, b] = x;
    auto [d, e] = y;
    a = a + d;
    b = (b == infty<E> ? b : b + d);
    b = min(b, e);
    return {a, b};
  }

  static E eval(X f, E x) { return min(x + f.fi, f.se); }

  static X add(E a) { return {a, infty<E>}; }
  static X chmin(E b) { return {0, b}; }

  static constexpr X unit() { return {0, infty<E>}; }
  static constexpr bool commute = 0;
};