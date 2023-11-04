#include "graph/tree.hpp"
#include "alg/monoid/min_idx.hpp"
#include "alg/monoid/min.hpp"
#include "ds/sparse_table/sparse_table.hpp"

template <typename TREE>
struct Fast_Lca {
  TREE& tree;
<<<<<<< HEAD
  using Mono = Monoid_Min<int>;
  Sparse_Table<Monoid_Min<int>> seg;
=======
  Sparse_Table<Monoid_Min<int>> seg_mi;
  Sparse_Table<Monoid_Min_Idx<int>> seg_mi_idx;
>>>>>>> a186dd248d5217509c67022080018011df4ce7f1
  vc<int> pos;

  Fast_Lca(TREE& tree) : tree(tree) {
    int N = tree.N;
    pos.resize(N);
    vc<int> dat(2 * N);
    FOR(v, N) {
      int a = tree.ELID(v);
      int b = tree.ERID(v);
      pos[v] = a;
      dat[a] = tree.LID[v];
      dat[b] = (v == tree.V[0] ? -1 : tree.LID[tree.parent[v]]);
    }
<<<<<<< HEAD
    seg.build(dat);
=======
  }

  int lca(int a, int b) {
    static_assert(!dist_only);
    return lca_and_dist(a, b).fi;
>>>>>>> a186dd248d5217509c67022080018011df4ce7f1
  }

  int dist(int a, int b) {
    int c = lca(a, b);
    return tree.depth[a] + tree.depth[b] - 2 * tree.depth[c];
  }

  int lca(int a, int b) {
    int p = pos[a], q = pos[b];
    if (p > q) swap(p, q);
    return tree.V[seg.prod(p, q + 1)];
  }
};