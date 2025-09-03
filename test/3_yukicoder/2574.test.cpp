#define PROBLEM "https://yukicoder.me/problems/no/2574"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/cartesian_tree.hpp"

void solve() {
  LL(H, W, N);
  vv(int, A, H, W, 1);
  FOR(N) {
    INT(x, y);
    A[--x][--y] = 0;
  }
  ll ANS = 0;
  vc<int> Y(W);
  FOR(i, H) {
    FOR(j, W) Y[j] = (A[i][j] ? Y[j] + 1 : 0);
    CartesianTree<int, true> CT(Y);
    FOR(i, W) {
      auto [l, r] = CT.range[i];
      ANS += ll(r - i) * (i - l + 1) * Y[i];
    }
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
