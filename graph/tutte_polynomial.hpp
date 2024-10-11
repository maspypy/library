#include "ds/unionfind/unionfind.hpp"
#include "setfunc/sps_exp.hpp"
#include "setfunc/sps_composition.hpp"

template <typename mint, int NMAX>
mint Tutte_Polynomial_Eval_connected(Graph<int, 0> G, mint X, mint Y) {
  int N = G.N;
  X -= 1, Y -= 1;
  /*
  V の連結成分分解を考えると,
  各部分集合に S に対して, S を span する A の選び方に対する y^{cycle} の sum を F[S] として
  c[n]F^n/n!, c[n] = X^{n-k(E)} として EGF composition でできる.

  F[S] の計算
  1 点ずつ足していく
  集合に辺の個数に応じた重みをつけて exp
  重み C(N,1) + C(N,2)Y + C(N,3)YY+...
  */

  vv(mint, bin, N + 1, N + 1);
  bin[0][0] = 1;
  FOR(i, N) FOR(j, i + 1) bin[i + 1][j] += bin[i][j], bin[i + 1][j + 1] += bin[i][j];
  vc<mint> wt(N + 1);
  FOR(n, 1, N + 1) {
    mint pow = 1;
    FOR(m, 1, n + 1) { wt[n] += bin[n][m] * pow, pow *= Y; }
  }
  vc<mint> F(1 << N);
  FOR(v, N) {
    u32 nbd = 0;
    for (auto& e: G[v]) nbd |= 1 << e.to;
    vc<mint> f(1 << v);
    FOR(s, 1 << v) { f[s] = F[s] * wt[popcnt(s & nbd)]; }
    f = sps_exp<mint, NMAX>(f);
    FOR(s, 1 << v) { F[s | 1 << v] = f[s]; }
  }
  if (X == mint(0)) { return F.back(); }

  // X で割れないときはこうすれば動く. 何もかもが環で動作する.
  // vc<mint> c(N + 1);
  // mint pow = 1;
  // FOR(n, 1, N + 1) { c[n] = pow, pow *= X; }
  // F = sps_composition_egf<mint, NMAX>(c, F);
  // return F.back();
  FOR(s, 1 << N) F[s] *= X;
  F = sps_exp<mint, NMAX>(F);
  return F.back() * X.inverse();
}

// QOJ 45
template <typename mint, int NMAX>
mint Tutte_Polynomial_Eval(Graph<int, 0> G, mint X, mint Y) {
  int N = G.N;
  UnionFind uf(N);
  for (auto& e: G.edges) uf.merge(e.frm, e.to);
  vvc<int> vs(N);
  FOR(v, N) vs[uf[v]].eb(v);
  mint ANS = 1;
  for (auto& V: vs) {
    if (V.empty()) continue;
    Graph<int, 0> H = G.rearrange(V);
    ANS *= Tutte_Polynomial_Eval_connected<mint, NMAX>(H, X, Y);
  }
  return ANS;
}
