// https://codeforces.com/contest/735/problem/E
#include "graph/base.hpp"
#include "graph/hld.hpp"

template <typename Graph, typename Data, typename F1, typename F2, typename F3>
vc<Data> tree_dp(Graph& G, F1 fee, F2 fev, F3 fve, Data unit) {
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
  return dpv;
}