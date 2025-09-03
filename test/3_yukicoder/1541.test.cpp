#define PROBLEM "https://yukicoder.me/problems/no/1541"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/binary_optimization.hpp"

void solve() {
  LL(N, M);
  Binary_Optimization<ll, false> X(N);

  FOR(i, N) {
    LL(k, C);
    X.add_1(i, 0, M - C);
    VEC(ll, A, k);
    VEC(ll, B, k);
    for (auto&& x: A) --x;
    FOR(j, k) { X.add_2(i, A[j], 0, 0, 0, B[j]); }
  }
  auto [a, x] = X.calc();
  print(a);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
