#define PROBLEM "https://yukicoder.me/problems/no/1038"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/contour_query_range.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

void solve() {
  LL(N, Q);
  Graph<int, 0> G(N);
  G.read_tree();

  Contour_Query_Range<decltype(G), false> X(G);
  FenwickTree<Monoid_Add<ll>> bit(len(X) + 1);
  vi A(N);

  FOR(Q) {
    INT(v, d, x);
    --v;
    ll ans = A[v];
    for (auto& i: X.get_indices(v)) { ans += bit.sum(1 + i); }
    print(ans);

    for (auto& [a, b]: X.get_contour_range(v, 0, 1 + d)) {
      bit.add(a, x), bit.add(b, -x);
    }
    A[v] += x;
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
