#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "alg/monoid/min2.hpp"

void solve() {
  LL(N, M, K, L);
  VEC(ll, A, N);
  for (auto&& a: A) --a;
  VEC(ll, B, L);
  for (auto&& b: B) --b;

  Graph<int, 0> G(N);
  G.read_graph(M, 1);

  using Mono = Monoid_Min2<ll, int>;
  using Data = typename Mono::Data;
  vc<Data> dist(N, Mono::unit());

  using T = tuple<ll, int, int>; // 距離、町、色
  pqg<T> que;

  auto add = [&](ll v, ll c, ll x) -> void {
    if (dist[v].add_element(x, c)) que.emplace(x, v, c);
  };

  for (auto&& b: B) add(b, A[b], 0);

  while (len(que)) {
    auto [dv, v, c] = que.top();
    que.pop();
    bool ok = 0;
    auto& e = dist[v];
    if (e.min1 == dv && e.key1 == c) ok = 1;
    if (e.min2 == dv && e.key2 == c) ok = 1;
    if (!ok) continue;
    for (auto&& e: G[v]) { add(e.to, c, dv + e.cost); }
  }

  vi ANS(N);
  FOR(v, N) {
    auto& e = dist[v];
    ll x = infty<ll>;
    if (e.key1 != A[v]) chmin(x, e.min1);
    if (e.key2 != A[v]) chmin(x, e.min2);
    if (x == infty<ll>) x = -1;
    ANS[v] = x;
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
