#define PROBLEM "https://yukicoder.me/problems/no/1145"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/sum_of_powers.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, N);
  auto f = sum_of_powers(A, M);
  f.erase(f.begin());
  print(f);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
