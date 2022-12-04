#define PROBLEM "https://yukicoder.me/problems/no/1197"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "graph/ds/lazy_tree_monoid.hpp"

void solve() {
  LL(N, K, Q);
  VEC(int, C, K);
  for (auto&& v: C) --v;

  Graph<int, 0> G(N);
  G.read_tree();

  TREE<decltype(G)> tree(G);
  using AM = ActedMonoid_Sum_Add<ll>;

  Lazy_Tree_Monoid<decltype(tree), AM> X(tree, vi(N, 0));

  FOR(i, K) { X.apply_path(0, C[i], 1); }

  ll d_sm = 0;
  auto& dep = tree.depth;
  FOR(i, K) d_sm += dep[C[i]];

  bool out = 0;

  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(k, d);
      --k;
      --d;
      d_sm -= dep[C[k]];
      X.apply_path(0, C[k], -1);
      C[k] = d;
      d_sm += dep[C[k]];
      X.apply_path(0, C[k], 1);
    }
    if (t == 2) {
      LL(v);
      --v;
      ll ANS = dep[v] * K + d_sm;
      ANS -= 2 * X.prod_path(0, v);
      ANS += 2 * K;
      print(ANS);
      out = 1;
    }
  }
  if (!out) print();
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
