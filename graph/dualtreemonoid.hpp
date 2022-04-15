#include "ds/lazysegtree.hpp"
#include "graph/hld.hpp"
#include "ds/dualsegtree.hpp"

template <typename HLD, typename Monoid, bool edge = false>
struct DualTreeMonoid {
  using X = typename Monoid::value_type;
  HLD &hld;
  int N;
  DualSegTree<Monoid> seg;

  DualTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {}

  X get(int i) {
    int v = i;
    if (edge) {
      auto &&e = hld.G.edges[i];
      v = (hld.parent[e.frm] == e.to ? e.frm : e.to);
    }
    return seg.get(hld.LID[v]);
  }

  vc<X> get_all() {
    vc<X> tmp = seg.get_all();
    vc<X> res;
    FOR(i, N) {
      if (edge && i == N - 1) break;
      int v = i;
      if (edge) {
        auto &&e = hld.G.edges[i];
        v = (hld.parent[e.frm] == e.to ? e.frm : e.to);
      }
      res.eb(tmp[hld.LID[i]]);
    }
    return res;
  }

  void apply_path(int u, int v, X x) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    for (auto &&[a, b]: pd) {
      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));
    }
    return;
  }

  void apply_subtree(int u, X x) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.apply(l + edge, r, x);
  }
};
