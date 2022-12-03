#define PROBLEM \
  "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/ds/contour_sum.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int, 0> G(N);
  G.read_tree(0, 0);
  Contour_Sum<decltype(G), Monoid_Add<ll>> X(G, A);

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      X.add(v, x);
    }
    if (t == 1) {
      LL(v, l, r);
      print(X.sum(v, l, r));
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
