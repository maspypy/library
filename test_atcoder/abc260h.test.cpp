#define PROBLEM "https://atcoder.jp/contests/abc260/tasks/abc260_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution_all.hpp"
#include "linalg/implicit_matrix/pascal.hpp"
#include "linalg/implicit_matrix/vandermonde.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(int, A, N);
  vc<int> CNT(N);
  for (auto&& x: A) CNT[x - 1]++;
  // 包除ルールの個数 -> ルールの決め方
  vvc<mint> polys;
  FOR(x, N) {
    int n = CNT[x];
    if (n <= 1) continue;
    vc<mint> f(n);
    FOR(i, n) f[i] = C<mint>(n - 1, i) * fact_inv<mint>(n - i);
    polys.eb(f);
  }
  vc<mint> f = convolution_all(polys);

  FOR(i, len(f)) f[i] *= fact<mint>(N - i);
  f = pascal(f, true, true);

  {
    mint cf = 1;
    for (auto&& x: CNT) cf *= fact<mint>(x);
    for (auto&& x: f) x *= cf;
  }

  int L = max(N, M + 1);
  vc<mint> g(N);
  FOR(i, len(f)) g[N - 1 - i] = f[i];
  g.resize(L);

  vc<mint> x(L);
  FOR(i, L) x[i] = i;
  vc<mint> ANS = vandermonde(g, x, true, false);
  ANS.erase(ANS.begin());
  ANS.resize(M);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}