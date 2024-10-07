#include "poly/typical_divide_conquer.hpp"
#include "poly/convolution_all.hpp"
#include "poly/fps_div.hpp"

// F[0](point[i]) ... F[CNT[i]-1](point[i])
template <typename mint>
vc<mint> multipoint_evaluation_for_prefix_product(vvc<mint> F, vc<mint> point, vc<int> CNT) {
  int N = len(point);
  if (N == 0) return {};
  auto I = argsort(CNT);
  point = rearrange(point, I), CNT = rearrange(CNT, I);
  vvc<mint> G1, G2;
  vvvc<mint> L(N), R(N);
  FOR(i, N) {
    vc<mint> f{mint(1), -point[i]};
    L[i].eb(f), R[i].eb(f), G2.eb(f);
  }
  int K = 0;
  for (auto& f: F) reverse(all(f));
  FOR(i, CNT[0]) { G1.eb(F[i]), K += len(F[i]) - 1; }
  FOR(j, N - 1) {
    FOR(k, CNT[j], CNT[j + 1]) {
      vc<mint> g(len(F[k]));
      g.back() = 1;
      L[j].eb(F[k]), R[j + 1].eb(g), K += len(g) - 1;
    }
  }
  Typical_Divide_Conquer<mint> TDC(N);
  FOR(i, N - 1) TDC.set_L(i, convolution_all<mint>(L[i]));
  FOR(i, 1, N) TDC.set_R(i, convolution_all<mint>(R[i]));
  vc<mint> g1 = convolution_all<mint>(G1);
  vc<mint> g2 = convolution_all<mint>(G2);
  g1.resize(K + 1), g2.resize(K + 1);
  vc<mint> ANS = TDC.calc(K, fps_div<mint>(g1, g2));
  I = argsort(I);
  ANS = rearrange(ANS, I);
  return ANS;
}
