#define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/static_toptree.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(--p, v);
  }
  G.build();

  Tree<decltype(G)> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);
  /*
  heavy path 上の点なし・あり
  */
  using poly = vc<mint>;
  using Data = pair<poly, poly>;

  auto single = [&](int v) -> Data {
    poly f = {1};
    poly g = {0, 1};
    return {f, g};
  };

  auto rake = [&](Data &x, Data &y, int u, int v) -> Data {
    auto &[f1, g1] = x;
    auto &[f2, g2] = y;
    if (v == -1) {
      if (len(f1) < len(g1)) swap(f1, g1);
      if (len(f2) < len(g2)) swap(f2, g2);
      FOR(i, len(g1)) f1[i] += g1[i];
      FOR(i, len(g2)) f2[i] += g2[i];
      poly f = convolution<mint>(f1, f2);
      return {f, {}};
    }
    if (len(f2) < len(g2)) swap(f2, g2);
    FOR(i, len(g2)) f2[i] += g2[i];
    poly g = f2;
    g.insert(g.begin(), 0);
    return {f2, g};
  };

  auto compress = [&](Data &x, Data &y, int a, int b, int c) -> Data {
    auto &[f1, g1] = x;
    auto &[f2, g2] = y;
    poly f = convolution<mint>(f1, f2);
    // g1(x) + f1(x)g2(x)
    poly g = convolution<mint>(f1, g2);
    FOR(i, len(g1)) g[i] += g1[i];

    return {f, g};
  };

  auto [f, g] = STT.tree_dp<Data>(single, rake, compress);
  vc<mint> ANS(N + 1);
  FOR(i, len(f)) ANS[i] += f[i];
  FOR(i, len(g)) ANS[i] += g[i];
  FOR(i, 1, N + 1) print(ANS[i]);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
