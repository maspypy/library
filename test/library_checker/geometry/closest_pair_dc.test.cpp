#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/closest_pair.hpp"

using P = Point<ll>;

void solve() {
  LL(N);
  VEC(P, point, N);
  auto [i, j] = closest_pair_dc(point);
  print(i, j);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}