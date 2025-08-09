#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "nt/dirichlet.hpp"

using mint = modint998;

void test(ll n) {
  vi FLOOR;
  FOR(i, 1, n + 1) FLOOR.eb(n / i);
  UNIQUE(FLOOR);
  vc<mint> f(n + 1), g(n + 1), h(n + 1);
  FOR(i, 1, n + 1) f[i] = RNG(1, mint::get_mod());
  FOR(i, 1, n + 1) g[i] = RNG(1, mint::get_mod());

  FOR(a, 1, n + 1) FOR(b, 1, n / a + 1) h[a * b] += f[a] * g[b];
  vc<mint> F = cumsum<mint>(f, 0), G = cumsum<mint>(g, 0),
           H = cumsum<mint>(h, 0);
  vc<mint> A = {0}, B = {0}, C = {0};
  for (auto &v : FLOOR) A.eb(F[v]), B.eb(G[v]), C.eb(H[v]);

  Dirichlet DIR(n);
  vc<mint> D = DIR.convolution(A, B);
  assert(C == D);
  vc<mint> E = DIR.div(C, A);
  assert(B == E);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(N, 1, 10000) { test(N); }
  solve();
}