#include "graph/base.hpp"
#include "random/base.hpp"
#include "nt/GF2.hpp"

// (s,t) path であって need をすべて通るものの最小長さを求める.
// s=t でもよい. 最初の 1 歩目も求める.
// {length, first v}. なければ {-1,-1}.
// O(2^K(N+M)L), L = shortest path length
template <typename GT>
pair<int, int> find_path_through_specified(GT& G, int s, int t, vc<int> need) {
  static_assert(!GT::is_directed);
  int N = G.N;
  assert(0 <= s && s < N && 0 <= t && t < N);
  using F = GF2<64>;
  // frm, to, wt
  vc<tuple<int, int, F>> edges;
  vc<int> S, T;
  for (auto& e: G.edges) {
    int a = e.frm, b = e.to;
    if ((a == s && b == t) || (a == t && b == s)) {
      if (need.empty()) return {1, t};
      continue;
    }
    if (a == s || b == s) { S.eb(a ^ b ^ s); }
    if (a == t || b == t) { T.eb(a ^ b ^ t); }
    if (a != s && a != t && b != s && b != t) {
      F x = RNG_64();
      edges.eb(a, b, x), edges.eb(b, a, x);
    }
  }
  int K = len(need);
  vc<int> get(N);
  FOR(k, K) get[need[k]] = 1 << k;
  int M = len(edges);

  vv(F, dp_e, 1 << K, M);
  vv(F, dp_v, 1 << K, N);
  for (auto& v: T) dp_v[get[v]][v] = RNG_64();
  FOR(L, 1, N) {
    for (auto& v: S) {
      if (dp_v.back()[v] != F(0)) return {1 + L, v};
    }
    vv(F, newdp_e, 1 << K, M);
    vv(F, newdp_v, 1 << K, N);
    FOR(s, 1 << K) {
      FOR(m, M) {
        auto [a, b, c] = edges[m];
        int t = s | get[b];
        if (get[b] && s == t) continue;
        F x = (dp_v[s][a] + dp_e[s][m ^ 1]) * c;
        newdp_e[t][m] += x, newdp_v[t][b] += x;
      }
    }
    swap(dp_v, newdp_v), swap(dp_e, newdp_e);
  }
  return {-1, -1};
}