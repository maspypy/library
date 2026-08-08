#include "graph/tree.hpp"
#include "ds/fastset.hpp"
#include "graph/fast_lca.hpp"

template <typename TREE>
struct Compress_Tree {
  FastSet FS;
  TREE& tree;
  Compress_Tree(TREE& tree) : tree(tree) {}

  using GT = typename TREE::Graph_type;
  using WT = typename GT::cost_type;

  pair<vc<int>, GT> compress(vc<int>& V, bool sorted = false) {
    return compress_impl(V, sorted,
                         [&](int a, int b) -> int { return tree.lca(a, b); });
  }

  pair<vc<int>, GT> compress_fast(vc<int>& V, Fast_Lca<TREE>& LCA,
                                  bool sorted = false) {
    return compress_impl(V, sorted,
                         [&](int a, int b) -> int { return LCA.lca(a, b); });
  }

  void sort_vertices(vc<int>& V) {
    int N = tree.N;
    if (len(FS) == 0) FS.build(N);
    for (int v : V) FS.insert(tree.LID[v]);
    int k = 0;
    FS.enumerate(0, N, [&](int i) -> void {
      FS.erase(i);
      V[k++] = tree.V[i];
    });
  }

  template <typename F>
  pair<vc<int>, GT> compress_impl(vc<int> V, bool sorted, F&& get_lca) {
    assert(!V.empty());
    if (!sorted) sort_vertices(V);
    int n = len(V);
    int root = get_lca(V[0], V.back());
    vc<int> key = move(V);
    V.clear();
    V.reserve(2 * n);

    // 圧縮木上の親番号
    vc<int> par;
    par.reserve(2 * n);

    auto add = [&](int v) -> int {
      int k = len(V);
      V.eb(v), par.eb(-1);
      return k;
    };

    add(root);
    vc<int> st = {0};
    st.reserve(2 * n);

    for (int v : key) {
      if (v == root) continue;
      int l = get_lca(V[st.back()], v);
      while (len(st) >= 2 && tree.depth[V[st[len(st) - 2]]] >= tree.depth[l]) {
        int a = st[len(st) - 2], b = POP(st);
        par[b] = a;
      }
      if (V[st.back()] != l) {
        int a = add(l);
        int b = add(v);
        par[st.back()] = par[b] = a;
        st.back() = b;
      } else {
        int b = add(v);
        par[b] = st.back();
      }
    }

    while (len(st) >= 2) {
      int a = st[len(st) - 2], b = POP(st);
      par[b] = a;
    }

    GT G(len(V));
    FOR(v, 1, len(V)) {
      int p = par[v];
      WT d = tree.depth_weighted[V[v]] - tree.depth_weighted[V[p]];
      G.add(p, v, d);
    }
    G.build();
    return {move(V), move(G)};
  }
};