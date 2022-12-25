#include "graph/strongly_connected_component.hpp"

struct TwoSat {
  Graph<int, 1> G;
  vc<int> values;

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

  pair<bool, vc<int>> calc() {
    G.build();
    ll n = len(values);
    auto [C, comp] = strongly_connected_component(G);
    FOR(i, n) {
      if (comp[2 * i] == comp[2 * i + 1]) return {false, values};
      values[i] = comp[2 * i] < comp[2 * i + 1];
    }
    return {true, values};
  }
};