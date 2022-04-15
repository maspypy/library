#include "mod/fast_div.hpp"
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
