#pragma once

template <typename X>
struct Monoid_Gcd {
  using value_type = X;
  static X op(X x, X y) { return gcd(x, y); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};
