#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/add.hpp"
#include "ds/segtree/segtree2d.hpp"

void solve() {
  LL(N, Q);
  vc<int> X(N), Y(N);
  vi W(N);
  FOR(i, N) {
    LL(x, y, w);
    X[i] = x, Y[i] = y, W[i] = w;
  }
  using QQ = tuple<ll, ll, ll, ll>;
  vc<QQ> query(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(x, y, w);
      X.eb(x);
      Y.eb(y);
      W.eb(0);
      query[q] = mt(-1, x, y, w);
    } else {
      LL(a, b, c, d);
      query[q] = mt(a, c, b, d);
    }
  }

  using Mono = Monoid_Add<ll>;

  SegTree2D<Mono, int, false> seg(X, Y, W);

  FOR(q, Q) {
    auto [a, b, c, d] = query[q];
    if (a == -1) {
      seg.multiply(b, c, d);
    } else {
      print(seg.prod(a, b, c, d));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
