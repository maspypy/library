#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  A = cumsum(A);
  FOR(_, Q) {
    LL(L, R);
    print(A[R] - A[L]);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
