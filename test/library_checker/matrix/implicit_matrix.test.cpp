#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/implicit_matrix/det.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  using T = tuple<int, int, mint>;
  VEC(T, dat, K);
  auto f = [&](vc<mint> v) -> vc<mint> {
    vc<mint> w(N);
    for (auto&& [a, b, c]: dat) { w[b] += v[a] * c; }
    return w;
  };
  mint det = implicit_matrix_det<mint>(N, f);
  print(det);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}