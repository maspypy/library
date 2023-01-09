// (圧縮された木の頂点ラベルたち、グラフ)
template <typename TREE>
pair<vc<int>, typename TREE::Graph_type> compress_tree(TREE& tree, vc<int> V) {
  // 大事な点をリストアップする
  // もともとの根は含まれるようにする
  {
    vc<int> VV = V;
    sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });
    FOR(i, len(V) - 1) { VV.eb(tree.lca(V[i], V[i + 1])); }
    VV.eb(tree.lca(V[0], V.back()));
    VV.eb(tree.V[0]);
    UNIQUE(VV);
    V = VV;
    sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });
  }
  // 辺を張ってグラフを作る
  int n = len(V);
  using GT = typename TREE::Graph_type;
  using WT = typename GT::cost_type;
  GT G(n);
  vc<int> st = {0};
  FOR(i, 1, n) {
    while (1) {
      int p = V[st.back()];
      int v = V[i];
      if (tree.in_subtree(v, p)) break;
      st.pop_back();
    }
    int p = V[st.back()];
    int v = V[i];
    WT d = tree.depth_weighted[v] - tree.depth_weighted[p];
    G.add(st.back(), i, d);
    st.eb(i);
  }
  G.build();
  return {V, G};
}
