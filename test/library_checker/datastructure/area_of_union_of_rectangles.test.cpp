#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/rectangleunion.hpp"

void solve() {
  LL(N);
  RectangleUnion<int> X;
  FOR(N) {
    LL(a, b, c, d);
    X.add_rect(a, c, b, d);
  }
  print(X.calc<ll>());
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}
