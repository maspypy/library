#define PROBLEM "https://yukicoder.me/problems/no/1718"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/rerooting_dp.hpp"
#include "graph/hld.hpp"
#include "graph/bfs01.hpp"

void solve() {
  LL(N, K);
  Graph G(N);
  G.read_tree();
  VEC(ll, D, K);
  for (auto&& a: D) --a;

  HLD hld(G);
  sort(all(D), [&](auto& x, auto& y) { return hld.LID[x] < hld.LID[y]; });

  ll base = 0;
  FOR(i, K) {
    int j = (i + 1 == K ? 0 : i + 1);
    int a = D[i], b = D[j];
    base += hld.dist(a, b);
  }

  // 部分木を塗る
  vi isin(N);
  FOR(i, K) {
    int j = (i + 1 == K ? 0 : i + 1);
    int a = D[i], b = D[j];
    isin[a] = 1;
    while (a != b) {
      a = hld.jump(a, b);
      isin[a] = 1;
    }
  }

  for (auto&& x: D) isin[x] = 1;

  const ll INF = 1LL << 60;
  using Data = ll;
  Data unit = -INF;
  auto fee = [&](Data x, Data y) -> Data { return max(x, y); };
  auto fev = [&](Data x, int v) -> Data {
    if (isin[v]) chmax(x, 0);
    return x;
  };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return x + 1; };
  auto dp = rerooting_dp(G, fee, fev, fve, unit);

  // span される部分からの距離
  vc<int> V;
  FOR(v, N) if (isin[v]) V.eb(v);
  auto [dist, par, root] = bfs01(G, V);

  FOR(v, N) {
    ll r = root[v];
    ll ANS = dist[v] + base - dp[r];
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
