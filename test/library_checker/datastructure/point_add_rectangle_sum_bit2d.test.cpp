#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_2d.hpp"

void solve() {
  LL(N, Q);
  vc<u32> X(N), Y(N);
  vc<u64> W(N);
  FOR(i, N) read(X[i], Y[i], W[i]);
  using QQ = tuple<u32, u32, u32, u32>;
  vc<QQ> query(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      U32(x, y, w);
      X.eb(x);
      Y.eb(y);
      W.eb(0);
      query[q] = mt(-1, x, y, w);
    } else {
      U32(a, b, c, d);
      query[q] = mt(a, c, b, d);
    }
  }

  FenwickTree_2D<Monoid_Add<u64>, u32, false> bit(X, Y, W);
  FOR(q, Q) {
    auto [a, b, c, d] = query[q];
    if (a == u32(-1)) {
      bit.add(b, c, d);
    } else {
      print(bit.prod(a, b, c, d));
    }
  }
}

signed main() {
  solve();

  return 0;
}
