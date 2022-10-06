#define PROBLEM "https://yukicoder.me/problems/no/1857"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution_all.hpp"

using mint = modint998;

void solve() {
  LL(N, S);
  mint s = mint(S).inverse();
  vvc<mint> polys(N);
  FOR(i, N) {
    INT(p);
    mint x = mint(p) * s;
    polys[i] = {1, x};
  }
  auto f = convolution_all(polys);

  mint ANS = 0;
  FOR(i, N + 1) { ANS += f[i] * fact<mint>(i); }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
