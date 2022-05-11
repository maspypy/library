#pragma once
#include "mod/mod_pow.hpp"
#include "nt/factor.hpp"
template <typename INT>
ll LCM(vc<INT> vals, int mod = -1) {
  if (mod == -1) {
    ll x = 1;
    for (auto&& v: vals) { x = x / gcd(x, v) * v; }
    return x;
  }
  unordered_map<ll, ll> pf;
  for (auto&& x: vals) {
    for (auto&& [p, e]: factor(x)) { chmax(pf[p], e); }
  }
  ll x = 1;
  for (auto&& [p, e]: pf) { x = x * mod_pow(p, e, mod) % mod; }
  return x;
}
