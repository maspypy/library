#define PROBLEM "https://yukicoder.me/problems/no/2206"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "mod/power_table.hpp"
#include "mod/prefix_sum_of_binom.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  const int LIM = 200'000;
  vc<mint> POW = power_table_1<mint>(2, LIM + 10);
  Prefix_Sum_Of_Binom_Offline<mint> X;

  vc<mint> CF(Q);

  FOR(q, Q) {
    INT(n, m);
    mint cf = POW[n] - mint(1);
    CF[q] = cf;
    X.add(n - 1, m);
  }
  auto res = X.calc();
  FOR(q, Q) print(res[q] * CF[q]);
}

signed main() {
  solve();
  return 0;
}