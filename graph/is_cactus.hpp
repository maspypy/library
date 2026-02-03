
// EDGE = true: 各辺が唯一のサイクル（関節点でサイクルまたは辺）
// EDGE = false： 各頂点が唯一のサイクル（橋でサイクルまたは辺）
template <bool EDGE>
bool is_cactus(Graph<int, 0> G) {
  if constexpr (EDGE) {
    static_assert(EDGE);
    auto BCT = block_cut(G);
    int N = G.N, n = BCT.N;
    Tree<decltype(BCT)> tree(BCT);
    vc<int> NV(n), NE(n);
    FOR(i, N, n) NV[i] = BCT.deg(i);
    for (auto& e : G.edges) {
      int a = e.frm, b = e.to;
      int i = tree.jump(a, b, 1);
      NE[i]++;
    }
    FOR(i, N, n) {
      int a = NV[i], b = NE[i];
      if (b == 1) continue;
      if (a < b) return false;
    }
    return true;
  } else {
    auto [nc, comp] = two_edge_component(G);
    vc<int> NV(nc), NE(nc);
    FOR(v, G.N) NV[comp[v]]++;
    for (auto& e : G.edges) {
      int a = e.frm, b = e.to;
      a = comp[a], b = comp[b];
      if (a == b) NE[a]++;
    }
    FOR(i, nc) {
      if (NV[i] < NE[i]) return false;
    }
    return true;
  }
}
