#include "mod/fast_div.hpp"
// int
ll mod_pow(ll a, ll n, int mod){
  fast_div fd(mod);
  a = a % fd;
  ll p = a;
  ll v = 1;
  while(n){
    if(n & 1) v = v * p % fd;
    p = p * p % fd;
    n >>= 1;
  }
  return v;
}

ll mod_pow_long(ll a, ll n, ll mod){
  a %= mod;
  ll p = a;
  ll v = 1;
  while(n){
    if(n & 1) v = i128(v) * p % mod;
    p = i128(p) * p % mod;
    n >>= 1;
  }
  return v;
}
