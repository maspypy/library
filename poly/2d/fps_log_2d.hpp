#include "poly/2d/convolution2d.hpp"
#include "poly/2d/fps_inv_2d.hpp"

template <typename T>
vvc<T> fps_log_2d(vvc<T> F) {
  assert(F[0][0] == 1);
  // G = log F, G'=F'/F.
  int N = len(F), M = len(F[0]);
  vvc<T> DF(N, vc<T>(M));
  FOR(i, N - 1) FOR(j, M) DF[i][j] = F[i + 1][j] * (i + 1);
  auto IF = fps_inv_2d(F);
  vvc<T> DG = convolution2d(DF, IF, true);
  vv(T, G, N, M);
  FOR(i, 1, N) FOR(j, M) G[i][j] = DG[i - 1][j] / i;
  G[0] = fps_log<T>(F[0]);
  return G;
}
