#define PROBLEM "https://yukicoder.me/problems/no/2613"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/binomial.hpp"
#include "mod/modint.hpp"
#include "mod/multiplicative_convolution_mod_p.hpp"

using mint = modint998;

void solve() {
  LL(N, P);
  Binomial B(P);

  vc<mint> F(P);
  F[1] = 1;
  vvc<mint> dat;
  while (N) {
    auto [a, b] = divmod(N, P);
    vc<mint> f(P);
    FOR(i, b + 1) {
      int r = B.C(b, i);
      f[r] += 1;
    }
    F = multiplicative_convolution_mod_p(P, F, f);
    N = a;
  }

  mint ANS = 0;
  FOR(i, P) ANS += mint(i) * F[i];
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
