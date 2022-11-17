#include "poly/online_convolution.hpp"

// https://oeis.org/A059372 sum_{n>0} n!x^n の逆関数
vc<mint> revert_transform_of_factorials(const int N) {
  // xQ' = Q^2 + (1+x)Q'Q
  // R = Q^2 として、xQ' = R + 1/2 (1+x)R'
  // [x^n] を見ると、nQn = Rn + 1/2(n+1)R_{n+1} + 1/2 nR_n の形
  //
  // Q = x + x^2F とすれば F_{n-3} まで分かった時点で
  // Q_{n-1}, R_n まで確定。R = x^2+x^4F^2+2x^3F として、
  // Q_n = F_{n-2}, R_{n+1} = (確定) + 2F_{n-2} の形
  vc<mint> Q(N + 1), R(N + 2);
  Q[1] = 1, R[2] = 1;
  vc<mint> F(N - 1), FF(N - 1);
  Online_Convolution<mint> X;
  FOR(n, 2, N + 1) {
    mint x = R[n] + mint(n) * inv<mint>(2) * R[n];
    if (n >= 3) x += mint(n + 1) * FF[n - 3] * inv<mint>(2);
    Q[n] = F[n - 2] = -x;
    FF[n - 2] = X.query(n - 2, x, x);
    if (n + 1 >= 4) R[n + 1] += FF[n + 1 - 4];
    R[n + 1] += mint(2) * F[n - 2];
  }
  return Q;
}

// https://oeis.org/A111111
// ただし、n=1, 2 に対しては 0 を返すようにしている
template <typename mint>
vc<mint> simple_permutations(const int N) {
  vc<mint> S = revert_transform_of_factorials(N);
  for (auto&& x: S) x = -x;
  S[1] += mint(1);
  FOR(i, 2, N + 1) {
    if (i % 2 == 0) S[i] -= 2;
    if (i % 2 == 1) S[i] += 2;
  }
  return S;
}
