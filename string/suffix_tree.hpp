
#include "string/suffix_array.hpp"
#include "seq/cartesian_tree.hpp"
#include "graph/base.hpp"

// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
// 各ノードは、suffix array での長方形領域と見なして、
// グラフおよび、領域データを作る。
// sample: test/my_test/suffix_tree.test.cpp
template <typename SUFFIX>
pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> suffix_tree(SUFFIX& X) {
  auto SA = X.SA;
  auto ISA = X.ISA;
  auto LCP = X.LCP;

  vc<tuple<int, int, int, int>> dat;
  vc<pair<int, int>> edges;

  int N = len(SA);
  if (N == 1) {
    Graph<int, 1> G(2);
    G.add(0, 1);
    dat.eb(0, 1, 0, 0);
    dat.eb(0, 1, 0, 1);
    return {G, dat};
  }

  dat.eb(0, N, 0, 0);
  CartesianTree<int, true> CT(LCP);

  auto dfs = [&](auto& dfs, int p, int idx, int h) -> void {
    int L = CT.range[idx].fi;
    int R = CT.range[idx].se + 1;
    int hh = LCP[idx];
    if (h < hh) {
      edges.eb(p, len(dat));
      p = len(dat);
      dat.eb(L, R, h, hh);
    }
    if (CT.lch[idx] == -1) {
      if (hh < N - SA[idx]) {
        edges.eb(p, len(dat));
        dat.eb(idx, idx + 1, hh, N - SA[idx]);
      }
    } else {
      dfs(dfs, p, CT.lch[idx], hh);
    }
    if (CT.rch[idx] == -1) {
      if (hh < N - SA[idx + 1]) {
        edges.eb(p, len(dat));
        dat.eb(idx + 1, idx + 2, hh, N - SA[idx + 1]);
      }
    } else {
      dfs(dfs, p, CT.rch[idx], hh);
    }
  };
  int r = CT.root;
  if (LCP[r] > 0) {
    edges.eb(0, 1);
    dat.eb(0, N, 0, LCP[r]);
    dfs(dfs, 1, r, LCP[r]);
  } else {
    dfs(dfs, 0, r, 0);
  }

  Graph<int, 1> G(len(dat));
  for (auto&& [a, b]: edges) G.add(a, b);
  G.build();
  return {G, dat};
}
