#define PROBLEM "https://yukicoder.me/problems/no/1838"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/inversion.hpp"

void solve() {
  LL(M, K);
  ll N = M * K;
  VEC(ll, A, N);
  vvc<int> pos(M);
  FOR(i, N) pos[A[i]].eb(i);
  ll base = 0;
  FenwickTree<Monoid_Add<int>> bit(N);
  FOR(j, K) {
    FOR(i, M) {
      int x = pos[i][j];
      base += bit.sum(x, N);
    }
    FOR(i, M) {
      int x = pos[i][j];
      bit.add(x, 1);
    }
  }
  vi ANS(M, base);
  FOR(j, K) {
    vc<int> P(M);
    FOR(i, M) P[i] = pos[i][j];
    auto tmp = inversion_rotate(P, false);
    FOR(i, M) ANS[i] += tmp[i];
  }
  print(MIN(ANS));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
