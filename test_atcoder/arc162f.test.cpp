#define PROBLEM "https://atcoder.jp/contests/arc162/tasks/arc162_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/fps_inv_2d.hpp"

using mint = modint998;

void solve() {
  LL(H, W);
  vv(mint, f, H + 1, W + 1);
  f[0][0] = mint(1);

  auto path = [&](int x, int y) -> mint {
    if (min(x, y) < 0) return 0;
    return C<mint, 0, 1>(x + y, y);
  };

  FOR(x, 1, H + 1) FOR(y, 1, W + 1) {
    mint a = path(x - 1, y - 1);
    mint b = path(x - 2, y);
    mint c = path(x, y - 2);
    mint d = a;
    f[x][y] = -(a * d - b * c);
  }

  vvc<mint> F = fps_inv_2d(f);

  mint ANS = 0;
  FOR(n, H + 1) {
    FOR(m, W + 1) {
      mint x = C<mint>(H, n) * C<mint>(W, m);
      x *= F[n][m]; // F(n, m);
      ANS += x;
      // print(n, m, ",", x);
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}