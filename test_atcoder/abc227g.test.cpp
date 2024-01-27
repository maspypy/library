#define PROBLEM "https://atcoder.jp/contests/abc227/tasks/abc227_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/hashmap.hpp"
#include "mod/modint.hpp"

#include "nt/factor_interval.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  HashMap<int> MP;
  factor_interval(1, K + 1, [&](int i, ll p) -> void { MP[p]--; });
  factor_interval(N - K + 1, N + 1, [&](int i, ll p) -> void { MP[p]++; });
  mint ANS = 1;
  MP.enumerate_all([&](ll p, int k) -> void { ANS *= mint(1 + k); });
  print(ANS);
}

signed main() {
  solve();
  return 0;
}