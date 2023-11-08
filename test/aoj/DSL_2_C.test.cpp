#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/kdtree/kdtree.hpp"

void solve() {
  LL(N);
  vi X, Y;
  vvc<int> idx(N);
  FOR(i, N) {
    LL(x, y);
    X.eb(x);
    Y.eb(y);
    idx[i].eb(i);
  }
  KDTree<ll> KDT(X, Y);

  LL(Q);
  FOR(Q) {
    LL(xl, xr, yl, yr);
    auto ids = KDT.collect_rect(xl, xr + 1, yl, yr + 1);
    sort(all(ids));
    for (auto& x: ids) print(x);
    print();
  }
}

signed main() {
  solve();

  return 0;
}