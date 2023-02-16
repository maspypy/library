#define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/from_log_differentiation.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N);
  poly f = {6 * N, 4 * N};
  poly g = {1, 3, 1};
  mint x = from_log_differentiation_kth(N - 1, f, g) / mint(N);
  print(x);
}

signed main() {
  solve();
  return 0;
}
