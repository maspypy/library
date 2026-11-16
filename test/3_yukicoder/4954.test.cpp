#define PROBLEM "https://yukicoder.me/problems/4954"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/floor_range.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  auto f = [&](ll q, ll l, ll r, bool) -> void { ++ANS; };
  floor_range(N, f);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
