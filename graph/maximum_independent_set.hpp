#include "graph/base.hpp"

// worst N*1.381^N だが、N=100 程度でも使える可能性がある。
template <int MAX_V, typename GT>
vc<int> maximum_independent_set(GT& G) {
  using BS = bitset<MAX_V>;
  const int N = G.N;
  assert(N <= MAX_V);
  vc<BS> nbd(N);
  FOR(v, N) for (auto&& e: G[v]) nbd[v][e.to] = 1;

  int best = 0;
  BS res;

  auto dfs = [&](auto& dfs, BS now, BS rest) -> void {
    pair<int, int> p = {-1, -1}; // (v, d)
    while (1) {
      bool upd = 0;
      FOR(v, N) if (rest[v]) {
        int d = (nbd[v] & rest).count();
        if (chmax(p.se, d)) p.fi = v;
        if (d <= 1) { rest[v] = 0, rest &= ~nbd[v], now[v] = 1, upd = 1; }
      }
      if (!upd) break;
      p = {-1, -1};
    }
    int a = now.count(), b = rest.count();
    if (chmax(best, a)) res = now;
    if (b == 0 || a + b <= best) return;
    int v = p.fi;
    rest[v] = 0;
    if (p.se >= 3) dfs(dfs, now, rest);
    now[v] = 1;
    dfs(dfs, now, rest & ~(nbd[v]));
  };
  BS now, rest;
  FOR(v, N) rest[v] = 1;
  dfs(dfs, now, rest);
  vc<int> ANS;
  FOR(v, N) if (res[v]) ANS.eb(v);
  return ANS;
}