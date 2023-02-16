#define PROBLEM "https://atcoder.jp/contests/abc240/tasks/abc240_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/sort_substrings.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/max.hpp"

void solve() {
  LL(N);
  STR(S);
  ll LIM = 1;
  while (LIM * LIM < 2 * N) LIM++;
  LIM += 10;
  chmin(LIM, N);
  auto rank = sort_substrings(S, LIM);

  // 文字列ランク -> (L, R)
  ll mx = 0;
  FOR(i, len(rank)) chmax(mx, MAX(rank[i]));
  vvc<pair<int, int>> LR(mx + 1);
  FOR_R(i, N) FOR(j, LIM + 1) {
    int r = rank[i][j];
    if (r != -1) LR[r].eb(i, i + j);
  }

  using Mono = Monoid_Max<int>;
  SegTree<Mono> seg(N + 1);
  seg.set(0, 0);

  vc<int> DP(N + 1, -infty<int>);
  DP[0] = 0;

  FOR(rk, mx + 1) {
    for (auto&& [L, R]: LR[rk]) {
      ll x = 1 + seg.prod(0, L + 1);
      if (DP[R] < x) seg.set(R, x);
      chmax(DP[R], x);
    }
  }
  print(seg.prod_all());
}

signed main() {
  solve();
  return 0;
}
