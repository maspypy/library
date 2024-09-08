#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_multiset.hpp"

void solve() {
  LL(N, M, K);
  My_Multiset X(N);
  auto root = X.new_root();
  VEC(ll, A, N);
  vi ANS;
  FOR(i, M - 1) root = X.add(root, A[i], 1);
  FOR(i, M - 1, N) {
    root = X.add(root, A[i], 1);
    ANS.eb(X.prefix_kth(root, K).se);
    root = X.add(root, A[i - M + 1], -1);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}