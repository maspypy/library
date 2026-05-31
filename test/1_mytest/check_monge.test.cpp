#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/random_monge.hpp"
#include "convex/monge/check_monge.hpp"

void test() {
  FOR(N, 1, 10) {
    FOR(1000) {
      auto A = random_monge_matrix(N + 1, N + 1);
      assert(check_monge<ll>(N, [&](int i, int j) -> ll { return A[i][j]; }));
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
