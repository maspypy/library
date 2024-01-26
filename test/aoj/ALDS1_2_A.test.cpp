#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/inversion.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll x = inversion<ll>(A);
  sort(all(A));
  print(A);
  print(x);
}

signed main() {
  solve();
  return 0;
}
