
// N2^{sqrt(2m)}
// https://www.slideshare.net/wata_orz/ss-12131479
template <typename Gr, typename F>
void enumerate_cliques(Gr& G, F query) {
  int N = G.N;
  auto deg = G.deg_array();
  vc<bool> done(N);
  vv(int, can, N, N);
  for (auto&& e: G.edges) { can[e.frm][e.to] = can[e.to][e.frm] = 1; }

  FOR(N) {
    // 次数最小の頂点の近傍を調べる
    int v = -1;
    int min_d = N;
    FOR(i, N) if (!done[i] && chmin(min_d, deg[i])) v = i;

    vc<int> nbd;
    for (auto&& e: G[v])
      if (!done[e.to]) nbd.eb(e.to);
    vc<int> C = {v};

    auto dfs = [&](auto& dfs, int k) -> void {
      query(C);
      FOR(i, k, len(nbd)) {
        bool ok = 1;
        for (auto&& x: C) {
          if (!can[x][nbd[i]]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          C.eb(nbd[i]);
          dfs(dfs, i + 1);
          C.pop_back();
        }
      }
    };

    dfs(dfs, 0);
    done[v] = 1;
    for (auto&& x: nbd) deg[x]--;
  }
}
