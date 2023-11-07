
#include "alg/acted_monoid/minmincnt_add.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "graph/base.hpp"

// G: tree
// count(l,r) s.t. (v_i|l<=i<=r) is connected
// https://qoj.ac/contest/1277/problem/6674
template <typename GT>
ll count_connected_intervals(GT& G) {
  assert(!GT::is_directed);
  int N = G.N;
  using AM = ActedMonoid_MinMincnt_Add<int>;
  Lazy_SegTree<AM> seg(N, [&](int i) -> pair<int, int> { return {0, 1}; });

  ll ANS = 0;
  FOR(r, N) {
    // |V|
    seg.apply(0, r + 1, 1);
    // |E|
    for (auto& e: G[r]) {
      if (e.to < r) { seg.apply(0, e.to + 1, -1); }
    }
    auto [mi, mi_cnt] = seg.prod(0, r + 1);
    assert(mi >= 1);
    if (mi == 1) ANS += mi_cnt;
  }
  return ANS;
}