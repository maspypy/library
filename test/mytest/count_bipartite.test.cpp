#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_bipartite.hpp"

using mint = modint998;

void test() {
  vc<mint> A = count_bipartite<mint>(10, true);
  vc<mint> B
      = {0, 1, 1, 3, 19, 195, 3031, 67263, 2086099, 89224635, 5254054111};
  assert(A == B);
  A = count_bipartite<mint>(10, false);
  B = {1, 1, 2, 7, 41, 376, 5177, 103237, 2922446, 116011231, 6433447397};
  assert(A == B);
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
