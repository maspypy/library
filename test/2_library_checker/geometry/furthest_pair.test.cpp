#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/furthest_pair.hpp"

using P = Point<ll>;

void solve() {
  INT(N);
  VEC(P, point, N);
  auto [a, b] = furthest_pair(point);
  print(a, b);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
