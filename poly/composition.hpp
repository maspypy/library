#include "poly/convolution.hpp"

// https://noshi91.hatenablog.com/entry/2024/03/16/224034
// O(Nlog^2N), N=100000 1.5sec
template <typename mint>
vc<mint> composition(vc<mint> f, vc<mint> g) {
  const int N = len(f) - 1;
  if (N == -1) return {};
  assert(len(f) == N + 1 && len(g) == N + 1);

  // ひとまずいまの実装だと 256 くらいまでは旧実装の方が高速
  if (N < 256) return composition_old<mint>(f, g);

  mint c = g[0];
  g[0] = 0;
  f = poly_taylor_shift<mint>(f, c);

  // [y^0]f(y^{-1})/1-g(x)y
  using poly = vvc<mint>;
  vc<poly> Gs;
  // 1-g(x)y = G0(x,y)G1(x^2,y)G2(x^4,y)...
  vv(mint, A, N + 1, 2);
  A[0][0] = 1;
  FOR(i, N + 1) A[i][1] = -g[i];
  while (1) {
    int H = len(A), W = len(A[0]);
    if (H == 1) { break; }
    vvc<mint> B = A;
    FOR(i, H) {
      if (i % 2 == 0) continue;
      FOR(j, W) B[i][j] = -B[i][j];
    }
    Gs.eb(B);
    A = convolution2d(A, B);
    FOR(i, (H + 1) / 2) A[i] = A[2 * i];
    A.resize((H + 1) / 2);
  }
  int sm_deg = 0;
  for (auto& G: Gs) sm_deg += len(G[0]) - 1;

  // middle product が使えるはずだがとりあえず
  reverse(all(f));
  vv(mint, F, 1, N + 1);
  F[0] = f;
  FOR_R(k, len(Gs)) {
    int d = len(F[0]) - 1;
    auto& G = Gs[k];
    F.resize(len(F) * 2);
    POP(F);
    FOR(i, len(F)) F[i].resize(d + 1);
    FOR_R(i, len(F)) {
      if (i % 2 == 0) F[i] = F[i / 2];
      if (i % 2 != 0) fill(all(F[i]), mint(0));
    }
    F = convolution2d(F, Gs[k]);
    if (len(F) - 1 > (N >> k)) F.resize((N >> k) + 1);
    FOR(i, len(F)) F[i].resize(d + 1);

    sm_deg -= len(G[0]) - 1;
    int s = d - sm_deg;
    FOR(i, len(F)) {
      if (s > 0) F[i] = {F[i].begin() + s, F[i].end()};
    }
  }

  vc<mint> ANS(N + 1);
  FOR(i, N + 1) ANS[i] = F[i][0];
  return ANS;
}

template <typename mint>
vc<mint> composition_old(vc<mint>& Q, vc<mint>& P) {
  int n = len(P);
  assert(len(P) == len(Q));
  int k = 1;
  while (k * k < n) ++k;
  // compute powers of P
  vv(mint, pow1, k + 1);
  pow1[0] = {1};
  pow1[1] = P;
  FOR3(i, 2, k + 1) {
    pow1[i] = convolution(pow1[i - 1], pow1[1]);
    pow1[i].resize(n);
  }
  vv(mint, pow2, k + 1);
  pow2[0] = {1};
  pow2[1] = pow1[k];
  FOR3(i, 2, k + 1) {
    pow2[i] = convolution(pow2[i - 1], pow2[1]);
    pow2[i].resize(n);
  }
  vc<mint> ANS(n);
  FOR(i, k + 1) {
    vc<mint> f(n);
    FOR(j, k) {
      if (k * i + j < len(Q)) {
        mint coef = Q[k * i + j];
        FOR(d, len(pow1[j])) f[d] += pow1[j][d] * coef;
      }
    }
    f = convolution(f, pow2[i]);
    f.resize(n);
    FOR(d, n) ANS[d] += f[d];
  }
  return ANS;
}
