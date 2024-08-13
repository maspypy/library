#define PROBLEM \
  "https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "graph/ds/contour_query_range.hpp"

#include "alg/monoid/add.hpp"

void solve() {
  INT(N, Q);
  VEC(ll, A, N);
  Graph<int, 0> G(N);
  G.read_tree(0, 0);
  Contour_Query_Range<decltype(G), false> CQ(G);
  FenwickTree<Monoid_Add<ll>> bit(len(CQ) + 1);

  auto apply = [&](int v, int l, int r, int x) -> void {
    for (auto& [a, b]: CQ.get_contour_range(v, l, r)) {
      bit.add(a, x), bit.add(b, -x);
    }
    if (l <= 0 && 0 < r) A[v] += x;
  };

  auto get = [&](int v) -> ll {
    ll ans = A[v];
    for (auto& i: CQ.get_indices(v)) { ans += bit.sum(i + 1); }
    return ans;
  };

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(v, l, r, x);
      apply(v, l, r, x);
    }
    if (t == 1) {
      INT(v);
      print(get(v));
    }
  }
}

signed main() {
  solve();
  return 0;
}
