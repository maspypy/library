#define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution.hpp"
#include "graph/ds/static_toptree.hpp"

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

  // 全部の数え上げ
  // heavy path 上にない場合の数え上げ (if heavy)
  using poly = vc<mint>;
  using Data = pair<poly, poly>;
  auto from_vertex = [&](int v) -> Data {
    poly f = {1, 1};
    poly g = {1, 0};
    return {f, g};
  };
  auto add_vertex = [&](Data &x, int v) -> Data {
    auto &[f, g] = x;
    g = f;
    f[1] += 1;
    return {f, g};
  };
  auto add_edge = [&](Data &x, int u, int v) -> Data { return x; };
  auto merge_light = [&](Data &x, Data &y) -> Data {
    auto &[f1, g1] = x;
    auto &[f2, g2] = y;
    poly f = convolution<mint>(f1, f2);
    return {f, g1};
  };
  auto merge_heavy = [&](Data &x, Data &y, int a, int b, int c, int d) -> Data {
    auto &[f1, g1] = x;
    auto &[f2, g2] = y;
    // f := (f1-1)g2 + f2
    // g := g1g2
    f1[0] -= 1;
    poly f = convolution<mint>(f1, g2);
    FOR(i, len(f2)) f[i] += f2[i];
    poly g = convolution<mint>(g1, g2);
    return {f, g};
  };

  auto res = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,
                               merge_heavy);
  vc<mint> ANS = res.fi;
  FOR(k, 1, N + 1) {
    mint x = (k < len(ANS) ? ANS[k] : 0);
    print(x);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
