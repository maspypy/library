#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"
#include "my_template.hpp"
#include "other/io2.hpp"
#include "graph/dsu_on_tree.hpp"
#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, K);
  Graph G(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    G.add(a, b);
  }
  G.build();
  Tree T(G);
  VEC(pi, CD, N);
  for (auto&& [c, d] : CD) --c, --d;
  /*
  頂点になっている：+x
  連結成分ごとに、ロスの min を持たせる
  */
  vc<int> tree(K, 1);
  vc<int> history;
  ll ans = 0;
  vc<int> ANS(N);
  UnionFind uf(K);

  auto eval = [&](int v) -> int {
    return (tree[v] ? uf.size(v) - 1 : uf.size(v));
  };

  auto ADD = [&](int v) -> void {
    auto [c, d] = CD[v];
    history.eb(c), history.eb(d);
    c = uf[c], d = uf[d];
    if (c == d) {
      if (tree[c]) tree[c] = 0, ans++;
      return;
    }
    ans -= eval(c) + eval(d);
    uf.merge(c, d);
    int r = uf[c];
    tree[r] = tree[c] && tree[d];
    ans += eval(r);
  };
  auto QUERY = [&](int v) -> void { ANS[v] = ans; };
  auto RESET = [&]() -> void {
    for (auto&& v : history) {
      uf.dat[v] = -1;
      tree[v] = 1;
    }
    ans = 0;
    history.clear();
  };
  DSU_on_Tree(T, ADD, QUERY, RESET);
  for (auto&& x : ANS) print(x);
}

signed main() {
  solve();

  return 0;
}
