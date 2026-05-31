#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/random_monge.hpp"
#include "convex/smawk.hpp"

void test() {
  FOR(H, 0, 30) FOR(W, 1, 30) {
    FOR(1000) {
      auto A = random_monge_matrix(H, W);

      auto better = [&](int i, int j, int k) -> bool {
        return A[i][j] > A[i][k];
      };

      vc<int> got = smawk(H, W, better);

      vc<int> expected(H);
      FOR(i, H) {
        expected[i] = 0;
        FOR(j, 1, W) {
          if (A[i][expected[i]] > A[i][j]) expected[i] = j;
        }
      }

      assert(got == expected);
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
