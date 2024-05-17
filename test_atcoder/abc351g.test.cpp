#define PROBLEM "https://atcoder.jp/contests/abc351/tasks/abc351_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/dynamic_tree_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

using Data = pair<mint, mint>;

void solve() {
  LL(N, Q);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(--p, v);
  }
  VEC(mint, A, N);
  G.build();
  Tree<decltype(G)> tree(G);

  Dynamic_Tree_Dp<decltype(tree), Data> X(tree);
  auto single = [&](int v) -> Data { return {1, A[v]}; };
  auto rake = [&](Data x, Data y, int u, int v) -> Data {
    mint c = y.se;
    auto [a, b] = x;
    return {a * c, b * c};
  };
  auto compress = [&](Data x, Data y, int u, int v, int w) -> Data {
    auto [a, b] = x;
    auto [c, d] = y;
    return {a * c, a * d + b};
  };
  X.init_dp(single, rake, compress);

  FOR(Q) {
    INT(v, x);
    --v;
    A[v] = x;
    Data a = X.recalc(v, single, rake, compress);
    print(a.se);
  }
}

signed main() {
  solve();
  return 0;
}