#define PROBLEM "https://yukicoder.me/problems/no/1400"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_bitset.hpp"
#include "graph/shortest_path/bfs_bitset.hpp"

using BS = My_Bitset;

void solve() {
  LL(N, T);
  vc<BS> G(N + N, BS(N + N));
  FOR(i, N) {
    STR(S);
    FOR(j, N) {
      if (S[j] == '0') continue;
      G[i][j + N] = 1;
      G[i + N][j] = 1;
    }
  }

  FOR(s, N) {
    auto dist = bfs_bitset<BS>(G, s);
    if (T % 2 == 0) {
      FOR(t, N) {
        if (dist[t] == -1 || dist[t] > T) return No();
      }
    }
    if (T % 2 == 1) {
      FOR(t, N, N + N) {
        if (dist[t] == -1 || dist[t] > T) return No();
      }
    }
  }
  Yes();
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}