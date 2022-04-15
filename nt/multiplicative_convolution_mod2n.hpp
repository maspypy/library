#include "poly/convolution.hpp"

template <typename mint>
vc<mint> multiplicative_convolution_mod2n(vc<mint>& A, vc<mint>& B){
  int N = 0;
  while((1<<N) < len(A)) ++N;
  assert((1<<N) == len(A) && (1<<N) == len(B));
  
  int mask = (1 << N) - 1;

  vc<vc<vc<mint>>> AA(N + 1);
  vc<vc<vc<mint>>> BB(N + 1);
  vc<vc<vc<mint>>> CC(N + 1);

  auto shape = [&](int n) -> pair<int, int> {
    int H = (N - n >= 2 ? 2 : 1);
    int W = 1 << max(N - n - 2, 0);
    return {H, W};
  };

  FOR(n, N + 1) {
    // 2 で n 回割れるところ
    auto [H, W] = shape(n);
    AA[n].assign(H, vc<mint>(W));
    BB[n].assign(H, vc<mint>(W));
    CC[n].assign(H, vc<mint>(W));
    int x = (1 << n) & mask;
    auto &a = AA[n], &b = BB[n];
    FOR(j, W) {
      a[0][j] = A[x];
      b[0][j] = B[x];
      if (H == 2) {
        a[1][j] = A[(1 << N) - x];
        b[1][j] = B[(1 << N) - x];
      }
      x = (5 * x) & mask;
    }
  }
  // n を固定して各軸方向に fft。合計 O(N2^N)
  FOR(n, N + 1) {
    auto &a = AA[n], &b = BB[n];
    auto [H, W] = shape(n);
    FOR(i, H) {
      ntt(a[i], false);
      ntt(b[i], false);
    }
    if (H == 2) {
      FOR(j, W) {
        tie(a[0][j], a[1][j]) = mp(a[0][j] + a[1][j], a[0][j] - a[1][j]);
        tie(b[0][j], b[1][j]) = mp(b[0][j] + b[1][j], b[0][j] - b[1][j]);
      }
    }
  }
  FOR(n1, N + 1) FOR(n2, N + 1) {
    // 必要な長さの fft 各点積を必要な場所に足しこむ。合計 O(2^N)
    int n3 = min(N, int(n1 + n2));
    auto [H, W] = shape(n3);
    FOR(i, H) FOR(j, W) CC[n3][i][j] += AA[n1][i][j] * BB[n2][i][j];
  }

  FOR(n, N + 1) {
    // inverse fft
    auto &c = CC[n];
    auto [H, W] = shape(n);
    FOR(i, H) ntt(c[i], true);
    if (H == 2) {
      FOR(j, W) {
        tie(c[0][j], c[1][j]) = mp(c[0][j] + c[1][j], c[0][j] - c[1][j]);
      }
    }
    mint coef = mint(1) / mint(H);
    FOR(i, H) FOR(j, W) c[i][j] *= coef;  
  }

  vc<mint> C(1 << N);
  FOR(n, N + 1) {
    auto [H, W] = shape(n);
    int x = (1 << n) & mask;
    auto &c = CC[n];
    FOR(j, W) {
      C[x] = c[0][j];
      if (H == 2) { C[(1 << N) - x] = c[1][j]; }
      x = (5 * x) & mask;
    }
  }
  return C;
}