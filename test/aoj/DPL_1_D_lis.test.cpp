#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "dp/longest_increasing_subsequence.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto dp = longest_increasing_subsequence(A);
  print(MAX(dp));
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
