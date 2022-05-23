// (圧縮された木の頂点ラベルたち、グラフ)
template <typename HLD>
pair<vc<int>, typename HLD::Graph_type> compress_tree(HLD& hld, vc<int> V) {
  // 大事な点をリストアップする
  // もともとの根は含まれるようにする
  {
    vc<int> VV = V;
    sort(all(V), [&](auto& x, auto& y) { return hld.LID[x] < hld.LID[y]; });
    FOR(i, len(V) - 1) { VV.eb(hld.lca(V[i], V[i + 1])); }
    VV.eb(hld.lca(V[0], V.back()));
    VV.eb(hld.V[0]);
    UNIQUE(VV);
    V = VV;
    sort(all(V), [&](auto& x, auto& y) { return hld.LID[x] < hld.LID[y]; });
  }
  // 辺を張ってグラフを作る
  int n = len(V);
  using Graph = typename HLD::Graph_type;
  using WT = typename Graph::cost_type;
  Graph G(n);
  vc<int> st = {0};
  FOR(i, 1, n) {
    while (1) {
      int p = V[st.back()];
      int v = V[i];
      if (hld.in_subtree(v, p)) break;
      st.pop_back();
    }
    int p = V[st.back()];
    int v = V[i];
    WT d = hld.depth_weighted[v] - hld.depth_weighted[p];
    G.add(st.back(), i, d);
    st.eb(i);
  }
  G.build();
  return {V, G};
}