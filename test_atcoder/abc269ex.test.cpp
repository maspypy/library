#define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_Ex"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "poly/convolution_all.hpp"
#include "poly/sum_of_prefix_suffix_products.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    LL(p);
    --p;
    G.add(p, v);
  }
  G.build();
  Tree<decltype(G)> tree(G);

  using poly = vc<mint>;

  auto dfs = [&](auto& dfs, int v) -> vc<mint> {
    auto P = tree.heavy_path_at(v);
    int n = len(P);
    vc<poly> F(n);
    FOR(i, n) {
      int a = P[i];
      vc<poly> polys;
      for (auto&& e: G[a]) {
        if (tree.head[e.to] == v) continue;
        polys.eb(dfs(dfs, e.to));
      }
      F[i] = convolution_all(polys);
    }
    vc<poly> G(n);
    FOR(i, n) G[i] = {mint(1)};
    G.back() = {mint(0), mint(1)};
    return sum_of_prefix_suffix_products(F, G);
  };
  auto f = dfs(dfs, 0);
  f.erase(f.begin());
  f.resize(N);
  for (auto&& x: f) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
