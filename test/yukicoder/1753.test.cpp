#define PROBLEM "https://yukicoder.me/problems/no/1753"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "setfunc/hadamard.hpp"

using mint = modint998;
// using mint = double;

void solve() {
  LL(N);
  vc<mint> P(N + 1);
  {
    VEC(ll, A, N + 1);
    mint den = mint(1) / mint(SUM<ll>(A));
    FOR(i, N + 1) P[i] = den * mint(A[i]);
  }

  const int K = 10;
  auto calc = [&](int ng) -> vc<mint> {
    vc<mint> X(1 << K);
    FOR(i, 1, N + 1) {
      if (i == ng) continue;
      X[i] += P[i];
    }
    hadamard<mint>(X);
    // print(X);
    for (auto&& x: X) { x = mint(1) / (mint(1) - x); }
    hadamard<mint>(X);
    return X;
  };

  mint ANS = 0;
  auto A = calc(-1);
  ANS += A[0];
  FOR(i, 1, N + 1) {
    auto B = calc(i);
    ANS += A[i] - B[i];
  }
  ANS *= P[0] / mint(1 << K);
  ANS = mint(1) - ANS;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
