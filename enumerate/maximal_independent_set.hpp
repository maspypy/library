// Source: https://github.com/maspypy/library/blob/main/enumerate/maximal_independent_set.hpp

#include "enumerate/bits.hpp"

// 3^(N/3). 極大.
// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i
template <typename GT, typename F>
void enumerate_maximal_independent_set(const GT& G, F f) {
  assert(G.N < 64);
  int N = G.N;
  vc<u64> adj(N);
  for (auto& e : G.edges) {
    adj[e.frm] |= u64(1) << e.to;
    adj[e.to] |= u64(1) << e.frm;
  }
  bool end = false;
  auto dfs = [&](auto& dfs, u64 I, u64 V) -> void {
    if (V == 0) {
      f(I, end);
      return;
    }
    int min_deg = infty<int>;
    int v = -1;
    enumerate_all_bit(V, [&](int i, bool) -> void {
      int d = popcnt(V & adj[i]);
      if (chmin(min_deg, d)) v = i;
    });
    u64 cand = (V & adj[v]) | u64(1) << v;
    enumerate_all_bit(cand, [&](int v, bool& end_inner) -> void {
      dfs(dfs, I | u64(1) << v, V & (~(u64(1) << v)) & ~(adj[v]));
      end_inner = end;
    });
  };
  u64 FULL = 0;
  FOR(i, N) FULL |= u64(1) << i;
  dfs(dfs, 0, FULL);
}
