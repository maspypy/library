// https://codeforces.com/contest/635/problem/F
#include "graph/base.hpp"
#include "graph/hld.hpp"

// snippet 参照
template <typename Graph, typename Data, typename F1, typename F2, typename F3>
vc<Data> rerooting_dp(Graph& G, F1 fee, F2 fev, F3 fve, Data unit) {
  using E = typename Graph::edge_type;

  int N = G.N;
  HLD hld(G);
  auto V = hld.V;
  auto VR = V;
  reverse(all(VR));
  auto par = hld.parent;

  vc<Data> dpv(N);
  vc<Data> dpe1(N);

  for (auto&& v: VR) {
    auto val = unit;
    E e0;
    for (auto&& e: G[v]) {
      if (e.to != par[v]) {
        val = fee(val, dpe1[e.to]);
      } else {
        e0 = e;
      }
    }
    dpv[v] = fev(val, v);
    dpe1[v] = (v ? fve(dpv[v], e0) : unit);
  }

  vc<Data> dp(N);
  vc<Data> dpe2(N);
  dpe2[0] = unit;

  for (auto&& v: V) {
    vc<Data> tmp = {dpe2[v]};
    for (auto&& e: G[v])
      if (e.to != par[v]) { tmp.eb(dpe1[e.to]); }
    int n = len(tmp);
    vc<Data> cum_l(n + 1), cum_r(n + 1);
    cum_l[0] = unit;
    FOR(i, n) cum_l[i + 1] = fee(cum_l[i], tmp[i]);
    cum_r[n] = unit;
    FOR_R(i, n) cum_r[i] = fee(cum_r[i + 1], tmp[i]);
    dp[v] = fev(cum_r[0], v);
    int nxt = 1;
    for (auto&& e: G[v])
      if (e.to != par[v]) {
        auto prod = fee(cum_l[nxt], cum_r[nxt + 1]);
        ++nxt;
        dpe2[e.to] = fve(fev(prod, v), e);
      }
  }
  return dp;
}