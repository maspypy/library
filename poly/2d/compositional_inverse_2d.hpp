#include "poly/compositional_inverse.hpp"

// 注意 (H+W)^2log(H+W) 時間になっているので正方形じゃないとダメなさぼり実装
// 仮定：F(x,y) = sum F_k(y)x^k, F_1=1, deg F_k<=k
// y の多項式を係数とする 1変数 fps に関する合成を考えている
template <typename mint>
vvc<mint> compositional_inverse_2d(vvc<mint> F) {
  int N = len(F) - 1, M = len(F[0]) - 1;
  assert(N == M);
  FOR(i, N) FOR(j, i + 1, M) assert(F[i][j] == 0);
  assert(F[0][0] == 0);

  int L = 1;
  while (L <= N) L *= 2;
  FOR(i, N + 1) {
    F[i].resize(L);
    ntt(F[i], false);
  }
  FOR(j, L) {
    vc<mint> f(N + 1);
    FOR(i, N + 1) f[i] = F[i][j];
    f = compositional_inverse<mint>(f);
    FOR(i, N + 1) F[i][j] = f[i];
  }
  FOR(i, N + 1) {
    F[i].resize(L);
    ntt(F[i], true);
    F[i].resize(N + 1);
  }
  return F;
}
