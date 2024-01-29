#include "graph/count/count_labeled_connected.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/integrate.hpp"

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