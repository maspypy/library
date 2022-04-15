#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primetest.hpp"

void solve() {
  ll ANS = 0;
  LL(N);
  FOR_(N) {
    LL(p);
    ANS += primetest(p);
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  FOR(_, T) solve();

  return 0;
}
