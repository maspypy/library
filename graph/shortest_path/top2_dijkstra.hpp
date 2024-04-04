#include "graph/base.hpp"
#include "alg/monoid/min2.hpp"

// 経路復元はなしで距離と種類だけになっている
template <typename T, typename GT>
vc<typename Monoid_Min2<T, int>::Data> top2_dijkstra(GT& G, vc<int> vs) {
  assert(G.is_prepared());
  int N = G.N;
  using Mono = Monoid_Min2<T, int>;
  using Data = typename Mono::Data;
  vc<Data> dist(N, Mono::unit());
  pqg<tuple<T, int, int>> que; // 距離、町、色

  auto upd = [&](int v, int c, T x) -> void {
    if (dist[v].add_element(x, c)) que.emplace(x, v, c);
  };

  for (auto& v: vs) { upd(v, v, 0); }

  while (len(que)) {
    auto [dv, v, c] = POP(que);
    bool ok = 0;
    auto& e = dist[v];
    if (e.min1 == dv && e.key1 == c) ok = 1;
    if (e.min2 == dv && e.key2 == c) ok = 1;
    if (!ok) continue;
    for (auto&& e: G[v]) { upd(e.to, c, dv + e.cost); }
  }
  return dist;
}