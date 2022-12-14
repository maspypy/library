#include "graph/path_cycle.hpp"

// 独立集合数え上げ。空集合も認める。N 1.381^N 程度。
template <typename GT>
u64 count_independent_set(GT& G) {
  using U = u64;
  const int N = G.N;
  assert(N < 64);
  if (N == 0) return 1;
  vc<U> nbd(N);
  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= U(1) << e.to;

  vc<U> dp_path(N + 1), dp_cyc(N + 1);
  dp_path[0] = 1, dp_path[1] = 2;
  FOR(i, 2, N + 1) dp_path[i] = dp_path[i - 1] + dp_path[i - 2];
  FOR(i, 3, N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i - 3];

  auto dfs = [&](auto& dfs, U s) -> U {
    int deg0 = 0;
    pair<int, int> p = {-1, -1}; // (v, d)
    FOR(v, N) if (s >> v & 1) {
      int d = popcnt(nbd[v] & s);
      if (chmax(p.se, d)) p.fi = v;
      if (d == 0) {
        ++deg0;
        s &= ~(U(1) << v);
      }
    }
    if (s == 0) return U(1) << deg0;
    int v = p.fi;
    if (p.se >= 3) {
      s &= ~(U(1) << v);
      return (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;
    }
    // d <= 2, path と cycle のみ
    vc<int> V;
    FOR(v, N) if (s >> v & 1) V.eb(v);
    int n = len(V);
    Graph<bool, 0> G(n);
    FOR(i, n) {
      U x = nbd[V[i]] & s;
      while (x) {
        int v = topbit(x);
        x ^= U(1) << v;
        int j = LB(V, v);
        if (i < j) G.add(i, j);
      }
    }
    G.build();
    auto [paths, cycs] = path_cycle(G);
    U res = 1;
    for (auto&& P: paths) res *= dp_path[len(P)];
    for (auto&& C: cycs) res *= dp_cyc[len(C)];
    return res << deg0;
  };
  return dfs(dfs, (U(1) << N) - 1);
}