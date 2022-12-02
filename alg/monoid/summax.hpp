#pragma once

template <typename E>
struct Monoid_SumMax {
  using value_type = pair<E, E>;
  using X = value_type;
  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }
  static X from_element(E e) { return {e, e}; }
  static constexpr X unit() { return {E(0), numeric_limits<E>::max()}; }
  static constexpr bool commute = 1;
};