#define PROBLEM "https://yukicoder.me/problems/no/2587"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/base.hpp"

#include "poly/poly_taylor_shift.hpp"
#include "poly/coef_of_rational_fps.hpp"
#include "graph/tree_walk_generating_function.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N, M, S, T);
  --S, --T;
  Graph<int, 0> G(N);
  G.read_tree();

  auto [g, f] = tree_walk_generating_function<true, mint>(
      G, S, T, [&](int i, int j) -> mint { return 1; });

  mint ANS = coef_of_rational_fps<mint>(g, f, M);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
