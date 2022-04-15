#include "ds/unionfind.hpp"
#include "graph/base.hpp"
#include "graph/hld.hpp"

template <typename T = int>
struct FunctionalGraph {
  int N, M;
  Graph<T, 1> tree; // 新しい頂点 N を根として追加した有向木。逆向きの辺になる。
  // HLD<Graph<T, 1>> hld;
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

  void build() {
    assert(N == M);
    UnionFind uf(N);
    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }
    FOR(v, N) if (root[v] == v) root[uf[v]] = v;
    FOR(v, N) root[v] = root[uf[v]];

    tree = Graph<T, 1>(N + 1);
    FOR(v, N) {
      if (root[v] != v)
        tree.add(TO[v], v);
      else
        tree.add(N, v);
    }
    tree.prepare();
  }

  void debug() {
    print("TO", TO);
    print("root");
    print(root);
    print("根を追加した木 tree");
    tree.debug();
  }
};
