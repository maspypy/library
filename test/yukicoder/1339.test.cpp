#define PROBLEM "https://yukicoder.me/problems/no/1339"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/discrete_log.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/mul.hpp"

void solve() {
  LL(N);
  while (N % 2 == 0) N /= 2;
  while (N % 5 == 0) N /= 5;
  amint::set_mod(N);
  auto H = [&](amint x) -> ll { return x.val; };
  ll k = discrete_log<Monoid_Mul<amint>>(amint(10), amint(1), H, 1, N + 10);
  print(k);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
