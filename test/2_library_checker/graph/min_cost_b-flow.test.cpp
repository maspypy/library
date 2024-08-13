#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bflow.hpp"

void solve() {
  LL(N, M);
  MinCostFlow<ll, ll> G(N);
  FOR(i, N) {
    LL(b);
    G.add_source(i, b);
  }
  FOR(i, M) {
    LL(frm, to, lo, hi, cost);
    G.add(frm, to, lo, hi, cost);
  }
  auto [ok, cost] = G.solve();
  if (!ok) return print("infeasible");
  print(cost);
  for (auto &&p: G.get_potential()) print(p);
  for (auto &&e: G.get_edges()) { print(e.flow()); }
}

signed main() {
  solve();

  return 0;
}
