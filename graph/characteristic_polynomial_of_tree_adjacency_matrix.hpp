#include "graph/ds/static_toptree.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "poly/convolution.hpp"

template <typename mint>
struct TREE_ADJ_MATRIX_DP {
  using poly = vc<mint>;
  using Data = array<array<poly, 2>, 2>;
  using value_type = Data;

  static void add(poly& f, poly g) {
    if (len(f) < len(g)) f.resize(len(g));
    FOR(i, len(g)) f[i] += g[i];
  };

  static Data rake(Data L, Data R) {
    Data Z;
    add(Z[0][0], convolution(L[0][0], R[0][1]));
    add(Z[0][1], convolution(L[0][1], R[0][1]));
    add(Z[1][0], convolution(L[0][0], R[1][1]));
    add(Z[1][1], convolution(L[0][1], R[1][1]));
    add(Z[1][0], convolution(L[1][0], R[0][1]));
    add(Z[1][1], convolution(L[1][1], R[0][1]));
    return Z;
  }
  static Data compress(Data L, Data R) {
    Data Z;
    FOR(p, 2) FOR(q, 2) FOR(r, 2) { add(Z[p][r], convolution<mint>(L[p][q], R[1 - q][r])); }
    return Z;
  }
};

// det(I-xA) の計算 (固有多項式の reverse になっている)
// weight(i,j)：A[i][j]
// 偶数次だけしか出てこないので loop ありより高速
template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(Graph<int, 0>& G, F weight) {
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  // u, v はもう計算したか
  using Data = array<array<poly, 2>, 2>;
  auto single = [&](int v) -> Data {
    Data X;
    int p = tree.parent[v];
    mint wt = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));
    X[0][0] = poly{mint(1)};
    X[0][1] = poly{mint(1)};                   // loop
    if (p != -1) X[1][1] = poly{mint(0), -wt}; // match
    return X;
  };
  Data X = STT.tree_dp<TREE_ADJ_MATRIX_DP<mint>>(single);
  vc<mint> ANS(G.N + 1);
  FOR(i, len(X[0][1])) { ANS[2 * i] += X[0][1][i]; }
  return ANS;
}

template <typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(Graph<int, 0>& G, F weight) {
  using poly = vc<mint>;
  Tree<Graph<int, 0>> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  using Data = array<array<poly, 2>, 2>;
  auto single = [&](int v) -> Data {
    Data X;
    int p = tree.parent[v];
    mint wt = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));
    X[0][0] = poly{mint(1)};
    X[0][1] = poly{mint(1), -weight(v, v)};             // loop
    if (p != -1) X[1][1] = poly{mint(0), mint(0), -wt}; // match
    return X;
  };
  Data X = STT.tree_dp<TREE_ADJ_MATRIX_DP<mint>>(single);
  vc<mint> ANS(G.N + 1);
  FOR(i, len(X[0][1])) { ANS[i] += X[0][1][i]; }
  return ANS;
}

// det(I-xA) の計算 (固有多項式の reverse になっている)
// weight(i,j)：A[i][j]
template <bool ALLOW_LOOP, typename mint, typename F>
vc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int, 0>& G, F weight) {
  if constexpr (ALLOW_LOOP) {
    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(G, weight);
  } else {
    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(G, weight);
  }
}
