
// (n,m)=(1000,1000) で 24ms
// https://contest.ucup.ac/contest/1358/problem/7514
template <typename GT>
u64 count_clique(GT& G) {
  INT(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  u64 ANS = 1; // emptyset
  vc<int> new_idx(N, -1);

  while (N) {
    auto deg = G.deg_array();
    int p = min_element(all(deg)) - deg.begin();
    vc<int> nbd, other;
    for (auto& e: G[p]) nbd.eb(e.to);
    FOR(v, N) {
      if (v != p) other.eb(v);
    }

    // nbd graph の補グラフを作って、独立集合を数える
    int n = len(nbd);
    FOR(i, n) { new_idx[nbd[i]] = i; }
    vv(int, adj, n, n);
    for (auto& e: G.edges) {
      int a = e.frm, b = e.to;
      a = new_idx[a], b = new_idx[b];
      if (a == -1 || b == -1) continue;
      adj[a][b] = adj[b][a] = 1;
    }
    FOR(i, n) { new_idx[nbd[i]] = -1; }
    Graph<int, 0> G1(n);
    FOR(i, n) FOR(j, i) if (!adj[i][j]) G1.add(i, j);
    G1.build();
    u64 cnt = count_independent_set(G1);
    ANS += cnt;
    G = G.rearrange(other).fi;
    assert(G.N == N - 1);
    --N;
  }
  return ANS;
}
