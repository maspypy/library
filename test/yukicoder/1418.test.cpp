#define PROBLEM "https://yukicoder.me/problems/no/1418"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/rerooting_dp.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();

  // 部分木の大きさ、その中の部分木の大きさの和
  using Data = pi;
  Data unit = {0, 0};
  auto fee = [&](Data x, Data y) -> Data { return {x.fi + y.fi, x.se + y.se}; };
  auto fev = [&](Data x, int v) -> Data {
    return {x.fi + 1, x.se + (x.fi + 1)};
  };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return x; };

  Tree<decltype(G)> tree(G);
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);
  ll ANS = 0;
  FOR(v, N) ANS += dp[v].se;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}