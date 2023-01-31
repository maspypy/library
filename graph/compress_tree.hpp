// (圧縮された木の頂点ラベルたち、グラフ)
template <typename TREE>
pair<vc<int>, typename TREE::Graph_type> compress_tree(TREE& tree, vc<int> V) {
  // 大事な点をリストアップする
  // もともとの根は含まれるようにする
  sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });
  int n = len(V);
  FOR(i, n) {
    int j = (i + 1 == n ? 0 : i + 1);
    V.eb(tree.lca(V[i], V[j]));
  }
  V.eb(tree.V[0]);
  sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });
  V.erase(unique(all(V)), V.end());
  // 辺を張ってグラフを作る
  n = len(V);
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
