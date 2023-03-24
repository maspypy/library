#define PROBLEM "https://yukicoder.me/problems/no/1718"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"
#include "graph/shortest_path/bfs01.hpp"

void solve() {
  LL(N, K);
  Graph<int, 0> G(N);
  G.read_tree();
  VEC(ll, D, K);
  for (auto&& a: D) --a;

  Tree<decltype(G)> tree(G);
  sort(all(D), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });

  ll base = 0;
  FOR(i, K) {
    int j = (i + 1 == K ? 0 : i + 1);
    int a = D[i], b = D[j];
    base += tree.dist(a, b);
  }

  // 部分木を塗る
  vi isin(N);
  FOR(i, K) {
    int j = (i + 1 == K ? 0 : i + 1);
    int a = D[i], b = D[j];
    isin[a] = 1;
    while (a != b) {
      a = tree.jump(a, b, 1);
      isin[a] = 1;
    }
  }

  for (auto&& x: D) isin[x] = 1;

  using Data = ll;
  Data unit = -infty<ll>;
  auto fee = [&](Data x, Data y) -> Data { return max(x, y); };
  auto fev = [&](Data x, int v) -> Data {
    if (isin[v]) chmax(x, 0);
    return x;
  };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return x + 1; };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  // span される部分からの距離
  vc<int> V;
  FOR(v, N) if (isin[v]) V.eb(v);
  auto [dist, par, root] = bfs01<int>(G, V);

  FOR(v, N) {
    ll r = root[v];
    ll ANS = dist[v] + base - dp[r];
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
