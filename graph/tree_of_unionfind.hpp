#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"

/*
マージ過程を表す木を構築する
q 回目にマージしてできる成分：N+q
add_root = true の場合：最後に全部をマージして、根 N+Q を追加する
*/
Graph<int> tree_of_unionfind(int N, vc<pair<int, int>> query, bool add_root) {
  UnionFind uf(N + len(query));
  vc<int> root(N);
  iota(all(root), 0);
  int Q = len(query);
  Graph<int> G(N + Q + add_root);
  FOR(q, Q) {
    int v = N + q;
    auto [a, b] = query[q];
    a = uf[a], b = uf[b];
    G.add(v, root[a]);
    if (b != a) G.add(v, root[b]);
    uf.merge(a, b);
    uf.merge(b, v);
    root[uf[v]] = v;
  }
  if (add_root) {
    int r = N + Q;
    FOR(v, N) if (uf[v] == v) G.add(r, root[v]);
  }
  G.build();
  return G;
}
