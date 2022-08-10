#include "mod/all_inverse.hpp"

// \prod_{i=0}^M (1+q^ix) を [x^N] まで計算
// 0 <= i <= N に対して q^i-1 が 0 にならないことを仮定した実装
// O(N + log(mod)) 時間
template <typename mint>
vc<mint> q_binomial(int N, mint q, ll M) {
  vc<mint> f(N + 1);
  f[0] = mint(1);
  mint c = q.pow(M + 1);
  vc<mint> den(N + 1, 1);
  {
    mint a = mint(1);
    FOR(i, N) {
      f[i + 1] = f[i] * (c - a);
      a *= q;
      den[i + 1] = den[i] * (a - mint(1));
    }
  }
  den = all_inverse(den);
  FOR(i, N + 1) { f[i] *= den[i]; }
  return f;
}