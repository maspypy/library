#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/floor_range.hpp"

void solve() {
  LL(N);
  vi ANS;
  2 * sqrt(N) + 10;
  ANS.reserve(2 * sqrt(N) + 10);
  floor_range(N, [&](ll q, ll l, ll r) -> void { ANS.eb(q); });
  print(len(ANS));
  print(ANS);
}

signed main() {
  solve();
  return 0;
}