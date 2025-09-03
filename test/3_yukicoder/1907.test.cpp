#define PROBLEM "https://yukicoder.me/problems/no/1907"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/det_A_plus_xB.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VV(mint, A, N, N);
  VV(mint, B, N, N);
  auto f = det_A_plus_xB(A, B);
  for (auto&& x: f) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
