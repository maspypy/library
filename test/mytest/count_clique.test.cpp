#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/count/count_clique.hpp"

void test() {
  FOR(N, 15) {
    FOR(100) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<0>(N, true)) G.add(a, b);
      G.build();
      vc<int> nbd(N);
      for (auto& e: G.edges) {
        nbd[e.frm] |= 1 << e.to;
        nbd[e.to] |= 1 << e.frm;
      }
      u64 n = 0;
      FOR(s, 1 << N) {
        int ok = 1;
        FOR(j, N) FOR(i, j) {
          if ((s >> i & 1) && (s >> j & 1)) {
            if (!(nbd[i] >> j & 1)) ok = 0;
          }
        }
        n += ok;
      }
      assert(n == count_clique(G));
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}