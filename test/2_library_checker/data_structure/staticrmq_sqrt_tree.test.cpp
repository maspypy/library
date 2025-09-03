#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/min.hpp"
#include "ds/sqrt_tree.hpp"

void solve() {
  INT(N, Q);
  VEC(int, A, N);
  SQRT_Tree<Monoid_Min<int>> seg(A);
  FOR(Q) {
    INT(L, R);
    print(seg.prod(L, R));
  }
}

signed main() {
  solve();
  return 0;
}