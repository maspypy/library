#include "random/base.hpp"
#include "nt/GF2.hpp"

// https://www.slideshare.net/wata_orz/ss-12208032
// https://epubs.siam.org/doi/10.1137/1.9781611973099.139
// O(2^kN^2M)
template <typename GT>
int minimum_cycle_length_through_specified(GT& G, vc<int> use) {
  assert(len(use) >= 2);
  assert(!GT::is_directed);
  const int N = G.N;
  using F = GF2<64>;
  int s = use.back();
  use.pop_back();

  // 重み付き有向グラフに変形
  // 始点の近くでは逆向きを違う重みにすることで、向き違いのキャンセリングを防ぐ
  Graph<F, 1> H(G.N);
  for (auto&& e: G.edges) {
    F a = RNG_64();
    F b = a;
    if (e.frm == s || e.to == s) b = RNG_64();
    H.add(e.frm, e.to, a);
    H.add(e.to, e.frm, b);
  }
  H.build();
  const int M = H.M;

  int K = len(use);
  vc<int> mask(N);
  FOR(k, K) mask[use[k]] = 1 << k;

  // [集合][最後の辺]
  vv(F, dp, 1 << K, M);
  for (auto&& e: H[s]) { dp[mask[e.to]][e.id] = e.cost; }
  FOR(L, 2, N + 1) {
    vv(F, newdp, 1 << K, M);
    FOR(s, 1 << K) {
      vc<F> dp_v(N);
      FOR(i, M) dp_v[H.edges[i].to] += dp[s][i];
      FOR(v, N) {
        for (auto&& e: H[v]) {
          int t = s | mask[e.to];
          if (mask[e.to] && s == t) continue;
          newdp[t][e.id] += dp_v[v] * e.cost;
          // use 上の点から戻るのを禁止する
          if (mask[v]) { newdp[t][e.id] += dp[s][e.id ^ 1] * e.cost; }
        }
      }
    }
    swap(dp, newdp);
    int full = (1 << K) - 1;
    F sm = 0;
    FOR(i, M) {
      if (H.edges[i].to == s) sm += dp[full][i];
    }
    if (sm != F(0)) return L;
  }
  return -1;
}