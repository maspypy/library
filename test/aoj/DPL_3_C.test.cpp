#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/cartesian_tree.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  CartesianTree<ll, 1> CT(A);
  print(CT.max_rectangle_area());
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
