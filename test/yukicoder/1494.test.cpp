#define PROBLEM "https://yukicoder.me/problems/no/1494"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "graph/tree_dp/rerooting_dp.hpp"

void solve() {
  LL(N);
  STR(S);
  Graph<char, 0> G(N);
  G.read_tree(1);
  Tree<decltype(G)> tree(G);

  // 消費した S の文字数 → LCS
  using Data = vc<int>;
  Data unit = vc<int>(len(S) + 1);

  auto fee = [&](Data x, Data y) -> Data {
    FOR(i, len(S) + 1) chmax(x[i], y[i]);
    return x;
  };
  auto fev = [&](Data x, int v) -> Data { return x; };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data {
    char c = e.cost;
    FOR_R(j, len(S)) {
      if (S[j] == c) chmax(x[j + 1], x[j] + 1);
    }
    FOR(j, len(S)) chmax(x[j + 1], x[j]);
    return x;
  };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  ll ANS = 0;
  FOR(v, N) {
    auto x = dp[v];
    chmax(ANS, MAX(x));
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
