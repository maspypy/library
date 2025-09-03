#define PROBLEM "https://yukicoder.me/problems/no/1575"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/sum_of_powers.hpp"
#include "poly/multipoint.hpp"
#include "nt/lpf_table.hpp"
#include "nt/divisors.hpp"

using mint = modint998;

/*
見かけだおしで, わりとやるだけか
*/

void solve() {
  LL(N, M, K, P, Q);
  VEC(ll, A, N);
  vc<mint> U(M), V(K);
  FOR(i, M) read(U[i]);
  FOR(i, K) read(V[i]);

  // まず g(t) = sum_{u in U, v in V} (u+vt)^P を求める
  vc<mint> SM_U = sum_of_powers<mint>(U, P);
  vc<mint> SM_V = sum_of_powers<mint>(V, P);
  vc<mint> g(P + 1);
  FOR(i, P + 1) g[i] = C<mint>(P, i) * SM_U[P - i] * SM_V[i];

  const int LIM = 100'100;

  // Y[i] = g(1/i)
  vc<mint> X(LIM);
  FOR(i, LIM) X[i] = inv<mint>(i);
  vc<mint> Y = multipoint_eval<mint>(g, X);

  // A の情報
  // 各 i に対して i<=a となる a の個数が欲しい
  vc<mint> CNT(LIM);
  for (auto& a: A) CNT[a] += mint(1);
  FOR_R(i, LIM - 1) CNT[i] += CNT[i + 1];

  auto lpf = lpf_table(LIM);
  vc<mint> F(LIM);
  FOR(x, 1, LIM) {
    for (auto& i: divisors_by_lpf(x, lpf)) { F[x] += Y[x / i] * CNT[i]; }
    F[x] *= mint(x).pow(P);
  }

  F = cumsum<mint>(F, 0);
  FOR(Q) {
    INT(x);
    print(F[x]);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
