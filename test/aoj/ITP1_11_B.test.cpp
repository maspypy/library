#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_B"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/dice.hpp"

void solve() {
  array<int, 6> A;
  FOR(i, 6) read(A[i]);
  Dice<int> X(A);
  auto dat = X.gen_all();
  LL(Q);
  FOR(Q) {
    LL(a, b);
    for (auto&& B: dat) {
      if (B[0] == a && B[1] == b) print(B[2]);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
