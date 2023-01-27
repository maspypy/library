#define PROBLEM "https://yukicoder.me/problems/no/1216"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "graph/ds/static_tree_monoid.hpp"
#include "ds/fenwicktree/fenwicktree_2d.hpp"

void solve() {
  LL(N, Q);
  Graph<ll, 0> G(N);
  G.read_tree(1);
  Tree<decltype(G)> tree(G);
  vi dat(N - 1);
  FOR(i, N - 1) dat[i] = G.edges[i].cost;
  Static_Tree_Monoid<decltype(tree), Monoid_Add<ll>, 1> TM(tree, dat);

  auto& dist = tree.depth_weighted;
  /*
  ・頂点 v に、根に着くのが時刻 t であるようなものを追加
  ・（消す）はじめて消えて到達するのが w であるとき、w に -1 個追加
  euler tour をとって
  */
  using T = tuple<int, int, ll>;
  vc<T> query;
  auto& LID = tree.LID;

  vi X, Y;
  iota(all(X), 0);
  FOR(Q) {
    LL(tp, v, t, l);
    --v;
    if (tp == 0) {
      // 追加クエリ
      // 消えないで到達できる最大の頂点
      auto check = [&](auto e) -> bool { return e <= l; };
      auto to = TM.max_path(check, v, 0);
      int w = tree.parent[to];

      query.eb(1, LID[v], t + dist[v]);
      X.eb(LID[v]);
      Y.eb(t + dist[v]);
      if (w != -1) {
        X.eb(LID[w]);
        Y.eb(t + dist[v]);
        query.eb(-1, LID[w], t + dist[v]);
      }
    }
    if (tp == 1) { query.eb(0, v, t); }
  }

  FenwickTree_2D<Monoid_Add<int>, ll, true> bit(X, Y);

  for (auto&& [tp, x, t]: query) {
    if (tp == 0) {
      int v = x;
      int l = tree.LID[v], r = tree.RID[v];
      t += dist[v];
      ll ANS = bit.sum(l, r, 0, t + 1);
      print(ANS);
    }
    if (tp == 1) { bit.add(x, t, 1); }
    if (tp == -1) { bit.add(x, t, -1); }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
