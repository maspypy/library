#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_dp/rerooting_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, N);
  Graph<bool, 0> G(N);
  vc<mint> B(N - 1), C(N - 1);
  FOR(i, N - 1) {
    LL(u, v, b, c);
    G.add(u, v);
    B[i] = b, C[i] = c;
  }
  G.build();
  Tree<decltype(G)> tree(G);

  using Data = pair<mint, mint>; // cnt, sum
  Data unit = {0, 0};
  auto fee = [&](Data x, Data y) -> Data { return {x.fi + y.fi, x.se + y.se}; };
  auto fev = [&](Data x, int v) -> Data {
    return {x.fi + mint(1), x.se + A[v]};
  };
  // e は v に入る有向辺
  auto fve = [&](Data x, auto& e) -> Data {
    x.se = B[e.id] * x.se + x.fi * C[e.id];
    return x;
  };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  vc<mint> ANS(N);
  FOR(v, N) ANS[v] = dp[v].se;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
