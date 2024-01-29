#include "poly/fps_log.hpp"
#include "graph/count/count_labeled_undirected.hpp"

// https://oeis.org/A033678
template <typename mint>
vc<mint> count_labeled_eulerian(int N) {
  if (N == 0) return vc<mint>({mint(1)});
  vc<mint> F = count_labeled_undirected<mint>(N - 1);
  F.insert(F.begin(), mint(1));
  FOR(n, N + 1) F[n] *= fact_inv<mint>(n);
  F = fps_log(F);
  FOR(n, N + 1) F[n] *= fact<mint>(n);
  return F;
}
