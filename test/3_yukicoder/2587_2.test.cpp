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

  auto [g, f] = tree_walk_generating_function<false, mint>(
      G, S, T, [&](int i, int j) -> mint { return 1; });

  // W(x) = g(x)/f(x)
  // ANS = sum_m binom(M,m)[x^m]W(x)
  // EGF(W) = sum_m W_m 1/m! x^m
  // [x^M]e^x EGF(W)
  // 根が全部 -1 される
  // ANS も C-rec で、f(x-1)

  vc<mint> W = fps_div(g, f);
  FOR(m, N) W[m] *= fact_inv<mint>(m);
  vc<mint> tmp(N + 1);
  FOR(m, N + 1) tmp[m] = fact_inv<mint>(m);
  vc<mint> F = convolution(W, tmp);
  F.resize(N);
  FOR(i, N) F[i] *= fact<mint>(i);
  reverse(all(f));
  f = poly_taylor_shift<mint>(f, -1);
  reverse(all(f));
  g = convolution<mint>(F, f);
  g.resize(N);
  mint ANS = coef_of_rational_fps<mint>(g, f, M);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
