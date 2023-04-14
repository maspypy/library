#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/doubling.hpp"

void solve() {
  LL(N, K);
  Doubling<Monoid_Add<ll>, 40> X(N);
  VEC(int, A, N);
  FOR(i, N) {
    int j = (i + A[i]) % N;
    X.add(i, j, A[i]);
  }
  X.build();
  auto [to, sm] = X.calc(0, K);
  print(sm);
}

signed main() {
  solve();
  return 0;
}