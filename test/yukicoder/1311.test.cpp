#define PROBLEM "https://yukicoder.me/problems/no/1311"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/kth_next_permutation.hpp"
#include "ds/fenwick/fenwick.hpp"

void solve() {
  LL(i, N);
  vc<int> A(N);
  iota(all(A), 0);
  kth_next_permutation(A, i);
  vc<int> B(N);
  FOR(i, N) B[A[i]] = i;
  FenwickTree<Monoid_Add<int>> X(vc<int>(N, 1));
  vc<int> rk(N);
  FOR(i, N) {
    rk[i] = X.sum(B[i]);
    X.add(B[i], -1);
  }
  ll ANS = 0;
  FOR(i, N) { ANS = ANS * (N - i) + rk[i]; }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
