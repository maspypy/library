#include "graph/ds/static_toptree.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "ds/unionfind/unionfind.hpp"

// det(I-xA) の計算 (固有多項式の reverse になっている)
// weight(i,j)：A[i][j]
// 偶数次だけしか出てこないので loop ありより高速
template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(
    Graph<int, 0>& G, F weight) {
  // int N = G.N;
  // vv(mint, A, N, N);
  // vv(mint, B, N, N);
  // FOR(i, N) A[i][i] = 1;
  // FOR(i, N) {
  //   for (auto& e: G[i]) { B[i][e.to] = -weight(i, e.to); }
  // }
  // return det_A_plus_xB(A, B);
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  using Data = array<array<poly, 2>, 2>;
  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {
    if (g.empty()) return;
    if (len(f) < len(g) + s) f.resize(len(g) + s);
    FOR(i, len(g)) f[s + i] += g[i] * wt;
  };
  auto from_vertex = [&](int v) -> Data {
    Data X;
    X[0][0] = poly{mint(1)};
    return X;
  };
  auto add_vertex = [&](Data& X, int v) -> Data { return X; };
  auto add_edge = [&](Data& X, int u, int v) -> Data {
    mint wt = -weight(u, v) * weight(v, u);
    Data Y;
    FOR(a, 2) {
      add(Y[0][0], X[a][0], 0);
      add(Y[1][1], X[a][0], 1, wt);
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
    mint wt = -weight(vb, vc) * weight(vc, vb);
    FOR(a, 2) FOR(d, 2) {
      poly f0 = X[a][0], &f1 = X[a][1];
      poly g0 = Y[0][d], &g1 = Y[1][d];
      // 辺を使う
      poly f = convolution(f0, g0);
      int x = (va != vb ? a : 1);
      int y = (vc != vd ? d : 1);
      add(Z[x][y], f, 1, wt);
      // 辺を使わない
      add(f0, f1, 0), add(g0, g1, 0);
      f = convolution(f0, g0);
      add(Z[a][d], f, 0);
    }
    return Z;
  };

  Data X = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,
                             merge_heavy);
  vc<mint> ANS(G.N + 1);
  FOR(a, 2) FOR(b, 2) {
    FOR(i, len(X[a][b])) { ANS[2 * i] += X[a][b][i]; }
  }
  return ANS;
}

template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(
    Graph<int, 0>& G, F weight) {
  // 点とマッチングに分解
  // マッチング：-w[i][j]w[j][i]x^2
  // 点：1-w[i][i]x
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  using Data = array<array<poly, 2>, 2>;
  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {
    if (g.empty()) return;
    if (len(f) < len(g) + s) f.resize(len(g) + s);
    FOR(i, len(g)) f[s + i] += g[i] * wt;
  };
  auto from_vertex = [&](int v) -> Data {
    mint wt = weight(v, v);
    Data X;
    X[0][0] = poly{mint(1)};
    X[1][1] = poly{mint(1), -wt};
    return X;
  };
  auto add_vertex = [&](Data& X, int v) -> Data {
    mint wt = weight(v, v);
    // 1-wtx
    add(X[1][1], X[0][0], 0, mint(1));
    add(X[1][1], X[0][0], 1, -wt);
    return X;
  };
  auto add_edge = [&](Data& X, int u, int v) -> Data {
    if (X[0][1].empty()) { X[1][0] = X[0][0]; }
    mint wt = weight(u, v) * weight(v, u);
    Data Y;
    add(Y[1][1], X[1][0], 2, -wt);
    add(Y[0][0], X[1][1], 0);
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
    mint wt = weight(vb, vc) * weight(vc, vb);
    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d, 2) {
      bool non_use = 1;
      bool use = (b == 0) && (c == 0);
      if (va != vb && b == 0) non_use = 0;
      if (vc != vd && c == 0) non_use = 0;
      if (!non_use && !use) continue;
      poly f = convolution(X[a][b], Y[c][d]);
      if (non_use) add(Z[a][d], f, 0);
      if (use) {
        int x = (va != vb ? a : 1);
        int y = (vc != vd ? d : 1);
        add(Z[x][y], f, 2, -wt);
      }
    }
    return Z;
  };

  Data X = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,
                             merge_heavy);
  poly& ANS = X[1][1];
  return ANS;
}

// det(I-xA) の計算 (固有多項式の reverse になっている)
// weight(i,j)：A[i][j]
template <bool ALLOW_LOOP, typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int, 0>& G,
                                                      F weight) {
  if constexpr (ALLOW_LOOP) {
    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(
        G, weight);
  } else {
    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(
        G, weight);
  }
}
