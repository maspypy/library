#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/rectangle_union.hpp"

void solve() {
  LL(N);
  Rectangle_Union<int> X;
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
