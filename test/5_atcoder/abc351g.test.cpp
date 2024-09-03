#define PROBLEM "https://atcoder.jp/contests/abc351/tasks/abc351_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/dynamic_tree_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

using Data = pair<mint, mint>;

struct DP {
  using value_type = Data;
  static Data rake(Data& L, Data& R) {
    mint c = R.se;
    auto [a, b] = L;
    return {a * c, b * c};
  }
  static Data compress(Data& L, Data& R) {
    auto [a, b] = L;
    auto [c, d] = R;
    return {a * c, a * d + b};
  }
};

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

  auto single = [&](int v) -> Data { return {1, A[v]}; };
  Dynamic_Tree_Dp<decltype(tree), DP> X(tree, single);
  FOR(Q) {
    INT(v, x);
    --v;
    A[v] = x;
    X.set(v, single(v));
    auto ans = X.prod_all();
    print(ans.se);
  }
}

signed main() {
  solve();
  return 0;
}