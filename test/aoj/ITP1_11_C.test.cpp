#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/dice.hpp"

void solve() {
  array<int, 6> A;
  FOR(i, 6) read(A[i]);
  Dice<int> X(A);
  auto dat = X.gen_all();
  array<int, 6> B;
  FOR(i, 6) read(B[i]);
  for (auto &&C: dat) {
    if (B == C) return Yes();
  }
  No();
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
