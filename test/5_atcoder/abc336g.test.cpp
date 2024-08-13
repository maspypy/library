#define PROBLEM "https://atcoder.jp/contests/abc336/tasks/abc336_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/count/BEST.hpp"

using mint = modint998;

void solve() {
  ll N = 16;
  VEC(int, A, N);

  mint ANS = 0;
  FOR(a, 8) FOR(b, 8) {
    // a ではじまり b で終わる
    // b->a を足して cycle を数える
    Graph<ll, 1> G(8);
    FOR(s, 16) {
      int a = s >> 1;
      int b = s & 7;
      G.add(a, b, A[s]);
    }
    G.add(b, a, 1);
    G.build();
    vc<int> mul = A;
    mul.eb(1);
    assert(len(G.edges) == len(mul));
    mint x = BEST_theorem<mint, 0>(G, mul);
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
