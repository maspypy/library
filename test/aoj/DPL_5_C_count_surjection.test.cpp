#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "setfunc/count_surjection.hpp"

using mint = modint107;

void solve() {
  LL(N, K);
  print(count_surjection<mint>(N, K));
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
