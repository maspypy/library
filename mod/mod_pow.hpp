#pragma once
#include "mod/barrett.hpp"

int mod_pow(int a, ll n, int mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  Barrett bt(mod);
  int p = a, v = bt.modulo(1);
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}

ll mod_pow_64(ll a, ll n, ll mod) {
  assert(n >= 0);
  a = ((a %= mod) < 0 ? a + mod : a);
  Barrett bt(mod);
  ll p = a, v = bt.modulo(1);
  while (n) {
    if (n & 1) v = bt.mul(v, p);
    p = bt.mul(p, p);
    n >>= 1;
  }
  return v;
}
