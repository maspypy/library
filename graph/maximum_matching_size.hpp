#include "random/base.hpp"
#include "mod/modint61.hpp"
#include "linalg/matrix_rank.hpp"

template <typename GT>
int maximum_matching_size(GT& G) {
  static_assert(!GT::is_directed);
  using mint = modint61;
  int N = G.N;
  vv(mint, tutte, N, N);
  for (auto&& e: G.edges) {
    mint x = RNG(mint::get_mod());
    int i = e.frm, j = e.to;
    tutte[i][j] += x;
    tutte[j][i] -= x;
  }
  return matrix_rank(N, N, tutte) / 2;
}
