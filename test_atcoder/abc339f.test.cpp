#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"
#include "random/hash_vector.hpp"
#include "ds/hashmap.hpp"

using B = BigInteger;

void solve() {
  LL(N);
  vc<B> A(N);
  FOR(i, N) {
    STR(S);
    A[i] = B(S);
  }

  HashMap<int> MP(N);
  FOR(i, N) {
    auto x = hash_vector(A[i].dat);
    MP[x]++;
  }

  ll ANS = 0;
  FOR(i, N) FOR(j, i + 1) {
    if (A[i].log10() + A[j].log10() > 1010) continue;
    B p = A[i] * A[j];
    auto x = hash_vector(p.dat);
    int cnt = MP.get(x, 0);
    if (i != j) cnt *= 2;
    ANS += cnt;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
