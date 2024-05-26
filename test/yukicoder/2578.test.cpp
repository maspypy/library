#define PROBLEM "https://yukicoder.me/problems/no/2578"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/array_on_divisors.hpp"

using mint = modint998;

ll M;
Array_On_Divisors<mint> X;

void solve() {
  LL(N);
  mint B, C, D;
  read(B, C, D);
  mint W = B;

  fill(all(X.dat), mint(1));
  FOR(N) {
    LL(a);
    if (M % a == 0) { X[a] *= W + mint(1); }
    W = W * C + D;
  }

  X.divisor_zeta([&](mint a, mint b) -> mint { return a * b; });
  for (auto& x: X.dat) x -= mint(1);
  X.divisor_mobius();
  print(X[M]);
}

signed main() {
  LL(T);
  read(M);
  X.build(M);
  FOR(T) solve();
  return 0;
}
