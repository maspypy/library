#define PROBLEM "https://yukicoder.me/problems/no/2626"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/my_bitset.hpp"
#include "string/zalgorithm.hpp"

using BS = My_Bitset;

void solve() {
  LL(N, M, K);
  STR(A, B);

  BS X(N), Y(M);
  FOR(i, N) X[i] = ('a' <= A[i] && A[i] <= 'z');
  FOR(i, M) Y[i] = ('a' <= B[i] && B[i] <= 'z');

  for (auto& x: A) {
    if ('a' <= x && x <= 'z') x ^= 32;
  }
  for (auto& x: B) {
    if ('a' <= x && x <= 'z') x ^= 32;
  }
  vc<int> Z = zalgorithm(B + "." + A);
  Z = {Z.end() - N, Z.end()};

  ll ANS = 0;
  FOR(i, len(X)) {
    if (Z[i] != M) continue;
    BS x = X.range(i, i + M);
    int cnt = (x ^ Y).count();
    ANS += (1 <= cnt && cnt <= K);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
