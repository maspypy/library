#define PROBLEM \
  "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

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
  vi dat_raw(len(CQ));
  FOR(v, N) {
    for (auto& p: CQ.get_indices(v)) { dat_raw[p] += A[v]; }
  }
  FenwickTree<Monoid_Add<ll>> bit(dat_raw);

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(v, x);
      A[v] += x;
      for (auto& p: CQ.get_indices(v)) bit.add(p, x);
    }
    if (t == 1) {
      INT(v, l, r);
      ll ans = 0;
      if (l <= 0 && 0 < r) ans += A[v];
      for (auto& [a, b]: CQ.get_contour_range(v, l, r)) {
        ans += bit.sum(a, b);
      }
      print(ans);
    }
  }
}

signed main() {
  solve();
  return 0;
}
