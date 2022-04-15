/*
マージ過程を表す木を構築する
q 回目にマージしてできる成分：N+q
最後に全部をマージして、根 N+Q を追加する
全部で N+Q+1 頂点、根が N+Q の根付き木
*/
Graph<int> tree_of_unionfind(int N, vc<pair<int, int>> query) {
  UnionFind uf(N);
  vc<int> root(N);
  iota(all(root), 0);
  int Q = len(query);
  Graph<int> G(N + Q + 1);
  FOR(q, Q) {
    int v = N + q;
    auto [a, b] = query[q];
    assert(0 <= a && a < N);
    assert(0 <= b && b < N);
    a = uf[a], b = uf[b];
    G.add(v, root[a]);
    if (b != a) G.add(v, root[b]);
    uf.merge(a, b);
    root[uf[a]] = v;
  }
  int r = N + Q;
  FOR(v, N) if (uf[v] == v) G.add(r, root[v]);
  G.build();
  return G;
}