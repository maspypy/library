#pragma once

template <typename E>
struct Monoid_SumMin {
  using value_type = pair<E, E>;
  using X = value_type;
  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }
  static X from_element(E x) { return {x, x}; }
  static constexpr X unit() { return {E(0), INF<E>}; }
  static constexpr bool commute = true;
};
