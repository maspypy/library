#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_2d.hpp"

void solve() {
  LL(N, Q);
  vi X(N), Y(N), W(N);
  FOR(i, N) {
    LL(x, y, w);
    X[i] = x, Y[i] = y, W[i] = w;
  }
  FenwickTree_2D<Monoid_Add<ll>, ll, false> bit(X, Y, W);
  FOR(Q) {
    LL(l, d, r, u);
    print(bit.sum(l, r, d, u));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
