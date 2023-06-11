#pragma once
#include "mod/barrett.hpp"

// int
ll mod_pow(ll a, ll n, int mod) {
  assert(n >= 0);
  a %= mod;
  if (a < 0) a += mod;
  Barrett bt(mod);
  ll p = a, v = bt.modulo(1);
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}

ll mod_pow_long(ll a, ll n, ll mod) {
  assert(n >= 0);
  a %= mod;
  if (a < 0) a += mod;
  ll p = a, v = 1 % mod;
  while (n) {
    if (n & 1) v = i128(v) * p % mod;
    p = i128(p) * p % mod;
    n >>= 1;
  }
  return v;
}
