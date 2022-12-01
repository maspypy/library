#define PROBLEM "https://yukicoder.me/problems/no/2012"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/func/cht.hpp"

void solve() {
  LL(N);
  CHT_xy<ll> cht;
  VEC(pi, XY, N);
  ll ANS = 0;
  for (auto&& [a, b]: XY) cht.add(a, -b);
  for (auto&& [x, y]: XY) { chmax(ANS, cht.get_max(y, x)); }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
