#pragma once

template <typename X>
struct Monoid_Or {
  using value_type = X;
  static X op(X x, X y) { return x | y; }
  static constexpr X unit(){return X(0);};
  static constexpr bool commute = true;
};
