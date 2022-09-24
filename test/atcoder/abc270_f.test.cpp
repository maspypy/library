#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/minimum_spanning_tree.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N, M);
  VEC(ll, X, N);
  VEC(ll, Y, N);
  using T = tuple<int, int, int>;
  VEC(T, dat, M);
  for (auto&& [a, b, c]: dat) { --a, --b; }

  vi cand;

  {
    Graph<ll> G(N);
    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }
    G.build();
    auto [val, used, tree] = minimum_spanning_tree(G);
    if (SUM<int>(used) == N - 1) cand.eb(val);
  }
  {
    Graph<ll> G(N + 1);
    FOR(i, N) G.add(i, N, X[i]);
    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }
    G.build();
    auto [val, used, tree] = minimum_spanning_tree(G);
    if (SUM<int>(used) == N) cand.eb(val);
    cand.eb(val);
  }
  {
    Graph<ll> G(N + 1);
    FOR(i, N) G.add(i, N, Y[i]);
    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }
    G.build();
    auto [val, used, tree] = minimum_spanning_tree(G);
    if (SUM<int>(used) == N) cand.eb(val);
    cand.eb(val);
  }
  {
    Graph<ll> G(N + 2);
    FOR(i, N) G.add(i, N, X[i]);
    FOR(i, N) G.add(i, N + 1, Y[i]);
    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }
    G.build();
    auto [val, used, tree] = minimum_spanning_tree(G);
    if (SUM<int>(used) == N + 1) cand.eb(val);
  }

  print(MIN(cand));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
