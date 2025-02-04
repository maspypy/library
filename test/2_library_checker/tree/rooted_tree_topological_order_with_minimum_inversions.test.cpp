#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions"

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
  INT(N);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(p, v);
  }
  G.build();
  Tree<decltype(G)> tree(G);

  vc<Data> A(N);
  FOR(i, N) A[i].ans = 0;
  FOR(i, N) {
    INT(x);
    A[i].x0 = x;
  }
  FOR(i, N) {
    INT(x);
    A[i].x1 = x;
  }

  auto comp = [&](Data x, Data y) -> bool { return x.x0 * y.x1 > x.x1 * y.x0; };
  auto [ord, x] = optimal_product_on_tree<decltype(tree), Mono, true>(tree, A, comp);
  print(x.ans);
  print(ord);
}

signed main() { solve(); }