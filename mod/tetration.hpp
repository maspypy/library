#include "mod/fast_div.hpp"
#include "nt/euler_phi.hpp"

int tetration(vc<ll> a, int mod) {
  for (auto&& x: a) assert(x > 0);

  // a[0]^(a[1]^(a[2]^...))
  vc<int> mod_chain = {mod};
  while (mod_chain.back() > 1) mod_chain.eb(euler_phi(mod_chain.back()));
  while (len(a) > len(mod_chain)) a.pop_back();
  while (len(mod_chain) > len(a)) mod_chain.pop_back();

  auto pow = [&](ll x, int n, int mod) -> int {
    fast_div fd(mod);
    if (x >= mod) x = x % fd + mod;
    ll v = 1;
    do {
      if (n & 1) {
        v *= x;
        if (v >= mod) v = v % fd + mod;
      }
      x *= x;
      if (x >= mod) x = x % fd + mod;
      n /= 2;
    } while (n);
    return v;
  };

  int v = 1;
  FOR_R(i, len(a)) v = pow(a[i], v, mod_chain[i]);
  return v % mod;
}
