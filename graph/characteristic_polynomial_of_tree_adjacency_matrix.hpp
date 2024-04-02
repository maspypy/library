#include "graph/ds/static_toptree.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "ds/unionfind/unionfind.hpp"

// det(I-xA) の計算 (固有多項式の reverse になっている)
// weight(i,j)：A[i][j]
// 偶数次だけしか出てこないので loop ありより高速
template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(
    Graph<int, 0>& G, F weight) {
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  // u, v はもう計算したか
  using Data = array<array<poly, 2>, 2>;
  auto add = [&](poly& f, poly& g) -> void {
    if (len(f) < len(g)) f.resize(len(g));
    FOR(i, len(g)) f[i] += g[i];
  };
  auto single = [&](int v) -> Data {
    Data X;
    int p = tree.parent[v];
    mint wt = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));
    X[0][0] = poly{mint(1)};
    X[0][1] = poly{mint(1)};                   // loop
    if (p != -1) X[1][1] = poly{mint(0), -wt}; // match
    return X;
  };
  auto rake = [&](Data& X, Data& Y, int u, int v) -> Data {
    Y[0][0].clear(), Y[1][0].clear();
    if (v == -1) {
      X[0][0].clear(), X[1][0].clear();
      Data Z;
      poly F00 = convolution<mint>(X[0][1], Y[0][1]);
      poly F01 = convolution<mint>(X[0][1], Y[1][1]);
      poly F10 = convolution<mint>(X[1][1], Y[0][1]);
      add(Z[0][1], F00), add(Z[1][1], F01), add(Z[1][1], F10);
      return Z;
    }
    Data Z;
    poly &f = Y[0][1], &g = Y[1][1];
    add(Z[0][0], f), add(Z[1][0], g);
    add(Z[0][1], f), add(Z[1][1], g);
    f = convolution<mint>(f, X[1][1]);
    add(Z[1][1], f);
    return Z;
  };
  auto compress = [&](Data& X, Data& Y, int a, int b, int c) -> Data {
    Data Z;
    FOR(p, 2) FOR(q, 2) FOR(r, 2) {
      poly f = X[p][q], &g = Y[1 - q][r];
      f = convolution<mint>(f, g);
      add(Z[p][r], f);
    }
    return Z;
  };
  Data X = STT.tree_dp<Data>(single, rake, compress);
  vc<mint> ANS(G.N + 1);
  FOR(i, len(X[0][1])) { ANS[2 * i] += X[0][1][i]; }
  return ANS;
}

template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(
    Graph<int, 0>& G, F weight) {
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  // u, v はもう計算したか
  using Data = array<array<poly, 2>, 2>;
  auto add = [&](poly& f, poly& g) -> void {
    if (len(f) < len(g)) f.resize(len(g));
    FOR(i, len(g)) f[i] += g[i];
  };
  auto single = [&](int v) -> Data {
    Data X;
    int p = tree.parent[v];
    mint wt = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));
    X[0][0] = poly{mint(1)};
    X[0][1] = poly{mint(1), -weight(v, v)};             // loop
    if (p != -1) X[1][1] = poly{mint(0), mint(0), -wt}; // match
    return X;
  };
  auto rake = [&](Data& X, Data& Y, int u, int v) -> Data {
    Y[0][0].clear(), Y[1][0].clear();
    if (v == -1) {
      X[0][0].clear(), X[1][0].clear();
      Data Z;
      poly F00 = convolution<mint>(X[0][1], Y[0][1]);
      poly F01 = convolution<mint>(X[0][1], Y[1][1]);
      poly F10 = convolution<mint>(X[1][1], Y[0][1]);
      add(Z[0][1], F00), add(Z[1][1], F01), add(Z[1][1], F10);
      return Z;
    }
    Data Z;
    FOR(a, 2) FOR(b, 2) FOR(c, 2) {
      if (a && c) continue;
      poly f = convolution(X[a][b], Y[c][1]);
      add(Z[a + c][b], f);
    }
    return Z;
  };
  auto compress = [&](Data& X, Data& Y, int a, int b, int c) -> Data {
    Data Z;
    FOR(p, 2) FOR(q, 2) FOR(r, 2) {
      poly f = X[p][q], &g = Y[1 - q][r];
      f = convolution<mint>(f, g);
      add(Z[p][r], f);
    }
    return Z;
  };
  Data X = STT.tree_dp<Data>(single, rake, compress);
  vc<mint> ANS(G.N + 1);
  FOR(i, len(X[0][1])) { ANS[i] += X[0][1][i]; }
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
