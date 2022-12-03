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

  CentroidDecomposition CD(G);
  vi ANS(Q);
  FenwickTree<Monoid_Add<ll>> bit(N + 10);

  FOR(root, N) {
    auto dats = CD.collect_dist(root);
    FOR(i, len(dats)) {
      auto dat = dats[i];
      // qid, v, dv
      vc<T> event;
      for (auto&& [v, dv]: dat) {
        for (auto&& q: query_at[v]) { event.eb(q, v, dv); }
      }
      sort(all(event));
      for (auto&& [qid, v, dv]: event) {
        auto [_, y, z] = query[qid];
        ll add = bit.sum(0, dv + 1);
        ANS[qid] += (i == 0 ? add : -add);
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
    }
  }
  for (auto&& x: ANS) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
