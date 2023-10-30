#define PROBLEM "https://yukicoder.me/problems/no/1755"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/find_linear_rec.hpp"
#include "poly/fps_inv.hpp"

using mint = modint998;

void solve() {
  mint K = 26;

  auto f = [&](int N) -> mint {
    mint ANS = 0;
    FOR(a, N + 1) {
      ll n = N - 2 * a;
      if (n <= 1) break;
      mint x = K.pow(ceil<ll>(n - 1, 2)) * (K - 1);
      mint y = (n % 2 == 0 ? K * (K - mint(1)) : 0);
      x = x + x - y;
      x *= K.pow(a);
      ANS += x;
    }
    return ANS;
  };

  ll LIM = 20;
  vc<mint> A(LIM);
  FOR(n, LIM) A[n] = f(n);
  auto G = find_linear_rec<mint>(A);
  auto F = convolution(A, G);
  F.resize(6);

  LIM = 1000000;
  G.resize(LIM + 1);
  G = fps_inv(G);
  F = convolution(F, G);

  LL(T);
  FOR(T) {
    LL(N);
    print(F[N]);
  }
}

signed main() {
  solve();
  return 0;
}
