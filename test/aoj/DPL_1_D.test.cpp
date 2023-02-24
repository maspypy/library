#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/longest_increasing_subsequence.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  print(longest_increasing_subsequence(A).fi);
}

signed main() {
  solve();
  return 0;
}
