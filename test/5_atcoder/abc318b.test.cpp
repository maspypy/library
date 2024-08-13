#define PROBLEM "https://atcoder.jp/contests/abc318/tasks/abc318_b"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/rectangle_union.hpp"

void solve() {
  LL(N);
  Rectangle_Union<int> X;
  FOR(N) {
    LL(a, b, c, d);
    X.add_rect(a, b, c, d);
  }
  print(X.calc());
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
