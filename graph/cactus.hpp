
vvc<int> get_cactus_cycle(Graph<int, 0>& G, Graph<int, 0>& BCT,
                          Tree<Graph<int, 0>>& tree) {
  vvc<pair<int, int>> es(BCT.N);
  vvc<int> cs(BCT.N);
  for (auto& e : G.edges) {
    int a = e.frm, b = e.to;
    int k = tree.jump(a, b, 1);
    es[k].eb(a, b);
  }
  vc<int> SM(G.N);

  FOR(k, G.N, BCT.N) {
    auto& E = es[k];
    if (len(E) == 1) continue;
    for (auto& [a, b] : E) SM[a] += b, SM[b] += a;
    vc<int> C;
    C.eb(E[0].fi);
    C.eb(E[0].se);
    while (C.back() != C[0]) {
      int a = C[len(C) - 2], b = C[len(C) - 1];
      C.eb(SM[b] - a);
    }
    POP(C);
    cs[k] = C;
    for (auto& [a, b] : E) SM[a] -= b, SM[b] -= a;
  }
  return cs;
}