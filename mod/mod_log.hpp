#include "mod/modint.hpp"
#include "nt/discrete_log.hpp"
#include "alg/monoid/mul.hpp"

int mod_log(int mod, ll a, ll b) {
  a = divmod(a, mod).se;
  b = divmod(b, mod).se;
  // まず群に帰着する。小さい場合は調べる
  ll p = 1 % mod;
  FOR(k, 32) {
    if (p == b) return k;
    p = p * a % mod;
  }
  if (a == 0 || b == 0) return -1;
  ll g = gcd(mod, p);
  if (b % g != 0) return -1;
  mod /= g;
  a %= mod, b %= mod;
  if (gcd(b, mod) > 1) return -1;
  // 群に帰着された
  amint::set_mod(mod);
  return discrete_log_group<Monoid_Mul<amint>>(
      amint(a), amint(b), [](auto x) { return x.val; }, 32, mod);
}
