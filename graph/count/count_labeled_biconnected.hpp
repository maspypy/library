#include "graph/count/count_labeled_connected.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/integrate.hpp"
#include "poly/fps_pow.hpp"

// https://oeis.org/A013922
template <typename mint>
vc<mint> count_labeled_biconnected(int N) {
  vc<mint> C = count_labeled_connected<mint>(N);
  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);

  vc<mint> D(N);
  FOR(i, N) D[i] = C[i + 1] * mint(i + 1);

  vc<mint> E(N);
  FOR(i, N) E[i] = C[i] * mint(i);

  vc<mint> G = fps_log(D);

  vc<mint> IE = compositional_inverse(E);
  vc<mint> B = composition(G, IE);
  vc<mint> A = integrate(B);

  FOR(i, N + 1) A[i] *= fact<mint>(i);
  return A;
}

// https://oeis.org/A013922
template <typename mint>
mint count_labeled_biconnected_single(int N) {
  if (N < 2) return 0;
  vc<mint> C = count_labeled_connected<mint>(N);
  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);

  vc<mint> D(N);
  FOR(i, N) D[i] = C[i + 1] * mint(i + 1);

  vc<mint> E(N);
  FOR(i, N) E[i] = C[i] * mint(i);

  vc<mint> G = fps_log(D);

  // (N-1)[x^{N-1}]G(IE(x))=[x^{-1}]G'(x)E(x)^{-(N-1)}
  // =[x^{N-2}]G'(x)(E(x)/x)^{-(N-1)}
  G = differentiate(G);
  E.erase(E.begin());
  E = fps_pow_1<mint>(E, -(N - 1));
  mint ANS = 0;
  FOR(i, N - 1) ANS += G[i] * E[N - 2 - i];

  ANS *= inv<mint>(N - 1);
  ANS *= inv<mint>(N);
  ANS *= fact<mint>(N);
  return ANS;
}