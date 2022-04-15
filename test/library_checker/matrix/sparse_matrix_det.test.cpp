#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/spmat_det.hpp"

#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  LL(N, K);
  using T = tuple<int, int, mint>;
  VEC(T, dat, K);
  print(spmat_det(N, dat));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
