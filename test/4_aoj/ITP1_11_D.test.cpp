#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/dice.hpp"

void solve() {
  LL(N);
  using ARR = typename Dice<int>::ARR;
  set<ARR> ss;
  FOR(N) {
    array<int, 6> A;
    FOR(i, 6) read(A[i]);
    Dice<int> X(A);
    auto dat = X.gen_all();
    A = MIN(dat);
    ss.insert(A);
  }
  Yes(len(ss) == N);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
