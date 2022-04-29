#define PROBLEM "https://yukicoder.me/problems/no/4"
#include "my_template.hpp"
#include "other/io.hpp"
#include "dp/subset_sum.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  ll S = SUM(A);
  auto I = subset_sum(A, S / 2);
  bool can = (S == 0 || len(I) > 0);
  if (can && S % 2 == 0) {
    print("possible");
  } else {
    print("impossible");
  }
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
