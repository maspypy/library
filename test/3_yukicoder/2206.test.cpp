#define PROBLEM "https://yukicoder.me/problems/no/2206"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "mod/powertable.hpp"
#include "mod/prefix_sum_of_binom.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  const int LIM = 200'000;
  vc<mint> POW = powertable_1<mint>(2, LIM + 10);
  Prefix_Sum_Of_Binom<mint> X(LIM);

  FOR(Q) {
    INT(n, m);
    mint cf = POW[n] - mint(1);
    mint x = X.query(n - 1, m);
    print(cf * x);
  }
}

signed main() {
  solve();
  return 0;
}
