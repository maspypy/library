#define PROBLEM "https://yukicoder.me/problems/no/1760"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/mobius_table.hpp"
#include "mod/powertable.hpp"
#include "nt/lcm_convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  auto mu = mobius_table<mint>(N);

  vc<mint> POW = powertable_1<mint>(2, N);

  mint ANS = 0;

  {
    mint x = 0;
    FOR(i, 1, N + 1) x += mint(mu[i]);
    ANS += x * x;
  }
  {
    mint x = 0, y = 0;
    FOR(i, 1, N + 1) x += mint(mu[i]);
    FOR(i, 1, N + 1) y += mint(mu[i]) * POW[N / i];
    ANS -= mint(2) * x * y;
    ANS += y * y;
  }

  vc<mint> f(N + 1);
  FOR(i, 1, N + 1) f[i] = mint(mu[i]) * POW[N / i];
  f = lcm_convolution<mint>(f, f);
  mint r = mint(3) * inv<mint>(4);
  auto Pr = powertable_1<mint>(r, N);
  FOR(i, 1, N + 1) {
    mint x = Pr[N / i] - mint(1);
    ANS += x * f[i];
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
