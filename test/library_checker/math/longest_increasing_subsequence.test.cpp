#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/longest_increasing_subsequence.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  auto [n, dp] = longest_increasing_subsequence(A);
  ll x = MAX(A) + 1;
  vc<int> I;
  FOR_R(i, N) {
    if (dp[i] == n && A[i] < x) {
      I.eb(i);
      --n;
      x = A[i];
    }
  }
  reverse(all(I));
  print(len(I));
  print(I);
}

signed main() {
  solve();

  return 0;
}
