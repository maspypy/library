#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/longest_increasing_subsequence.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  vc<int> I = longest_increasing_subsequence(A);
  print(len(I));
  print(I);
}

signed main() {
  solve();

  return 0;
}
