
// 大きさ K 以下の頂点被覆があればそれを返す
// NK*1.618^K くらい
// path-cycle を何とかするともっと早くなる
// グラフの持ち方がいまいちかも
// https://codeforces.com/contest/164/problem/D
template <typename GT>
vc<int> find_vertex_cover(GT G, int K) {
  int N = G.N;
  vv(bool, adj, N, N);
  for (auto& e: G.edges) {
    assert(e.frm != e.to);
    adj[e.frm][e.to] = adj[e.to][e.frm] = 1;
  }
  vc<int> deg(N);
  FOR(v, N) deg[v] = SUM<int>(adj[v]);

  if (K == 0) return {};

  vc<bool> used(N);
  vc<int> S;
  bool end = 0;
  int M = SUM<int>(deg) / 2;

  auto on = [&](int v) -> void {
    assert(!used[v]);
    M -= deg[v];
    FOR(w, N) {
      if (!used[w] && adj[v][w]) { deg[v]--, deg[w]--; }
    }
    assert(deg[v] == 0);
    used[v] = 1;
    S.eb(v);
  };
  auto off = [&](int v) -> void {
    assert(S.back() == v);
    S.pop_back();
    used[v] = 0;
    FOR(w, N) {
      if (!used[w] && adj[v][w]) { deg[v]++, deg[w]++; }
    }
    M += deg[v];
  };

  auto dfs = [&](auto& dfs) -> void {
    if (end) return;
    int c = max_element(all(deg)) - deg.begin();
    if (deg[c] * (K - len(S)) < M) { return; }
    if (deg[c] == 0) {
      assert(M == 0);
      end = 1;
      return;
    }
    if (len(S) == K) { return; }
    on(c);
    dfs(dfs);
    if (end) return;
    off(c);
    if (deg[c] == 1) return;
    if (len(S) + deg[c] > K) return;
    int k = len(S);
    FOR(v, N) {
      if (adj[v][c] && !used[v]) { on(v); }
    }
    dfs(dfs);
    if (end) return;
    while (len(S) > k) { off(S.back()); }
  };
  dfs(dfs);
  if (!end) assert(S.empty());
  return S;
}