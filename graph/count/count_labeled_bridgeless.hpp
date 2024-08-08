#include "graph/count/count_labeled_connected.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/fps_exp.hpp"
#include "poly/fps_pow.hpp"

// 橋のない連結グラフ
// https://oeis.org/A095983
// N=1: 1
// O(Nlog^2N)
// https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_p
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

// https://oeis.org/A095983
// N での値のみ, O(NlogN)
template <typename mint>
mint count_labeled_bridgeless_single(int N) {
  if (N == 0) return 0;
  vc<mint> C = count_labeled_connected<mint>(N);
  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);

  vc<mint> D(N + 1);
  FOR(i, N + 1) D[i] = mint(i) * C[i];

  vc<mint> E = fps_exp(D);
  E.insert(E.begin(), mint(0));
  E.pop_back();

  // D(x)=B(E(x))
  // [x^N]B(x) を求めたい
  // Lagrange Inversion
  // N[x^N]D(IE(x))=[x^{-1}]D'(x)E(x)^{-N}
  // =[x^{N-1}]D'(x)(E(x)/x)^{-N}

  E.erase(E.begin());
  E = fps_pow_1<mint>(E, -N);
  D = differentiate(D);
  mint ANS = 0;
  FOR(i, N) ANS += D[i] * E[N - 1 - i];
  ANS *= inv<mint>(N);

  // [x^N]B(x) が出た
  ANS *= inv<mint>(N);
  ANS *= fact<mint>(N);
  return ANS;
}