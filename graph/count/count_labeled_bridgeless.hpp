#include "graph/count/count_labeled_connected.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/fps_exp.hpp"

// 橋のない連結グラフ
// https://oeis.org/A095983
// N=1: 1
template <typename mint>
vc<mint> count_labeled_bridgeless(int N) {
  vc<mint> C = count_labeled_connected<mint>(N);
  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);

  vc<mint> D(N + 1);
  FOR(i, N + 1) D[i] = mint(i) * C[i];

  vc<mint> E = fps_exp(D);
  E.insert(E.begin(), mint(0));
  E.pop_back();

  // D(x)=B(E(x))
  vc<mint> IE = compositional_inverse(E);
  vc<mint> B = composition(D, IE);

  vc<mint> A(N + 1);
  FOR(i, 1, N + 1) A[i] = B[i] * inv<mint>(i);

  FOR(i, 1, N + 1) A[i] *= fact<mint>(i);
  return A;
}