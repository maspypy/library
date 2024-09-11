
// 3^(N/3). 極大.
// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i
template <typename GT, typename F>
void enumerate_maximal_independent_set(GT& G, F f) {
  assert(G.N < 64);
  int N = G.N;
  vc<u64> adj(N);
  for (auto& e: G.edges) {
    adj[e.frm] |= u64(1) << e.to;
    adj[e.to] |= u64(1) << e.frm;
  }
  auto dfs = [&](auto& dfs, u64 I, u64 V) -> void {
    if (V == 0) {
      f(I);
      return;
    }
    int min_deg = infty<int>;
    int v = -1;
    enumerate_bits_64(V, [&](int i) -> void {
      int d = popcnt(V & adj[i]);
      if (chmin(min_deg, d)) v = i;
    });
    u64 cand = (V & adj[v]) | u64(1) << v;
    enumerate_bits_64(cand, [&](int v) -> void { dfs(dfs, I | u64(1) << v, V & (~(u64(1) << v)) & ~(adj[v])); });
  };
  u64 FULL = 0;
  FOR(i, N) FULL |= u64(1) << i;
  dfs(dfs, 0, FULL);
}
