#pragma once
#include "mod/modint61.hpp"

struct Monoid_Rolling_Hash {
  using value_type = pair<modint61, modint61>; // pow of base, val
  using X = value_type;
  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }
  static constexpr X unit() { return {1, 0}; }
  static constexpr bool commute = false;
};