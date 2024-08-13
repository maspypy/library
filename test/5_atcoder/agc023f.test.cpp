#define PROBLEM "https://atcoder.jp/contests/agc023/tasks/agc023_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/optimal_product_on_tree.hpp"

struct Data {
  ll ans, x0, x1;
};

struct Mono {
  using value_type = Data;
  using X = value_type;
  static X op(X x, X y) {
    X z;
    z.ans = x.ans + y.ans + x.x1 * y.x0;
    z.x0 = x.x0 + y.x0, z.x1 = x.x1 + y.x1;
    return z;
  }
  static constexpr X unit() { return Data{0, 0, 0}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);
  Graph<bool, 1> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(--p, v);
  }
  G.build();
  Tree<decltype(G)> tree(G);
  vc<Data> A(N);
  FOR(v, N) {
    INT(x);
    if (x == 0) { A[v] = Data{0, 1, 0}; }
    if (x == 1) { A[v] = Data{0, 0, 1}; }
  }
  auto comp = [&](Data x, Data y) -> bool { return x.x0 * y.x1 > x.x1 * y.x0; };
  auto [ord, x]
      = optimal_product_on_tree<decltype(tree), Mono, true>(tree, A, comp);
  print(x.ans);
}

signed main() {
  solve();
  return 0;
}
