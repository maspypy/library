#include "graph/ds/static_toptree.hpp"
#include "poly/convolution.hpp"

// ans[k] := #(matching on G, size=k)
// 隣接行列の特性多項式を求めることと等価
template <typename mint>
vc<mint> count_matching_on_tree(Graph<int, 0>& G) {
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  using Data = array<array<poly, 2>, 2>;
  auto add = [&](poly& f, poly& g, int s) -> void {
    if (g.empty()) return;
    if (len(f) < len(g) + s) f.resize(len(g) + s);
    FOR(i, len(g)) f[s + i] += g[i];
  };
  auto from_vertex = [&](int v) -> Data {
    Data X;
    X[0][0] = poly{mint(1)};
    return X;
  };
  auto add_vertex = [&](Data& X, int v) -> Data { return X; };
  auto add_edge = [&](Data& X, int u, int v) -> Data {
    Data Y;
    FOR(a, 2) {
      add(Y[0][0], X[a][0], 0);
      add(Y[1][1], X[a][0], 1);
      add(Y[0][0], X[a][1], 0);
    }
    return Y;
  };
  auto merge_light = [&](Data& X, Data& Y) -> Data {
    poly &X0 = X[0][0], &X1 = X[1][1];
    poly &Y0 = Y[0][0], &Y1 = Y[1][1];
    poly A = convolution(X0, Y0);
    poly B = convolution(X0, Y1);
    poly C = convolution(X1, Y0);
    Data Z;
    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1], C, 0);
    return Z;
  };
  auto merge_heavy
      = [&](Data& X, Data& Y, int va, int vb, int vc, int vd) -> Data {
    Data Z;
    FOR(a, 2) FOR(d, 2) {
      poly f0 = X[a][0], &f1 = X[a][1];
      poly g0 = Y[0][d], &g1 = Y[1][d];
      // 辺を使う
      poly f = convolution(f0, g0);
      int x = (va != vb ? a : 1);
      int y = (vc != vd ? d : 1);
      add(Z[x][y], f, 1);
      // 辺を使わない
      add(f0, f1, 0), add(g0, g1, 0);
      f = convolution(f0, g0);
      add(Z[a][d], f, 0);
    }
    return Z;
  };

  Data X = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,
                             merge_heavy);
  vc<mint> ANS;
  FOR(a, 2) FOR(b, 2) { add(ANS, X[a][b], 0); }
  return ANS;
}