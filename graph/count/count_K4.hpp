
// M^{1.5} + M^2/w
// simple graph を仮定
template <typename GT>
ll count_K4(GT& G) {
  assert(G.is_prepared() && !G.is_directed());
  const int N = G.N;
  Graph<bool, 1> DAG(N);
  {
    auto deg = G.deg_array();
    auto comp = [&](int a, int b) -> bool {
      return (deg[a] == deg[b] ? a < b : deg[a] < deg[b]);
    };
    for (auto&& e: G.edges) {
      int a = e.frm, b = e.to;
      if (!comp(a, b)) swap(a, b);
      DAG.add(a, b);
    }
    DAG.build();
  }

  vc<int> new_idx(N, -1);
  ll ANS = 0;
  FOR(a, N) {
    vc<int> V;
    for (auto&& e: DAG[a]) V.eb(e.to);
    FOR(i, len(V)) new_idx[V[i]] = i;
    int n = len(V);
    Graph<bool, 1> H(n);
    FOR(i, n) {
      for (auto&& e: DAG[V[i]]) {
        int j = new_idx[e.to];
        if (j == -1) continue;
        H.add(i, j);
      }
    }
    H.build();
    FOR(b, ceil(n, 64)) {
      int L = 64 * b;
      int R = L + 64;
      chmin(R, n);
      vc<u64> dp(n);
      FOR(i, L, R) {
        for (auto&& e: H[i]) { dp[e.to] |= u64(1) << (i - L); }
      }
      for (auto&& e: H.edges) { ANS += popcnt(dp[e.frm] & dp[e.to]); }
    }
    FOR(i, len(V)) new_idx[V[i]] = -1;
  }
  return ANS;
}