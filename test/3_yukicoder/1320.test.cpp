#define PROBLEM "https://yukicoder.me/problems/no/1320"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/minimum_cost_cycle.hpp"

void solve() {
  INT(t);
  INT(N, M);
  ll ANS = 0;
  if (t == 0) {
    Graph<int, 0> G(N);
    G.read_graph(M, 1);
    auto [wt, vs, es] = minimum_cost_cycle<ll>(G);
    ANS = wt;
    if (ANS != infty<ll>) {
      int n = len(es);
      assert(len(vs) == n + 1);
      assert(vs[0] == vs[n]);
      ll cost = 0;
      FOR(i, n) {
        auto& e = G.edges[es[i]];
        int a = vs[i], b = vs[i + 1];
        assert((a == vs[i] && b == vs[i + 1])
               || (a == vs[i + 1] && b == vs[i]));
        cost += e.cost;
      }
      assert(wt == cost);
    }
  }
  if (t == 1) {
    Graph<int, 1> G(N);
    G.read_graph(M, 1);
    auto [wt, vs, es] = minimum_cost_cycle<ll>(G);
    ANS = wt;
    if (ANS != infty<ll>) {
      int n = len(es);
      assert(len(vs) == n + 1);
      assert(vs[0] == vs[n]);
      ll cost = 0;
      FOR(i, n) {
        auto& e = G.edges[es[i]];
        assert(e.frm == vs[i] && e.to == vs[i + 1]);
        cost += e.cost;
      }
      assert(wt == cost);
    }
  }
  if (ANS == infty<ll>) ANS = -1;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
