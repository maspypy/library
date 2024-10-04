#define PROBLEM "https://yukicoder.me/problems/no/2909"
#define ERROR 1e-5
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "ds/kdtree/kdtree.hpp"

/*
許容誤差について：V=infty と扱ってよい
単に最近傍探索ということになる
・直接行く
・S -> 駅 -> 駅 -> T
*/

using Re = double;

void solve() {
  LL(N, M, K);
  vc<int> A(K + 1), B(K + 1);
  vc<int> X(N), Y(N);
  read(A[0], B[0]);
  FOR(i, N) read(X[i], Y[i]);
  FOR(i, 1, K + 1) { read(A[i], B[i]); }

  KDTree<int> KDT(X, Y);
  vc<Re> D(K + 1);
  FOR(i, K + 1) {
    int j = KDT.nearest_neighbor_search<ll>(A[i], B[i]);
    ll dx = A[i] - X[j];
    ll dy = B[i] - Y[j];
    D[i] = sqrtl(dx * dx + dy * dy);
  }

  Re ANS = 0;
  FOR(k, 1, K + 1) {
    Re ans = D[0] + D[k];
    ll dx = A[k] - A[0];
    ll dy = B[k] - B[0];
    Re d = sqrtl(dx * dx + dy * dy);
    chmin(ans, d);
    ANS += ans;
  }

  ANS *= 2;
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
