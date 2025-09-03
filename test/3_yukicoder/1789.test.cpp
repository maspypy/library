#define PROBLEM "https://yukicoder.me/problems/no/1789"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/shortest_path/warshall_floyd.hpp"
#include "graph/tree.hpp"

#include "flow/hungarian.hpp"

void solve() {
  INT(N1);
  Graph<int, 0> G1(N1);
  G1.read_tree();
  INT(N2);
  Graph<int, 0> G2(N2);
  G2.read_tree();

  auto dist = warshall_floyd<int>(G2);
  int ANS = -1;

  FOR(r2, N2) {
    // r2 を根付き木として解く
    // v1, v2 -> 辺の個数の max

    Tree<decltype(G1)> T1(G1, 0);
    Tree<decltype(G2)> T2(G2, r2);

    auto V1 = T1.V;
    auto V2 = T2.V;

    vv(ll, dp, N1, N2, -infty<int>);
    FOR_R(idx2, N2) {
      int v2 = V2[idx2];
      auto ch2 = T2.collect_child(v2);
      int n2 = len(ch2);
      // 方向ごとに頂点を集めておく
      vvc<int> vs(n2);
      FOR(i, n2) {
        int c = ch2[i];
        int L = T2.LID[c], R = T2.RID[c];
        FOR(p, L, R) { vs[i].eb(T2.V[p]); }
      }
      FOR_R(idx1, N1) {
        int v1 = V1[idx1];
        auto ch1 = T1.collect_child(v1);
        int n1 = len(ch1);
        if (n1 == 0) {
          dp[v1][v2] = 0;
          continue;
        }
        if (n1 > n2) continue;
        vv(ll, mat, n1, n2, -infty<int>);
        FOR(i, n1) {
          int w1 = ch1[i];
          FOR(j, n2) {
            for (auto& w2: vs[j]) {
              chmax(mat[i][j], dp[w1][w2] + dist[v2][w2]);
            }
          }
        }
        auto [ans, match, X, Y] = hungarian<ll, false>(mat);
        if (ans < 0) continue;
        dp[v1][v2] = ans;
      }
    }
    chmax(ANS, dp[0][r2]);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
