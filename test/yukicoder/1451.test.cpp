#define PROBLEM "https://yukicoder.me/problems/no/1451"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_of_unionfind.hpp"
#include "graph/tree.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N, M);
  using P = pair<int, int>;
  VEC(P, AB, M);
  for (auto&& [a, b]: AB) --a, --b;
  auto G = tree_of_unionfind(N, AB, true);
  Tree<decltype(G)> tree(G, N + M);

  vc<mint> ANS(N);
  vi SZ(N + M + 1);
  FOR(v, N) SZ[v] = 1;
  auto V = tree.V;
  FOR_R(i, len(V)) {
    int v = V[i];
    int p = tree.parent[v];
    if (p != -1) SZ[p] += SZ[v];
  }

  auto dfs = [&](auto& dfs, int v, mint p) -> void {
    if (v < N) {
      ANS[v] = p;
      return;
    }

    auto ch = tree.collect_child(v);
    if (len(ch) == 1) return dfs(dfs, ch[0], p);
    int a = ch[0], b = ch[1];
    if (SZ[a] == SZ[b]) {
      dfs(dfs, a, p * inv<mint>(2));
      dfs(dfs, b, p * inv<mint>(2));
    }
    if (SZ[a] > SZ[b]) { dfs(dfs, a, p); }
    if (SZ[a] < SZ[b]) { dfs(dfs, b, p); }
  };

  for (auto&& e: G[N + M]) dfs(dfs, e.to, mint(1));
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
