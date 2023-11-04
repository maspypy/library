#include "graph/tree.hpp"
#include "alg/monoid/min_idx.hpp"
#include "alg/monoid/min.hpp"
#include "ds/static_range_product.hpp"

// sparse table を使う <O(NlogN),O(1)>
// dist_only の方が 2 割くらい高速か
template <typename TREE, bool dist_only>
struct Fast_Lca {
  using Mono1 = Monoid_Min<int>;
  using Mono2 = Monoid_Min_Idx<int>;
  TREE& tree;
  Static_Range_Produc<Mono1, Sparse_Table<Mono1>> seg_mi;
  Static_Range_Produc<Mono2, Sparse_Table<Mono2>> seg_mi_idx;
  vc<int> pos;

  Fast_Lca(TREE& tree) : tree(tree) {
    int N = tree.N;
    pos.resize(N);
    if constexpr (dist_only) {
      vc<int> dat(2 * N - 1);
      FOR(v, N) {
        int a = tree.ELID(v);
        int b = tree.ERID(v);
        int d = tree.depth[v];
        dat[a] = d;
        pos[v] = a;
        if (b < 2 * N - 1) dat[b] = d - 1;
      }
      seg_mi.build(dat);
    } else {
      vc<pair<int, int>> dat(2 * N - 1);
      FOR(v, N) {
        int a = tree.ELID(v);
        int b = tree.ERID(v);
        int d = tree.depth[v];
        pos[v] = a;
        dat[a] = {d, v};
        if (b < 2 * N - 1) dat[b] = {d - 1, tree.parent[v]};
      }
      seg_mi_idx.build(dat);
    }
  }

  int lca(int a, int b) {
    static_assert(!dist_only);
    int p = pos[a], q = pos[b];
    if (p > q) swap(p, q);
    return seg_mi_idx.prod(p, q + 1).se;
  }

  int dist(int a, int b) {
    if constexpr (dist_only) {
      int da = tree.depth[a], db = tree.depth[b];
      int p = pos[a], q = pos[b];
      if (p > q) swap(p, q);
      return da + db - 2 * seg_mi.prod(p, q + 1);
    } else {
      return lca_and_dist(a, b).se;
    }
  }

  pair<int, int> lca_and_dist(int a, int b) {
    int da = tree.depth[a], db = tree.depth[b];
    int p = pos[a], q = pos[b];
    if (p > q) swap(p, q);
    auto [dc, c] = seg_mi_idx.prod(p, q + 1);
    return {c, da + db - dc - dc};
  }
};
