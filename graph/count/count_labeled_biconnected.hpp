#include "graph/count/count_labeled_connected.hpp"
#include "graph/count/count_labeled_tree.hpp"
#include "poly/compositional_inverse.hpp"
#include "poly/differentiate.hpp"
#include "poly/integrate.hpp"

template <typename mint>
vc<mint> count_labeled_biconnected(int N) {
  // すべて指数型
  // F1(x): labeled connected
  vc<mint> F1 = count_labeled_connected<mint>(N);
  FOR(i, N + 1) F1[i] *= fact_inv<mint>(i);

  // labeled connected から頂点 0 を削除したときの連結成分を考える
  // F1'(x) = exp(F2'(x)) の形の式が出てくる
  // F2 は 2 頂点以上 labeled connected で頂点 0 が関節点ではないもの
  vc<mint> DF2 = fps_log(differentiate(F1));

  // F3 は rooted labeled connected
  vc<mint> F3(N + 1);
  FOR(i, N + 1) F3[i] = F1[i] * mint(i);
  POP(F3);

  // F(x): labeled biconnected.
  // F2'(x) を頂点 0 の component によって数える
  // F2'：rooted connected たちの root 同士を biconnected になるようにつなぐ
  // F3(x)^n/n! から、F2'(x) のうち頂点 0 の成分の大きさが n のものが出てくる
  // 結局 F'(F3(x))=F2'(x) が分かり, F'(x)=F2'(IF3(x)) により F が求まる
  vc<mint> IF3 = compositional_inverse(F3);
  vc<mint> DF = composition(DF2, IF3);
  vc<mint> F = integrate(DF);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  return F;
}