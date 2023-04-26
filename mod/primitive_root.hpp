#pragma once

#include "nt/factor.hpp"
#include "mod/mod_pow.hpp"
#include "random/base.hpp"

// int
int primitive_root(int p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](int g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    int x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}

ll primitive_root_long(ll p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](ll g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    ll x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}
