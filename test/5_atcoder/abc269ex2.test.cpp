#define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/static_toptree.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

using poly = vc<mint>;
using Data = pair<poly, poly>;

/*
empty も含めて
heavy path 上の点なし・あり
*/

struct TREE_DP {
  using value_type = Data;
  static Data rake(Data &L, Data &R) {
    auto &[f1, g1] = L;
    auto &[f2, g2] = R;
    if (len(f2) < len(g2)) swap(f2, g2);
    FOR(i, len(g2)) f2[i] += g2[i];
    f1 = convolution(f1, f2);
    g1 = convolution(g1, f2);
    return {f1, g1};
  }
  static Data compress(Data &L, Data &R) {
    auto &[f1, g1] = L;
    auto &[f2, g2] = R;
    poly f = convolution<mint>(f1, f2);
    // g1(x) + f1(x)g2(x)
    poly g = convolution<mint>(f1, g2);
    if (len(g) < len(g1)) swap(g, g1);
    FOR(i, len(g1)) g[i] += g1[i];
    return {f, g};
  }
};

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

  auto single = [&](int v) -> Data {
    poly f = {1};
    poly g = {0, 1};
    return {f, g};
  };

  auto [f, g] = STT.tree_dp<TREE_DP>(single);
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