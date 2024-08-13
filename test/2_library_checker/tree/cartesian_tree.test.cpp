#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/cartesian_tree.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  CartesianTree<int, 1> CT(A);
  auto& ANS = CT.par;
  FOR(i, N) if (ANS[i] == -1) ANS[i] = i;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
