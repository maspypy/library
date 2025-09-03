#define PROBLEM "https://yukicoder.me/problems/no/1857"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution_all.hpp"

using mint = modint998;

void solve() {
  LL(N, S);
  mint s = mint(S).inverse();
  vc<mint> polys(N);
  FOR(i, N) {
    INT(p);
    mint x = mint(p) * s;
    polys[i] = -x;
  }
  auto f = convolution_all_1(polys);

  mint ANS = 0;
  FOR(i, N + 1) { ANS += f[i] * fact<mint>(i); }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
