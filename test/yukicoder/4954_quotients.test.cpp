#define PROBLEM "https://yukicoder.me/problems/4954"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/floor_range.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  floor_range(q, l, r, N)++ ANS;
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
