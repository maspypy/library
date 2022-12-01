#pragma once

#include "random/base.hpp"
#include "mod/modint61.hpp"

// pow of base, val
struct Monoid_Rolling_Hash {
  using value_type = pair<modint61, modint61>;
  using X = value_type;

  static u64 &get_param() {
    static u64 base = 0;
    return base;
  }
  static void set_param(u64 base) { get_param() = base; }

  static X from_element(u64 x) {
    while (get_param() == 0) set_param(RNG_64());
    return {get_param(), x};
  }
  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }
  static constexpr X unit() { return {1, 0}; }
  static constexpr bool commute = false;
};