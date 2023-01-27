#define PROBLEM "https://yukicoder.me/problems/no/1976#"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/rerooting_dp.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  using Data = pair<int, int>;
  Data unit = {0, 0};
  auto fee = [&](Data x, Data y) -> Data {
    return {max({x.fi, y.fi, x.se + y.se}), max(x.se, y.se)};
  };
  auto fev = [&](Data x, int v) -> Data { return x; };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return {x.fi, x.se + 1}; };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  int ANS = N;

  for (auto&& e: G.edges) {
    int a = e.frm, b = e.to;
    int xa = dp.get(a, b).fi;
    int xb = dp.get(b, a).fi;
    int ra = ceil(xa, 2);
    int rb = ceil(xb, 2);
    int x = max({xa, xb, 1 + ra + rb});
    chmin(ANS, x);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
