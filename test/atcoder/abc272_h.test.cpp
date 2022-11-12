#define PROBLEM "https://atcoder.jp/contests/abc272/tasks/abc272_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution.hpp"
#include "poly/convolution_all.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(int, A, N);
  sort(all(A));
  vc<mint> f(N + 1);
  FOR(i, N + 1) f[i] = fact_inv<mint>(i);
  vvc<mint> polys;
  FOR(k, N) {
    vc<mint> p = {mint(A[k] - k), mint(1)};
    polys.eb(p);
  }
  auto p = convolution_all(polys);
  vc<mint> X(N + 1);
  FOR(i, N + 1) X[i] = mint(i);
  auto Y = multipoint_eval(p, X);
  FOR(i, N + 1) f[i] *= Y[i];
  {
    vc<mint> g(N + 1);
    FOR(i, N + 1) g[i] = fact_inv<mint>(i) * (i % 2 == 1 ? mint(-1) : mint(1));
    f = convolution(f, g);
    f.resize(N + 1);
  }
  reverse(all(f));

  FOR(k, N + 1) f[k] *= fact<mint>(N - k);
  FOR(k, N + 1) f[k] *= fact<mint>(k);
  reverse(all(f));
  vc<mint> g(N + 1);
  FOR(i, N + 1) g[i] = fact_inv<mint>(i) * (i % 2 == 1 ? mint(-1) : mint(1));
  f = convolution(f, g);
  f.resize(N + 1);
  reverse(all(f));
  FOR(k, N + 1) f[k] *= fact_inv<mint>(k);

  mint ANS = 0;
  FOR(k, N + 1) if (k % 2 == 1) ANS += f[k];
  ANS *= fact_inv<mint>(N) * mint(N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
