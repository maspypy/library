#define PROBLEM "https://atcoder.jp/contests/arc107/tasks/arc107_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/k_ary_optimization.hpp"
#include "graph/base.hpp"

// -1, 削除, +1
void solve() {
  LL(N, M);
  K_ary_Optimization<ll, false> X(vc<int>(N, 3));
  FOR(i, N) {
    LL(a);
    vi cost = {0, -a, 0};
    X.add_1(i, cost);
  }
  FOR(i, N) {
    LL(b);
    vi cost = {-b, 0, b};
    X.add_1(i, cost);
  }

  FOR(M) {
    INT(a, b);
    --a, --b;
    vv(ll, cost, 3, 3);
    cost[0][2] = cost[2][0] = -infty<int>;
    X.add_2(a, b, cost);
  }

  auto [val, color] = X.calc();
  print(val);
  // print(color);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
