#define PROBLEM "https://yukicoder.me/problems/no/2580"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"
#include "mod/modint.hpp"
#include "poly/prefix_sum_of_polynomial.hpp"
#include "poly/composition_f_a_plus_bx.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(ll, A, N - 1);
  BigInteger M;
  read(M);

  // 累積和の多項式
  vc<mint> F = {1};

  FOR(i, N - 1) {
    ll a = A[i];
    auto [q, r] = M.divmod(a);
    M = q;
    F = composition_f_a_plus_bx<mint>(F, mint(r), mint(a));
    F = prefix_sum_of_polynomial(F, true);
  }
  mint x = M.divmod(998244353).se;
  mint fx = 0;
  mint pow = 1;
  FOR(i, len(F)) fx += F[i] * pow, pow *= x;
  print(fx);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
