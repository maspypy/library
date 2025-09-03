#define PROBLEM "https://yukicoder.me/problems/no/1774"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "linalg/matrix_lowrank_update.hpp"

using mint = modint107;

void solve() {
  INT(N, M);
  Matrix_Rank_Lowrank_Update<mint> X(N);

  FOR(i, M) {
    INT(a, b, c);
    --a, --b, --c;
    mint wt = RNG(0, mint::get_mod());
    vc<mint> x(N), y(N);
    x[a] += 1, x[b] -= 1;
    y[a] += 1, y[c] -= 1;
    X.rank_one_update(wt, x, y);
    X.rank_one_update(-wt, y, x);
    assert(X.rank() % 2 == 0);
    print(X.rank() / 2);
  }
}

signed main() {
  solve();
  return 0;
}
