#include "poly/composition.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/fps_div.hpp"

// 0=[x^0]F, a=[x^1]F
// [2,N) で a^i != a
// このとき G, H は互いに合成逆で
// G(F(x))=aG(x), F(H(x))=H(ax)
// https://yukicoder.me/problems/no/3621
template <typename mint>
struct Schroder {
  int N;
  vc<mint> F, G, H;
  mint a;
  vc<mint> pw;
  Schroder(vc<mint> &F) : F(F) {
    N = len(F);
    a = (N <= 1 ? 1 : F[1]);
    pw.resize(N + 1, 1);
    FOR(i, N) pw[i + 1] = pw[i] * a;
    H.resize(2);
    H[1] = 1;
    while (len(H) < N) {
      int m = len(H);
      int M = min<int>(2 * m - 1, N);
      H.resize(M);
      vc<mint> f(M);
      FOR(i, M) f[i] = F[i];
      vc<mint> E = composition(f, H);
      E = {E.begin() + m, E.begin() + M};
      vc<mint> den(M - m);
      FOR(i, M - m) den[i] = H[i + 1] * pw[i] * (i + 1);
      E = fps_div<mint>(E, den);
      FOR(i, M - m) E[i] /= pw[m + i] - a;
      vc<mint> DH(M - m);
      FOR(i, M - m) { DH[i] = H[i + 1] * (i + 1); }
      E = convolution<mint>(E, DH);
      E.resize(M - m);
      FOR(i, M - m) H[m + i] = E[i];
    }
    SHOW(H);
    H.resize(N);
    G = compositional_inverse(H);
  }

  // F の K 回合成
  vc<mint> iterated_composition(ll K) {
    mint c = a.pow(K);
    vc<mint> g(N);
    FOR(i, N) g[i] = G[i] * c;
    return composition(H, g);
  }
};