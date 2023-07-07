#define PROBLEM "https://yukicoder.me/problems/no/1038"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "graph/centroid.hpp"

void solve() {
  LL(N, Q);
  Graph<int> G(N);
  G.read_tree();

  using T = tuple<ll, ll, ll>;
  VEC(T, query, Q);
  for (auto&& [a, b, c]: query) --a;

  // 頂点 -> クエリ

  vc<vi> query_at(N);
  FOR(q, Q) query_at[get<0>(query[q])].eb(q);

  Centroid_Decomposition<decltype(G)> CD(G);
  vi ANS(Q);
  FenwickTree<Monoid_Add<ll>> bit(N + 10);

  FOR(root, N) {
    auto [V, dp, indptr] = CD.collect_dist(root);
    auto calc = [&](vc<int> V, vc<int> dp, int sgn) -> void {
      vc<T> event;
      FOR(i, len(V)) {
        int v = V[i];
        int dv = dp[i];
        for (auto&& q: query_at[v]) { event.eb(q, v, dv); }
      }
      sort(all(event));
      for (auto&& [qid, v, dv]: event) {
        auto [_, y, z] = query[qid];
        ll add = bit.sum(0, dv + 1);
        ANS[qid] += add * sgn;
        if (dv <= y) {
          bit.add(0, z);
          bit.add(y - dv + 1, -z);
        }
      }
      for (auto&& [qid, v, dv]: event) {
        auto [_, y, z] = query[qid];
        if (dv <= y) {
          bit.add(0, -z);
          bit.add(y - dv + 1, +z);
        }
      }
    };
    calc(V, dp, +1);
    FOR(i, 1, len(indptr) - 1) {
      int l = indptr[i], r = indptr[i + 1];
      calc({V.begin() + l, V.begin() + r}, {dp.begin() + l, dp.begin() + r},
           -1);
    }
  }
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}