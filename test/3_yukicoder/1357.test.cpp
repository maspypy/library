#define PROBLEM "https://yukicoder.me/problems/no/1357"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/famous/riemann_zeta_even.hpp"

using mint = modint998;

void solve() {
  INT(N);
  vc<mint> ANS = riemann_zeta_even<mint>(2 * N);
  FOR(a, 1, N + 1) ANS[2 * a] *= mint(a + a - 1);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
