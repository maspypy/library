#define PROBLEM "https://yukicoder.me/problems/no/2012"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/cht.hpp"

void solve() {
  LL(N);
  CHT_xy<ll> cht;
  VEC(pi, XY, N);
  ll ANS = 0;
  for (auto&& [a, b]: XY) cht.add(a, -b);
  for (auto&& [x, y]: XY) { chmax(ANS, cht.get_max(y, x).fi); }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
