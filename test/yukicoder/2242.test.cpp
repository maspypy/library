#define PROBLEM "https://yukicoder.me/problems/no/2242"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "alg/monoid/max.hpp"
#include "ds/doubling.hpp"

void solve() {
  /*
  T を増やしていく → 最後に目的のところに行く
  欲しいもの：
  T → H<=T に対する max T
  */
  LL(N);
  VEC(int, H, N);
  VEC(int, T, N);
  Dynamic_SegTree_Sparse<Monoid_Max<int>, 0, 200'100> seg(0, infty<int> + 10);
  auto root = seg.new_root();
  FOR(i, N) { root = seg.multiply(root, H[i], T[i]); }

  auto X = T;
  UNIQUE(X);
  int n = len(X);

  Doubling<Monoid_Add<int>, 20> D(n);

  FOR(i, n) {
    int x = X[i];
    int y = seg.prod(root, 0, X[i] + 1);
    chmax(y, x);
    int to = LB(X, y);
    D.add(i, to, to - i);
  }
  D.build();

  auto F = [&](int a, int b) -> int {
    if (a == b) return 0;
    // T >= h となる最小
    int s = LB(X, T[a]);
    int t = LB(X, H[b]);
    if (s >= t) { return 1; }
    auto check = [&](auto e) -> bool { return e < t - s; };
    ll step = D.max_step(check, s);
    ll ANS = step + 2;
    if (ANS > N) ANS = -1;
    return ANS;
  };

  INT(Q);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(F(a, b));
  }
}

signed main() {
  solve();
  return 0;
}