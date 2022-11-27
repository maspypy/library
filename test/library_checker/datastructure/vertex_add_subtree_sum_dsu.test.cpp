#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/dsu_on_tree.hpp"
#include "ds/fenwick.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  G.build();
  TREE tree(G);

  vi ANS(Q, -1);
  vvc<pair<int, int>> query(N);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      query[v].eb(q, x);
    }
    if (t == 1) {
      LL(v);
      query[v].eb(q, -1);
    }
  }

  FenwickTree<Monoid_Add<ll>> bit(Q);
  vc<pair<int, int>> history;
  ll base_sum = 0;

  auto ADD = [&](int v) -> void {
    base_sum += A[v];
    for (auto&& [q, x]: query[v]) {
      if (x != -1) {
        bit.add(q, x);
        history.eb(q, x);
      }
    }
  };
  auto QUERY = [&](int v) -> void {
    for (auto&& [q, x]: query[v]) {
      if (x == -1) ANS[q] = base_sum + bit.sum(q);
    }
  };
  auto RESET = [&]() -> void {
    base_sum = 0;
    for (auto&& [q, x]: history) bit.add(q, -x);
    history.clear();
  };
  DSU_on_Tree(tree, ADD, QUERY, RESET);
  for (auto&& ans: ANS)
    if (ans != -1) print(ans);
}

signed main() {
  solve();

  return 0;
}
