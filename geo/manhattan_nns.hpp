#include "ds/segtree/segtree.hpp"
#include "alg/monoid/min_idx.hpp"

// 点群 FRM から点群 TO への最近点探索
// vector の pair を返す：dist, nbd_idx
template <typename X = ll>
pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {
  assert(len(TO) >= 1);
  int N = len(FRM), M = len(TO);
  vc<pair<X, X>> points(N + M);
  FOR(i, N) points[i] = FRM[i];
  FOR(i, M) points[N + i] = TO[i];
  vc<X> Y(M);
  FOR(i, M) Y[i] = TO[i].se;
  UNIQUE(Y);

  vc<int> nbd_idx(N, -1);
  vc<X> dist(N, infty<X>);

  auto add_ans = [&](int i, int j) -> void {
    if (j == -1) return;
    X dx = points[i].fi - points[j].fi;
    X dy = points[i].se - points[j].se;
    if (chmin(dist[i], abs(dx) + abs(dy))) nbd_idx[i] = j - N;
  };

  vc<int> I(N + M);
  iota(all(I), 0);
  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi); });
  auto calc = [&]() -> void {
    SegTree<Monoid_Min_Idx<X>> seg1(len(Y)), seg2(len(Y));
    for (auto&& i: I) {
      auto [x, y] = points[i];
      int idx = LB(Y, y);
      if (i < N) {
        add_ans(i, seg1.prod(idx, len(Y)).se);
        add_ans(i, seg2.prod(0, idx).se);
      }
      elif (i >= N) {
        seg1.set(idx, {y - x, i});
        seg2.set(idx, {-(x + y), i});
      }
    }
  };

  calc();
  reverse(all(I));
  FOR(i, N + M) points[i].fi *= -1;
  calc();

  return {dist, nbd_idx};
};