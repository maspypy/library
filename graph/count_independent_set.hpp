#include "graph/path_cycle.hpp"
#include "poly/convolution.hpp"

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

// 独立集合数え上げ。空集合も認める。N 1.381^N 程度。
template <typename GT>
vc<u64> count_independent_set_by_size(GT& G) {
  using U = u64;
  const int N = G.N;
  assert(N < 64);
  if (N == 0) return {1};
  vc<U> nbd(N);
  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= U(1) << e.to;

  vvc<U> dp_path(N + 1), dp_cyc(N + 1);
  dp_path[0] = {1}, dp_path[1] = {1, 1};
  FOR(i, 2, N + 1) {
    dp_path[i] = dp_path[i - 1];
    dp_path[i].resize(ceil(i, 2) + 1);
    FOR(k, len(dp_path[i - 2])) { dp_path[i][k + 1] += dp_path[i - 2][k]; }
  }
  FOR(i, 3, N + 1) {
    dp_cyc[i] = dp_path[i - 1];
    FOR(k, len(dp_path[i - 3])) dp_cyc[i][k + 1] += dp_path[i - 3][k];
  }

  auto dfs = [&](auto& dfs, U s) -> vc<U> {
    vc<U> res = {1};
    pair<int, int> p = {-1, -1}; // (v, d)
    FOR(v, N) if (s >> v & 1) {
      int d = popcnt(nbd[v] & s);
      if (chmax(p.se, d)) p.fi = v;
      if (d == 0) {
        res.eb(0);
        FOR_R(i, len(res) - 1) res[i + 1] += res[i];
        s &= ~(U(1) << v);
      }
    }
    if (s == 0) return res;
    int v = p.fi;
    if (p.se >= 3) {
      s &= ~(U(1) << v);
      auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);
      if (len(f) < len(g) + 1) f.resize(len(g) + 1);
      FOR(i, len(g)) f[i + 1] += g[i];
      return convolution_naive(f, res);
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
    for (auto&& P: paths) res = convolution_naive(res, dp_path[len(P)]);
    for (auto&& C: cycs) res = convolution_naive(res, dp_cyc[len(C)]);
    return res;
  };
  auto res = dfs(dfs, (U(1) << N) - 1);
  res.resize(N + 1);
  return res;
}