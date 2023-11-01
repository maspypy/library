#pragma once
#include "mod/dynamic_modint.hpp"
#include "mod/dynamic_modint_64.hpp"
#include "mod/mongomery_modint.hpp"

u32 mod_pow(int a, ll n, int mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (1 << 30))) {
    using mint = Mongomery_modint_32<202311021>;
    mint::set_mod(mod);
    return mint(a).pow(n).val();
  }
  using mint = Dynamic_Modint<202311022>;
  return mint(a).pow(n).val;
}

u64 mod_pow_64(ll a, ll n, u64 mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  if ((mod & 1) && (mod < (1 << 30))) {
    using mint = Mongomery_modint_64<202311023>;
    mint::set_mod(mod);
    return mint(a).pow(n).val();
  }
  using mint = Dynamic_Modint_64<202311024>;
  return mint(a).pow(n).val;
}