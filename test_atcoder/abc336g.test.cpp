#define PROBLEM "https://atcoder.jp/contests/abc336/tasks/abc336_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/BEST.hpp"

using mint = modint998;

void solve() {
  ll N = 16;
  VEC(ll, A, N);

  mint ANS = 0;
  FOR(a, 8) FOR(b, 8) {
    // a ではじまり b で終わる
    // b->a を足して cycle を数える
    Graph<ll, 1> G(8);
    FOR(s, 16) {
      if (A[s] == 0) continue;
      int a = s >> 1;
      int b = s & 7;
      G.add(a, b, A[s]);
    }
    G.add(b, a, 1);
    G.build();
    UnionFind uf(8);
    for (auto& e: G.edges) {
      if (e.cost > 0) { uf.merge(e.frm, e.to); }
    }
    vc<int> V;
    vi indeg(8), outdeg(8);
    for (auto& e: G.edges) {
      indeg[e.to] += e.cost;
      outdeg[e.frm] += e.cost;
    }
    bool ok = 1;
    FOR(v, 8) {
      if (indeg[v] == 0 && outdeg[v] == 0) continue;
      if (indeg[v] != outdeg[v]) ok = 0;
      if (uf[v] != uf[a]) ok = 0;
      V.eb(v);
    }
    if (!ok) continue;
    G = G.rearrange(V);
    vc<int> mul;
    for (auto& e: G.edges) { mul.eb(e.cost); }
    mint x = BEST_theorem<mint>(G, mul);
    for (auto& a: A) x *= fact_inv<mint>(a);
    // 辺ラベルの対称性を除く
    ANS += x;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
