#define PROBLEM "https://yukicoder.me/problems/no/1821"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/famous/eulerian_number.hpp"

using mint = modint998;

void solve() {
  LL(N);
  STR(S);
  int a = count(all(S), '0');
  int b = count(all(S), '1');
  if (a == 0 || b == 0) return print(fact<mint>(N));
  if (a < b) swap(a, b);

  auto dp = eulerian_number_2d<mint>(N, b);

  mint ANS = 0;
  // a のうちで、等号でとるものの個数を固定
  FOR(i, a + 1) { ANS += C<mint>(N, i) * dp[a - i + b][b]; }
  ANS *= fact<mint>(b) * fact<mint>(a);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
