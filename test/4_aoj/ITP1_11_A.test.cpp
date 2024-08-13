#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/dice.hpp"

void solve() {
  array<int, 6> A;
  FOR(i, 6) read(A[i]);
  Dice<int> X(A);
  STR(S);
  for (auto&& s: S) { X.rotate(s); }
  print(X.U());
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
