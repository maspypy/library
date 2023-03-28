#include "mod/dynamic_modint.hpp"
#include "nt/discrete_log.hpp"
#include "alg/monoid/mul.hpp"

int mod_log(int mod, ll a, ll b) {
  dmint::set_mod(mod);
  return discrete_log_monoid<Monoid_Mul<dmint>>(
      dmint(a), dmint(b), [](auto x) { return x.val; }, 0, mod);
}
