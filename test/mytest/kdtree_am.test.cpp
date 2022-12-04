#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/kdtree/kdtree_acted_monoid.hpp"
#include "alg/acted_monoid/summax_add.hpp"
#include "random/base.hpp"

void test() {
  ll LIM = RNG(1, 100);
  int N = RNG(1, 100);
  using AM = ActedMonoid_SumMax_Add<int>;
  using MX = AM::Monoid_X;

  vc<int> dat[100][100];

  vc<int> X, Y;
  vc<typename MX::value_type> val;
  FOR(i, N) {
    int x = RNG(0, LIM);
    int y = RNG(0, LIM);
    int v = RNG(0, 100);
    dat[x][y].eb(v);
    X.eb(x), Y.eb(y), val.eb(v, v);
  }
  KDTree_ActedMonoid<AM, int> KDT(X, Y, val);

  int Q = 100;
  FOR(Q) {
    int t = RNG(0, 4);
    int xl = RNG(0, LIM), xr = RNG(0, LIM), yl = RNG(0, LIM), yr = RNG(0, LIM);
    if (xl > xr) swap(xl, xr);
    if (yl > yr) swap(yl, yr);
    if (t == 0) {
      // multiply
      int k = RNG(0, N);
      int x = X[k], y = Y[k];
      int v = RNG(0, 100);
      dat[x][y].eb(v);
      KDT.multiply(x, y, {v, v});
    }
    if (t == 1) {
      // prod
      int sm = 0, mx = MX::unit().se;
      FOR(i, xl, xr) FOR(j, yl, yr) {
        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);
      }
      auto res = KDT.prod(xl, xr, yl, yr);
      assert(res.fi == sm && res.se == mx);
    }
    if (t == 2) {
      // prod all
      int sm = 0, mx = MX::unit().se;
      FOR(i, LIM) FOR(j, LIM) {
        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);
      }
      auto res = KDT.prod_all();
      assert(res.fi == sm && res.se == mx);
    }
    if (t == 3) {
      // apply
      int a = RNG(0, 10);
      FOR(i, xl, xr) FOR(j, yl, yr) {
        for (auto&& x: dat[i][j]) x += a;
      }
      KDT.apply(xl, xr, yl, yr, a);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  FOR(100) test();
  solve();

  return 0;
}
