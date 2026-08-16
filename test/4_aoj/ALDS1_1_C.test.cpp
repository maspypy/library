#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/is_prime.hpp"

void solve() {
  ll ANS = 0;
  LL(N);
  FOR(N) {
    LL(p);
    ANS += is_prime(p);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
