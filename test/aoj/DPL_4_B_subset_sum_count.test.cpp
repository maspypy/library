#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/subset_sum_count.hpp"

void solve() {
  LL(N, K, L, R);
  VEC(ll, A, N);
  print(subset_sum_count_by_size(A, L, R + 1)[K]);
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
