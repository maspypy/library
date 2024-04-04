#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/shortest_path/top2_dijkstra.hpp"

void solve() {
  LL(N, M, K, L);
  VEC(ll, A, N);
  for (auto&& a: A) --a;
  VEC(ll, B, L);
  for (auto&& b: B) --b;

  Graph<int, 1> G(N + K);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    G.add(a, b, c), G.add(b, a, c);
  }
  for (auto& b: B) G.add(N + A[b], b, 0);
  G.build();

  vc<int> vs(K);
  FOR(k, K) vs[k] = N + k;
  auto dist = top2_dijkstra<ll>(G, vs);

  vi ANS(N);
  FOR(v, N) {
    auto& e = dist[v];
    ll x = infty<ll>;
    if (e.key1 != N + A[v]) chmin(x, e.min1);
    if (e.key2 != N + A[v]) chmin(x, e.min2);
    if (x == infty<ll>) x = -1;
    ANS[v] = x;
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
