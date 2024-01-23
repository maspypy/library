#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/blackbox/det.hpp"

#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  LL(N, K);
  using T = tuple<int, int, mint>;
  VEC(T, dat, K);
  auto A = [&](vc<mint> X) -> vc<mint> {
    vc<mint> Y(N);
    for (auto& [a, b, c]: dat) Y[b] += X[a] * c;
    return Y;
  };
  mint d = blackbox_det<mint>(N, A);
  print(d);
}

signed main() {
  solve();
  return 0;
}
