#include "graph/tree.hpp"
#include "ds/unionfind.hpp"

// N が根となる木を新たに作る
template <typename T = int>
struct FunctionalGraph {
  int N, M;
  vc<int> TO;
  vc<T> wt;
  vc<int> root;

  FunctionalGraph() {}
  FunctionalGraph(int N) : N(N), M(0), TO(N, -1), wt(N), root(N, -1) {}

  void add(int a, int b, T c = 1) {
    assert(0 <= a && a < N);
    assert(TO[a] == -1);
    ++M;
    TO[a] = b;
    wt[a] = c;
  }

  TREE<Graph<T, 1>> build() {
    assert(N == M);
    UnionFind uf(N);
    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }
    FOR(v, N) if (root[v] == v) root[uf[v]] = v;
    FOR(v, N) root[v] = root[uf[v]];

    Graph<T, 1> G(N + 1);
    FOR(v, N) {
      if (root[v] == v)
        G.add(N, v, wt[v]);
      else
        G.add(TO[v], v, wt[v]);
    }

    G.build();
    TREE<Graph<T, 1>> tree(G, N);
    return tree;
  }

  // functional graph に向かって進む
  template <typename TREE>
  int jump(TREE& tree, int v, ll step) {
    int d = tree.depth[v];
    if (step <= d - 1) return tree.jump(v, N, step);
    v = tree.jump(v, N, d - 1);
    step -= d - 1;
    int bottom = TO[v];
    int c = tree.depth[bottom];
    step %= c;
    if (step == 0) return v;
    return tree.jump(bottom, step - 1);
  }
};
