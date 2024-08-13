#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/cartesian_tree.hpp"

void solve() {
  LL(H, W);
  vi A(W);
  ll ANS = 0;
  FOR(i, H) {
    FOR(j, W) {
      LL(x);
      A[j] = (x == 0 ? A[j] + 1 : 0);
    }
    CartesianTree<ll, 1> CT(A);
    chmax(ANS, CT.max_rectangle_area());
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
