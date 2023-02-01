#pragma once

// max(x+a,b) と表せる関数の合成
template <typename E>
struct Monoid_Add_Chmax {
  using value_type = pair<E, E>;
  using X = value_type;
  static X op(X x, X y) {
    auto [a, c] = x;
    auto [d, f] = y;
    a = a + d;
    c = (c == -INF<E> ? c : c + d);
    c = max(c, f);
    return {a, c};
  }

  static E eval(X f, E x) { return max(x + f.fi, f.se); }
  static X add(E a) { return {a, -INF<E>}; }
  static X chmax(E c) { return {0, c}; }

  static constexpr X unit() { return {0, -INF<E>}; }
  static constexpr bool commute = 0;
};