#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "ds/segtree/segtree_2d.hpp"
#include "alg/monoid/min.hpp"

void test() {
  FOR(N, 100) {
    FOR(Q, 100) {
      vc<int> X(N), Y(N), val(N);
      FOR(i, N) X[i] = RNG(0, 5), Y[i] = RNG(0, 5), val[i] = RNG(0, 100);
      SegTree_2D<Monoid_Min<int>, int, true> seg(X, Y, val);
      FOR(Q) {
        int t = RNG(0, 3);
        if (N == 0) t = 2;
        if (t == 0) {
          int i = RNG(0, N);
          val[i] = RNG(0, 100);
          seg.set(i, val[i]);
        }
        if (t == 1) {
          int i = RNG(0, N);
          int x = RNG(0, 100);
          chmin(val[i], x);
          seg.multiply(i, val[i]);
        }
        if (t == 2) {
          int a = RNG(0, 5), b = RNG(0, 5), c = RNG(0, 5), d = RNG(0, 5);
          if (a > b) swap(a, b);
          if (c > d) swap(c, d);
          int ans = infty<int>;
          FOR(i, N) {
            if (a <= X[i] && X[i] < b && c <= Y[i] && Y[i] < d)
              chmin(ans, val[i]);
          }
          assert(ans == seg.prod(a, b, c, d));
        }
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}
