#define PROBLEM "https://yukicoder.me/problems/no/1212"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/ds/tree_monoid.hpp"
#include "alg/monoid/min.hpp"
#include "ds/segtree/segtree.hpp"

void solve() {
  INT(N);
  Graph<ll, 0> G(N);
  G.read_tree(1);

  Tree<decltype(G)> tree(G);

  LL(Q);
  VEC(pi, query, Q);
  for (auto&& [x, y]: query) --x, --y;
  vvc<int> QIDS(N);
  FOR(q, Q) {
    auto [x, y] = query[q];
    int lca = tree.lca(x, y);
    QIDS[lca].eb(q);
  }

  auto& par = tree.parent;

  using Mono = Monoid_Min<ll>;

  // 接続先 → 辺重み を管理するセグ木。
  // これを使って、dat[edge] = 親から見て edge 以外のところの min を作る
  SegTree<Mono> seg(N);
  vi dat(N - 1);
  vi dat_v(N);                 // 子方向の min
  vi dat_par(N, Mono::unit()); // 親方向

  auto build_at = [&](int v) -> void {
    for (auto&& e: G[v]) {
      if (e.to == par[v]) continue;
      seg.set(e.to, e.cost);
    }
  };
  auto reset_at = [&](int v) -> void {
    for (auto&& e: G[v]) {
      if (e.to == par[v]) continue;
      seg.set(e.to, Mono::unit());
    }
  };

  FOR(v, N) {
    build_at(v);
    dat_v[v] = seg.prod_all();
    for (auto&& e: G[v]) {
      if (e.to == par[v]) continue;
      dat_par[e.to] = e.cost;
      dat[e.id] = Mono::op(seg.prod(0, e.to), seg.prod(e.to + 1, N));
    }
    reset_at(v);
  }

  Tree_Monoid<decltype(tree), Mono, true> X(tree, dat);
  vi ANS(Q);
  FOR(lca, N) {
    build_at(lca);
    for (auto&& q: QIDS[lca]) {
      auto [S, T] = query[q];
      if (S > T) swap(S, T);
      ll base = tree.dist(S, T, 1);
      ll best = Mono::unit();

      // S, T での寄り道
      if (S != lca) chmin(best, dat_v[S]);
      if (T != lca) chmin(best, dat_v[T]);
      // lca での寄り道
      chmin(best, dat_par[lca]);
      vc<int> ng = {-1, N};
      if (S != lca) ng.eb(tree.jump(lca, S, 1));
      if (T != lca) ng.eb(tree.jump(lca, T, 1));
      sort(all(ng));
      FOR(k, len(ng) - 1) { chmin(best, seg.prod(ng[k] + 1, ng[k + 1])); }
      // S → lca の道中
      if (lca != S) {
        int v = tree.jump(lca, S, 1);
        chmin(best, X.prod_path(S, v));
      }
      if (lca != T) {
        int v = tree.jump(lca, T, 1);
        chmin(best, X.prod_path(T, v));
      }
      ANS[q] = (best == Mono::unit() ? -1 : base + 2 * best);
    }
    reset_at(lca);
  }
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
