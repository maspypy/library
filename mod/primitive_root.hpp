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

ll primitive_root_64(ll p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](ll g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  while (1) {
    ll x = RNG(1, p);
    if (is_ok(x)) return x;
  }
  return -1;
}

// https://codeforces.com/contest/1190/problem/F
ll primitive_root_prime_power_64(ll p, ll e) {
  assert(p >= 3);
  ll g = primitive_root_64(p);
  ll q = p;
  ll phi = p - 1;
  FOR(e - 1) {
    q *= p;
    phi *= p;
    if (mod_pow_64(g, phi / p, q) == 1) g += q / p;
  }
  return g;
}
