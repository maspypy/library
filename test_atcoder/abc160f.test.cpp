#define PROBLEM "https://atcoder.jp/contests/abc160/tasks/abc160_f"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  Graph<bool, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  using Data = pair<int, mint>;
  Data unit = {0, mint(1)};
  auto fee = [&](Data x, Data y) -> Data { return {x.fi + y.fi, x.se * y.se}; };
  auto fev = [&](Data x, int v) -> Data {
    return {x.fi + 1, x.se * inv<mint>(x.fi + 1)};
  };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return x; };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  FOR(v, N) print(dp[v].se * fact<mint>(N));
}

signed main() {
  solve();
  return 0;
}
