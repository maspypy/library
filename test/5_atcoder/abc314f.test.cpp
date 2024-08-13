#define PROBLEM "https://atcoder.jp/contests/abc314/tasks/abc314_f"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_of_unionfind.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vc<pair<int, int>> query;
  FOR(N - 1) {
    LL(a, b);
    query.eb(--a, --b);
  }

  auto G = tree_of_unionfind(N, query, false);
  int root = N + N - 2;
  vc<int> sz(N + N - 1);

  {
    auto dfs = [&](auto& dfs, int v) -> void {
      if (0 <= v && v < N) sz[v]++;
      for (auto&& e: G[v]) {
        dfs(dfs, e.to);
        sz[v] += sz[e.to];
      }
    };
    dfs(dfs, root);
  }

  vc<mint> dp(N + N - 1);
  {
    auto dfs = [&](auto& dfs, int v) -> void {
      if (v < N) return;
      vc<int> ch;
      for (auto&& e: G[v]) ch.eb(e.to);
      assert(len(ch) == 2);
      int s = ch[0], t = ch[1];
      ll a = sz[s], b = sz[t];
      mint ps = mint(a) / mint(a + b);
      mint qs = mint(1) - ps;
      dp[s] += dp[v] + ps;
      dp[t] += dp[v] + qs;
      dfs(dfs, s);
      dfs(dfs, t);
    };
    dfs(dfs, root);
  }
  // print(sz);
  dp.resize(N);
  print(dp);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
