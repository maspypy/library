#define PROBLEM "https://atcoder.jp/contests/arc153/tasks/arc153_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "graph/base.hpp"
#include "enumerate/product.hpp"
#include "seq/famous/stirling_number_2.hpp"
#include "graph/block_cut.hpp"

using mint = modint998;

void naive(Graph<bool, 0> G) {
  const int N = G.N;
  const int M = G.M;

  int ANS = 0;

  auto F = [&](vc<int> color) -> void {
    vv(int, mat, N, N, -1);
    FOR(i, M) {
      auto e = G.edges[i];
      int a = e.frm, b = e.to;
      mat[a][b] = mat[b][a] = color[i];
    }
    vc<int> P(N);
    iota(all(P), 0);
    do {
      int s = 0;
      FOR(i, N - 1) {
        int a = P[i], b = P[i + 1];
        if (mat[a][b] == -1) break;
        s |= 1 << mat[a][b];
      }
      if (s == 7) {
        ++ANS;
        return;
      }
    } while (next_permutation(all(P)));
  };

  enumerate_product(3, M, F);
  print(ANS);
}

void solve() {
  LL(N, M);
  Graph<bool, 0> G(N);
  G.read_graph(M);
  if (N <= 4) return naive(G);

  // i 元集合から 3 元集合への全射の数え上げ
  vc<mint> S = stirling_number_2_k<mint>(3, max(N, M));
  for (auto&& x: S) x *= mint(6);

  // 3 色で塗る方法全体
  mint ANS = S[M];

  auto BCT = block_cut(G);
  auto deg = BCT.deg_array();
  // 3-cycle であって、唯一の関節点を含むもの → 6 を引く
  FOR(block, N, BCT.N) {
    if (deg[block] != 3) continue;
    vc<int> nbd;
    for (auto&& e: BCT[block]) nbd.eb(e.to);
    int cnt = 0;
    for (auto&& v: nbd)
      if (deg[v] > 1) ++cnt;
    if (cnt == 1) ANS -= mint(6);
  }
  // cut vertex の次数を n として
  FOR(cut, N) {
    int n = deg[cut];
    ANS -= S[n];
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
