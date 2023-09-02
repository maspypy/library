#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/maximum_matching.hpp"
#include "graph/maximum_matching_size.hpp"
#include "random/base.hpp"

void test() {
  FOR(N, 0, 100) {
    FOR(M, 0, 100) {
      if (N == 0 && M > 0) break;
      Graph<int, 0> G(N);
      FOR(M) {
        int a = RNG(0, N);
        int b = RNG(0, N);
        G.add(a, b);
      }
      G.build();
      int x = maximum_matching(G).fi;
      int y = maximum_matching_size(G);
      assert(x == y);
    }
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