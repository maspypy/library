#define PROBLEM "https://atcoder.jp/contests/abc234/tasks/abc234_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/kdtree/kdtree.hpp"

void solve() {
  LL(N, K);
  vc<int> X(N), Y(N);
  vc<int> V(N);
  FOR(i, N) {
    INT(a, b);
    X[i] = a, Y[i] = b, V[i] = i;
  }
  KDTree<int, int> KDT(X, Y, V);

  int x_min = MIN(X);
  int x_max = MAX(X);
  int y_min = MIN(Y);
  int y_max = MAX(Y);

  vc<pair<int, int>> ANS;
  FOR(i, N) {
    ll a = X[i] - K, b = X[i] + K + 1, c = Y[i] - K, d = Y[i] + K + 1;
    chmax(a, x_min), chmin(b, x_max + 1);
    chmax(c, y_min), chmin(d, y_max + 1);
    vc<int> I = KDT.collect_rect(a, b, c, d);
    sort(all(I));
    for (auto&& j: I) {
      if (i >= j) continue;
      ll dx = X[i] - X[j], dy = Y[i] - Y[j];
      if (dx * dx + dy * dy <= K * K) { ANS.eb(i, j); }
    }
  }
  print(len(ANS));
  for (auto&& [i, j]: ANS) print(1 + i, 1 + j);
}

signed main() {
  solve();

  return 0;
}
