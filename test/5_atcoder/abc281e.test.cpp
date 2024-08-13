#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/slide_split_sum.hpp"

void solve() {
  LL(N, M, K);
  Slide_Split_Sum<ll> S;
  VEC(ll, A, N);
  vi ANS;
  FOR(i, N) {
    S.insert(A[i]);
    if (len(S) > M) S.erase(A[i - M]);
    if (len(S) == M) ANS.eb(S.query_l(K));
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}