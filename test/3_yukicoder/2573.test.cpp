#define PROBLEM "https://yukicoder.me/problems/no/2573"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/hungarian.hpp"

void solve() {
  LL(H, W);
  vv(ll, mat, W, W);
  FOR(i, W) {
    LL(x, y);
    --x, --y;
    FOR(j, W) {
      ll cost = 0;
      if (j < y - x) { cost = x + y - x - j; }
      elif (y - x <= j && j < y) { cost = x; }
      elif (y <= j) { cost = x + j - y; }
      mat[i][j] = cost;
    }
  }
  // FOR(i, W) print(mat[i]);
  auto [ans, match, X, Y] = hungarian<ll, true>(mat);
  print(ans);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
