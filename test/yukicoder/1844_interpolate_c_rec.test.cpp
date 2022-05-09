#define PROBLEM "https://yukicoder.me/problems/no/1844"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint107;

void solve() {
  LL(N);
  mint ANS = 1;
  FOR_(N) {
    LL(p, e);
    vc<mint> A(10);
    FOR(i, 10) A[i] = mint(p).pow(i);
    A = cumsum(A, 0);
    A = cumsum(A, 0);
    mint x = interpolate_linear_rec<mint>(A, e);
    ANS *= x;
  }
  print(ANS);
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
