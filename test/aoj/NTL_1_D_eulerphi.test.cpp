#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/euler_phi.hpp"

void solve() {
  LL(N);
  print(euler_phi(N));
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
