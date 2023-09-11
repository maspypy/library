#define PROBLEM "https://atcoder.jp/contests/abc314/tasks/abc314_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/slide_split_sum.hpp"

void solve() {
  LL(N, M);
  LL(H);
  vi A(N), B(N);
  FOR(i, N) read(A[i], B[i]);
  for (auto&& x: B) --x;
  Slide_Split_Sum<ll> S;
  FOR(M) S.insert(0);
  vi F(M);
  vi ANS(M + 1);

  // くらっても大丈夫
  ll can = M;
  FOR(i, N) {
    ll b = B[i];
    S.erase(F[b]);
    F[b] += A[i];
    S.insert(F[b]);
    while (S.query(can).fi >= H) { --can; }
    ANS[can] = 1 + i;
  }
  reverse(all(ANS));
  FOR(i, M) chmax(ANS[i + 1], ANS[i]);

  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
