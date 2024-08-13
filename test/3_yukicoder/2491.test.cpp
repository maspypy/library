#define PROBLEM "https://yukicoder.me/problems/no/2491"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree.hpp"
#include "graph/centroid_decomposition.hpp"
#include "ds/offline_query/rectangle_add_point_sum.hpp"
#include "alg/monoid/add_pair.hpp"

void solve() {
  INT(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  vc<int> D(N);
  FOR(i, 1, N) D[i] = tree.dist(i - 1, i);

  ll base = SUM<ll>(D);
  vi ANS(N, base);

  /*
  i -> i+1, 距離 d[i+1]
  やること
  i+1 からの距離が e かつ番号が i 以下の点に対して
  max(0, d - 1 - e) を引くことができる

  rectangle add rectangle sum
  */

  FOR(i, 1, N) {
    for (auto& e: G[i]) {
      if (e.to < i) { ANS[e.to] -= max(0, D[i] - 1 - 1); }
    }
  }

  auto f = [&](vc<int>& par, vc<int>& V, int n1, int n2) -> void {
    int n = 1 + n1 + n2;
    vc<int> dep(n);
    FOR(i, 1, n) dep[i] += dep[par[i]] + 1;

    auto F = [&](int L1, int R1, int L2, int R2) -> void {
      // dep range, index range
      Rectangle_Add_Point_Sum<Monoid_Add_Pair<ll>, int, true> X;
      FOR(i, L1, R1) {
        int v = V[i];
        if (v == 0) continue;
        int d = D[v];
        if (d <= 2) continue;
        // 距離が d-2 以下
        int d1 = 1, d2 = d - 2 - dep[i];
        if (d1 > d2) continue;
        // 足すもの：(d - 1 - dep[i]) - x
        X.add_query(d1, d2 + 1, 0, v, {d - 1 - dep[i], -1});
      }
      FOR(i, L2, R2) { X.sum_query(dep[i], V[i]); }
      auto res = X.calc();
      FOR(i, L2, R2) {
        auto [a, b] = res[i - L2];
        ANS[V[i]] -= a + b * dep[i];
      }
    };
    F(1, 1 + n1, 1 + n1, 1 + n1 + n2);
    F(1 + n1, 1 + n1 + n2, 1, 1 + n1);
  };

  centroid_decomposition<1, decltype(G)>(G, f);
  for (auto& x: ANS) print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
