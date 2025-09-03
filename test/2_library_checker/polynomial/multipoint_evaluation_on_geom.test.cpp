#define PROBLEM \
  "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, a, r);
  VEC(mint, f, N);

  auto Y = multipoint_eval_on_geom_seq<mint>(f, a, r, M);
  print(Y);
}

signed main() {
  solve();
  return 0;
}