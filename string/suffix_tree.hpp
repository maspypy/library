
#include "string/suffixarray.hpp"
#include "alg/monoid/min_idx.hpp"
#include "ds/segtree/segtree.hpp"
#include "graph/base.hpp"

// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
// 各ノードは、suffix array での長方形領域と見なして、
// グラフおよび、領域データを作る。
// sample: test/my_test/suffix_tree.test.cpp
pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> suffix_tree(SuffixArray& X) {
  auto SA = X.SA;
  auto ISA = X.ISA;
  auto LCP = X.LCP;

  int N = len(SA);

  using Mono = Monoid_Min_Idx<int, 1>;

  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X { return {LCP[i], i}; });

  using T = tuple<int, int, int, int>;
  vc<T> dat;
  Graph<int, 1> G;
  dat.eb(0, 0, N, 0);

  auto dfs = [&](auto& dfs, int p, int l, int r, int h) -> void {
    if (r == l + 1) {
      int i = SA[l];
      int sz = N - i;
      if (h == sz) return;
      int k = len(dat);
      dat.eb(l, h, l + 1, sz);
      G.resize(k + 1);
      G.add(p, k);
      return;
    }
    auto [lcp, i] = seg.prod(l, r - 1);
    if (lcp == h) {
      dfs(dfs, p, l, i + 1, h);
      dfs(dfs, p, i + 1, r, h);
      return;
    }
    int k = len(dat);
    dat.eb(l, h, r, lcp);
    G.resize(k + 1);
    G.add(p, k);
    dfs(dfs, k, l, r, lcp);
  };
  dfs(dfs, 0, 0, N, 0);
  G.build();
  return {G, dat};
}