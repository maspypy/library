#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/inversion.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll ANS = inversion<ll>(A);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
