#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_multiset.hpp"

void solve() {
  LL(N, M, K);
  My_Multiset<int, ll> X;
  VEC(ll, A, N);
  FOR(i, M) X.insert(A[i]);
  vi ANS;
  FOR(i, M, N + 1) {
    ANS.eb(X.get_kth(K).se);
    if (i == N) break;
    X.insert(A[i]), X.erase(A[i - M]);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}