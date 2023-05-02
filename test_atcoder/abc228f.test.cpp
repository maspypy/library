#define PROBLEM "https://atcoder.jp/contests/abc228/tasks/abc228_f"

#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/max.hpp"
#include "ds/cumsum_2d.hpp"
#include "ds/segtree/segtree_2d_dense.hpp"

void solve() {
  LL(H, W, h1, w1, h2, w2);
  chmin(h2, h1), chmin(w2, w1);
  VV(ll, A, H, W);
  Cumsum_2D<Monoid_Add<ll>> X(A);
  vv(ll, B, H - h2 + 1, W - w2 + 1);
  FOR(x, H - h2 + 1) FOR(y, W - w2 + 1) {
    B[x][y] = X.sum(x, x + h2, y, y + w2);
  }

  ll ANS = 0;
  SegTree_2D_Dense<Monoid_Max<ll>> seg(B);
  FOR(x, H - h1 + 1) FOR(y, W - w1 + 1) {
    ll a = X.sum(x, x + h1, y, y + w1);
    ll b = seg.prod(x, x + h1 - h2 + 1, y, y + w1 - w2 + 1);
    chmax(ANS, a - b);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
