#define PROBLEM \
  "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/lagrange_interpolate_iota.hpp"
using mint = modint998;
void solve() {
  LL(N, M, c);
  VEC(mint, f, N);
  print(lagrange_interpolate_iota(f, mint(c), M));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
