#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/extgcd.hpp"

void solve() {
  LL(a, b);
  auto [x, y, d] = extgcd(a, b);
  print(x, y);
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
