#define PROBLEM "https://atcoder.jp/contests/abc333/tasks/abc333_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/typical_divide_conquer.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N);
  poly g(N);
  FOR(i, N) g[i] = inv<mint>(2) * (mint(1) - inv<mint>(2).pow(i + 1)).inverse();
  reverse(all(g));

  Typical_Divide_Conquer<mint> X(N);
  FOR(i, N) {
    if (i != N - 1) X.set_L(i, poly{mint(1), -inv<mint>(2)});
    if (i != 0) X.set_R(i, poly{mint(1), -inv<mint>(1)});
  }

  auto ANS = X.calc(N - 1, g);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
