#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/famous/eulerian_number.hpp"

using mint = modint998;

void test() {
  const int LIM = 100;
  auto dp = eulerian_number_2d<mint>(LIM, LIM);

  FOR(N, LIM + 1) {
    auto f = eulerian_number_n<mint>(N);
    assert(len(f) == N + 1);
    FOR(i, N + 1) assert(f[i] == dp[N][i]);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}