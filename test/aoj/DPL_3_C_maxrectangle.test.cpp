#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/cartesian_tree.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  CartesianTree<ll> CT(A);
  ll ANS = 0;
  FOR(i, N) {
    auto [l, r] = CT.range[i];
    chmax(ANS, A[i] * (r - l));
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
