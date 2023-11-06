#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  auto Ac = cumsum<ll>(A);
  FOR(Q) {
    INT(L, R);
    print(Ac[R] - Ac[L]);
  }
}

signed main() {
  solve();
  return 0;
}
