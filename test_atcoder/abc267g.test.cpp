#define PROBLEM "https://atcoder.jp/contests/abc267/tasks/abc267_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/implicit_matrix/pascal.hpp"
#include "poly/convolution_all.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vc<int> CNT(N);
  FOR(N) {
    INT(x);
    CNT[--x]++;
  }
  vvc<mint> polys;
  for (auto&& c: CNT) {
    FOR(i, c) {
      vc<mint> f = {-mint(i), mint(1)};
      polys.eb(f);
    }
  }
  auto P = convolution_all(polys);
  vc<mint> points(N + 1);
  FOR(i, N + 1) points[i] = mint(i);
  auto F = multipoint_eval(P, points);

  F = pascal<mint>(F, 0, 1);
  reverse(all(F));
  F = pascal<mint>(F, 1, 1);
  reverse(all(F));
  print(F[N - K]);
}

signed main() {
  solve();
  return 0;
}