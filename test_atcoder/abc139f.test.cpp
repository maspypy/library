#define PROBLEM "https://atcoder.jp/contests/abc139/tasks/abc139_f"
#define ERROR 1e-10

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/max_norm_sum.hpp"

using P = Point<ll>;

void solve() {
  LL(N);
  VEC(P, point, N);
  auto [val, I] = max_norm_sum<ll, ll>(point);
  ll x = 0, y = 0;
  for (auto&& i: I) x += point[i].x, y += point[i].y;
  assert(val == x * x + y * y);
  double ANS = sqrtl(val);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}