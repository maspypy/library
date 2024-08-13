#define PROBLEM "https://yukicoder.me/problems/no/2181"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/binomial.hpp"

void solve() {
  LL(L, R, mod);
  Binomial X(mod);
  ll ANS = 0;
  FOR(n, L, R + 1) ANS += X.C(n + n, n) - 2;
  ANS %= mod;
  if (ANS < 0) ANS += mod;
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
