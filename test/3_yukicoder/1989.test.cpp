#define PROBLEM "https://yukicoder.me/problems/no/1989"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  mint avg = mint(M) * mint(N) / mint(N + N + 1);
  mint x = C_negative<mint, true>(N + N + 1, M);
  print(avg * x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
