#define PROBLEM \
  "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/multipoint.hpp"

#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  INT(N);
  mint a, r;
  read(a, r);
  VEC(mint, Y, N);

  auto f = multipoint_interpolate_on_geom_seq(Y, a, r);
  print(f);
}

signed main() {
  solve();
  return 0;
}