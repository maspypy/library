#include "graph/base.hpp"

/*
block-cut tree を、block に通常の頂点を隣接させて拡張しておく
https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg
[0, n)：もとの頂点 [n, n + n_block)：block
関節点：[0, n) のうちで、degree >= 2 を満たすもの

孤立点は、1 点だけからなる block
*/
template <typename GT>
Graph<int, 0> block_cut(GT& G) {
  int n = G.N;
  vc<int> low(n), ord(n), st;
  vc<bool> used(n);
  st.reserve(n);
  int nxt = n;
  int k = 0;
  vc<pair<int, int>> edges;

  auto dfs = [&](auto& dfs, int v, int p) -> void {
    st.eb(v);
    used[v] = 1;
    low[v] = ord[v] = k++;
    int child = 0;
    for (auto&& e: G[v]) {
      if (e.to == p) continue;
      if (!used[e.to]) {
        ++child;
        int s = len(st);
        dfs(dfs, e.to, v);
        chmin(low[v], low[e.to]);
        if ((p == -1 && child > 1) || (p != -1 && low[e.to] >= ord[v])) {
          edges.eb(nxt, v);
          while (len(st) > s) {
            edges.eb(nxt, st.back());
            st.pop_back();
          }
          ++nxt;
        }
      } else {
        chmin(low[v], ord[e.to]);
      }
    }
  };
  FOR(v, n) if (!used[v]) {
    dfs(dfs, v, -1);
    for (auto&& x: st) { edges.eb(nxt, x); }
    ++nxt;
    st.clear();
  }
  Graph<int, 0> BCT(nxt);
  for (auto&& [a, b]: edges) BCT.add(a, b);
  BCT.build();
  return BCT;
}