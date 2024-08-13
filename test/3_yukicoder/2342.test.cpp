#define PROBLEM "https://yukicoder.me/problems/no/2342"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/sum_affine.hpp"
#include "mod/modint.hpp"
#include "graph/tree.hpp"
#include "ds/kdtree/kdtree_acted_monoid.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);
  VEC(mint, A, N);
  vc<int> X(N), Y(N);
  FOR(v, N) {
    X[v] = tree.LID[v];
    Y[v] = tree.depth[v];
  }
  KDTree_ActedMonoid<ActedMonoid_Sum_Affine<mint>, int> KDT(X, Y, A);

  FOR(Q) {
    LL(t);
    if (t == 1) {
      INT(v);
      --v;
      print(KDT.prod(X[v], X[v] + 1, Y[v], Y[v] + 1));
    }
    if (t == 2) {
      INT(v, K, C, D);
      --v;
      assert(K <= 10);
      pair<mint, mint> p = {C, D};
      /*
      どの点からどの深さに足すか？
      一番浅いところからのみ足されるようにする
      */
      vc<int> vs = {v};
      FOR(K) {
        int nxt = tree.parent[vs.back()];
        if (nxt == -1) break;
        vs.eb(nxt);
      }
      int n = len(vs);
      // depth closed range
      vc<pair<int, int>> range(n);
      FOR(i, n) range[i] = {tree.depth[vs[i]], tree.depth[vs[i]] + K - i};
      FOR(i, n) {
        auto [l, r] = range[i];
        if (i + 1 < n) {
          auto [l1, r1] = range[i + 1];
          chmax(l, r1 + 1);
        }
        int v = vs[i];
        KDT.apply(tree.LID[v], tree.RID[v], l, r + 1, p);
      }
    }
    if (t == 3) {
      INT(v, C, D);
      --v;
      pair<mint, mint> p = {C, D};
      KDT.apply(tree.LID[v], tree.RID[v], 0, infty<int>, p);
    }
    if (t == 4) {
      INT(u, v, C, D);
      --u, --v;
      pair<mint, mint> p = {C, D};
      for (auto&& [a, b]: tree.get_path_decomposition(u, v, false)) {
        if (a > b) swap(a, b);
        ++b;
        KDT.apply(a, b, 0, infty<int>, p);
      }
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
