#pragma once
#include "mod/barrett.hpp"

// int
ll mod_pow(ll a, ll n, int mod) {
  a %= mod;
  Barrett bt(mod);
  ll p = a;
  ll v = 1;
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}

ll mod_pow_long(ll a, ll n, ll mod) {
  a %= mod;
  ll p = a;
  ll v = 1;
  while (n) {
    if (n & 1) v = i128(v) * p % mod;
    p = i128(p) * p % mod;
    n >>= 1;
  }
  return v;
}
