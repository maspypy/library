
// 注意 (H+W)^2log(H+W) 時間になっているので正方形じゃないとダメなさぼり実装
template <typename mint>
vvc<mint> fps_pow_2d(vvc<mint> F, ll K) {
  int N = len(F) - 1, M = len(F[0]) - 1;
  int L = 1;
  while (L < N + M + 1) L *= 2;

  vv(mint, F1, L, N + M + 1);
  FOR(i, N + 1) FOR(j, M + 1) F1[i][i + j] = F[i][j];

  FOR(j, N + M + 1) {
    vc<mint> f(L);
    FOR(i, L) f[i] = F1[i][j];
    ntt(f, false);
    FOR(i, L) F1[i][j] = f[i];
  }
  FOR(i, L) F1[i] = fps_pow<mint>(F1[i], K);
  FOR(j, N + M + 1) {
    vc<mint> f(L);
    FOR(i, L) f[i] = F1[i][j];
    ntt(f, true);
    FOR(i, L) F1[i][j] = f[i];
  }
  FOR(i, N + 1) FOR(j, M + 1) F[i][j] = F1[i][i + j];
  return F;
}
