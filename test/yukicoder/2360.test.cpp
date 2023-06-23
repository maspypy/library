#define PROBLEM "https://yukicoder.me/problems/no/2360"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_dp/rerooting_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(string, A, N);
  Graph<bool, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  vc<mint> POW = {1};
  FOR(100) POW.eb(POW.back() * mint(10));

  using Data = pair<mint, mint>; // cnt, sum
  Data unit = {mint(0), mint(0)};
  auto fee = [&](Data x, Data y) -> Data { return {x.fi + y.fi, x.se + y.se}; };
  auto fev = [&](Data x, int v) -> Data {
    mint val = stoi(A[v]);
    mint pow = POW[len(A[v])];
    return {x.fi + mint(1), x.se * pow + val * (x.fi + mint(1))};
  };
  // e は v に入る有向辺
  auto fve = [&](Data x, auto& e) -> Data { return x; };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  vc<mint> ANS(N);
  FOR(v, N) ANS[v] = dp[v].se;
  // print(ANS);
  print(SUM<mint>(ANS));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
