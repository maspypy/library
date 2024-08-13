#define PROBLEM "https://yukicoder.me/problems/no/2459"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/sum_of_powers.hpp"

using mint = modint998;

void solve() {
  LL(H, W, N, K);

  auto get = [&](ll H) -> pi {
    // 1～n が 2 個と n+1 が H-2n 個という形で書ける
    ll n = 0;
    if (H < 2 * K) {
      n = H - K;
    } else {
      n = K - 1;
    }
    return {n, H - 2 * n};
  };

  auto [N1, M1] = get(H);
  auto [N2, M2] = get(W);

  mint ANS = 0;
  mint F = (H - K + 1) * (W - K + 1);

  mint c = mint(1) / F;

  ANS += mint(4) * mint(N1 * N2);

  {
    vc<mint> F = sum_of_powers_iota<mint>(1, N1 + 1, N);
    vc<mint> G = sum_of_powers_iota<mint>(1, N2 + 1, N);
    mint sm = 0;
    mint pow = 1;
    FOR(n, N + 1) {
      mint x = F[n] * G[n];
      x *= C<mint>(N, n);
      if (n % 2 == 1) x = -x;
      x *= pow;
      sm += x;
      pow *= c;
    }
    ANS -= mint(4) * sm;
  }

  auto calc = [&](mint c, ll K) -> mint {
    mint sm = K;
    vc<mint> F = sum_of_powers_iota<mint>(1, K + 1, N);
    mint pow = 1;
    FOR(n, N + 1) {
      mint x = F[n];
      x *= C<mint>(N, n);
      if (n % 2 == 1) x = -x;
      sm -= x * pow;
      pow *= c;
    }
    return sm;
  };

  ANS += calc(mint(N2 + 1) / F, N1) * mint(2) * mint(M2);
  ANS += calc(mint(N1 + 1) / F, N2) * mint(2) * mint(M1);

  {
    mint p = mint((N1 + 1) * (N2 + 1)) / F;
    mint x = mint(1) - (mint(1) - p).pow(N);
    ANS += mint(M1 * M2) * x;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
