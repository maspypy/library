#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwick2d.hpp"

void solve() {
  LL(N, Q);
  vi X(N), Y(N), W(N);
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

  Fenwick2D<Monoid_Add<ll>, ll, false> bit(X, Y, W);
  FOR(q, Q) {
    auto [a, b, c, d] = query[q];
    if (a == -1) {
      bit.add(b, c, d);
    } else {
      print(bit.prod(a, b, c, d));
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
