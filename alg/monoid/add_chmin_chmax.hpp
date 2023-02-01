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
    b = (b == R_INF ? b : b + d);
    c = (c == L_INF ? c : c + d);
    b = min(b, e);
    c = max(min(c, e), f);
    return {a, b, c};
  }

  static E eval(X f, E x) {
    auto [a, b, c] = f;
    return max(min(x + a, b), c);
  }

  static X add(E a) { return {a, INF<E>, -INF<E>}; }
  static X chmin(E b) { return {0, b, -INF<E>}; }
  static X chmax(E c) { return {0, INF<E>, c}; }

  static constexpr X unit() { return {0, INF<E>, -INF<E>}; }
  static constexpr bool commute = 0;
};