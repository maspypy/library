#include "graph/scc.hpp"
struct TwoSat {
  vc<int> values;

  Graph<int, 1> G;
  TwoSat(ll n) : G(n + n), values(n, -1) {}
  void add(int a, int b) {
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));
    G.add(a ^ 1, b);
    G.add(b ^ 1, a);
  }
  void set(int a) {
    if (a >= 0)
      values[a] = 1;
    else
      values[~a] = 0;
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    G.add(a ^ 1, a);
  }
  void implies(int a, int b) { add(~a, b); }

  bool calc() {
    G.build();
    ll n = len(values);
    SCC<Graph<int, 1>> scc(G);
    FOR(i, n) {
      if (scc[2 * i] == scc[2 * i + 1]) return false;
      values[i] = scc[2 * i] < scc[2 * i + 1];
    }
    return true;
  }
};