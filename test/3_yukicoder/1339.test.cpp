#define PROBLEM "https://yukicoder.me/problems/no/1339"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/discrete_log.hpp"
#include "mod/dynamic_modint.hpp"
#include "alg/monoid/mul.hpp"

void solve() {
  LL(N);
  while (N % 2 == 0) N /= 2;
  while (N % 5 == 0) N /= 5;
  dmint::set_mod(N);
  auto H = [&](dmint x) -> ll { return x.val; };
  ll k = discrete_log_monoid<Monoid_Mul<dmint>>(dmint(10), dmint(1), H, 1, N + 10);
  print(k);
}

signed main() {
  LL(T);
  FOR(T) solve();

  return 0;
}
