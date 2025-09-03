#define PROBLEM "https://yukicoder.me/problems/no/2320"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/binary_optimization.hpp"

void solve() {
  LL(N, S, T);

  vc<int> state(N, -1);
  FOR(S) {
    INT(x);
    --x;
    state[x] = 0;
  }
  FOR(T) {
    INT(x);
    --x;
    state[x] = 1;
  }

  Binary_Optimization<i128, false> X(N);
  FOR(i, N) {
    if (state[i] == 0) X.add_1(i, 0, -infty<ll>);
    if (state[i] == 1) X.add_1(i, -infty<ll>, 0);
  }
  FOR(i, N) FOR(j, N) {
    INT(x);
    if (i >= j) continue;
    X.add_2(i, j, x, 0, 0, x);
  }

  auto [val, x] = X.calc();
  print(val);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
