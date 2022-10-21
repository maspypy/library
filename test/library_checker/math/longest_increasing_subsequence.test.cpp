#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/longest_increasing_subsequence.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  auto dp = longest_increasing_subsequence(A);
  ll n = MAX(dp);
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
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
