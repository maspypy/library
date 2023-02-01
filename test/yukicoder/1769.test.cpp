#define PROBLEM "https://yukicoder.me/problems/no/1769"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/centroid.hpp"
#include "graph/tree.hpp"
#include "ds/hashmap.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree(1);

  vi ANS(N);
  Centroid_Decomposition<decltype(G)> CD(G);
  HashMap<vc<int>> MP;

  FOR(root, N) {
    vc<int> conv;
    Graph<int, 1> G;
    tie(conv, G) = CD.get_subgraph(root);
    const int N = G.N;
    // lca が 0 であるような path について解く
    vc<int> A(N);
    FOR(v, N) {
      for (auto&& e: G[v]) A[e.to] = A[v] ^ e.cost;
    }
    Tree<decltype(G)> tree(G, 0, false);

    // 根以外の点に対して、dep=1 の LA
    vc<int> par_1(N, -1);
    FOR(v, 1, N) {
      int p = tree.parent[v];
      par_1[v] = (p == 0 ? v : par_1[p]);
    }

    // 色 -> 頂点集合
    MP.reset();
    FOR(v, 1, N) if (A[v] != A[0]) MP[A[v]].eb(v);

    // 根の次の点 -> 頂点の個数
    vc<int> CNT(N);
    FOR(v, N) if (par_1[v] == v) CNT[v] = tree.subtree_size(v);

    MP.enumerate_all([&](auto key, auto V) -> void {
      vc<int> W;
      for (auto&& x: V) {
        if (len(W) && tree.in_subtree(x, W.back())) { continue; }
        W.eb(x);
      }
      V = W;
      // 到達可能な点の個数を更新
      ll s = N;
      for (auto&& v: V) {
        int x = tree.subtree_size(v);
        CNT[par_1[v]] -= x;
        s -= x;
      }
      // 各 v からの答を計算
      for (auto&& v: V) { ANS[conv[v]] += s - CNT[par_1[v]]; }
      for (auto&& v: V) {
        int x = tree.subtree_size(v);
        CNT[par_1[v]] += x;
      }
    });

    // 根から進む場合
    vc<int> OK(N);
    OK[0] = 1;
    FOR(v, N) {
      if (!OK[v]) continue;
      for (auto&& e: G[v]) {
        if (A[e.to] == A[0]) continue;
        OK[e.to] = 1;
      }
    }
    ANS[conv[0]] += SUM<int>(OK) - 1;
  }
  print(SUM<ll>(ANS));
}

signed main() {
  solve();
  return 0;
}
