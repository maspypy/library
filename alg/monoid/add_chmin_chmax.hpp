#pragma once

// max(min(x+a,b),c) と表せる関数の合成
template <typename E>
struct Monoid_Add_Chmin_Chmax {
  using value_type = tuple<E, E, E>;
  using X = value_type;

  static X op(X x, X y) {
    auto [a, b, c] = x;
    auto [d, e, f] = y;
    a = a + d;
    b = (b == infty<E> ? b : b + d);
    c = (c == -infty<E> ? c : c + d);
    b = min(b, e);
    c = max(min(c, e), f);
    return {a, b, c};
  }

  static E eval(X f, E x) {
    auto [a, b, c] = f;
    return max(min(x + a, b), c);
  }

  static X add(E a) { return {a, infty<E>, -infty<E>}; }
  static X chmin(E b) { return {0, b, -infty<E>}; }
  static X chmax(E c) { return {0, infty<E>, c}; }

  static constexpr X unit() { return {0, infty<E>, -infty<E>}; }
  static constexpr bool commute = 0;
};