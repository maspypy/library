#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "linalg/transpose.hpp"
#include "other/equal_4square_sum_grid.hpp"

void test() {
  FOR(H, 2, 20) {
    FOR(W, 2, 20) {
      if (H % 2 == 1 && W % 2 == 0) continue;
      int S0 = 2 * (H * W - 1);
      int L = S0, R = S0;
      if (H % 2 == 0 && W % 2 == 0) { L = S0, R = S0; }
      if (H % 4 == 2 && W % 2 == 1) { L = S0 - 1, R = S0 + 1; }
      if (H % 4 == 0 && W % 2 == 1) { L = S0 - 2, R = S0 + 2; }
      FOR(S, L, R + 1) {
        vvc<int> A = equal_4square_sum_grid(H, W, S);
        assert(len(A) == H && len(A[0]) == W);
        vc<int> used(H * W);
        FOR(x, H) FOR(y, W) used[A[x][y]]++;
        assert(MIN(used) == 1 && MAX(used) == 1);
        FOR(x, H - 1) FOR(y, W - 1) { assert(A[x][y] + A[x][y + 1] + A[x + 1][y] + A[x + 1][y + 1] == S); }
      }
    }
  }
}

void solve() {
  int x, y;
  cin >> x >> y;
  cout << x + y << "\n";
}

signed main() {
  test();
  solve();
}
