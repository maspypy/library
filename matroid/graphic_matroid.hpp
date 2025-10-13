struct Graphic_Matroid {
  Graph<int, 0> G;
  vc<int> root, dep, par, que;

  Graphic_Matroid(Graph<int, 0> &G)
      : G(G), root(G.N), dep(G.N), par(G.N), que(G.N) {}

  int size() { return G.M; }

  const vc<bool> *I = nullptr;
  void prepare(const vc<bool> &_I) {
    I = &_I;
    int N = G.N, M = G.M;
    assert(int(I->size()) == M);
    root.assign(N, -1);
    auto calc_frm = [&](int s) -> void {
      int ql = 0, qr = 0;
      root[s] = s, dep[s] = 0, par[s] = -1;
      que[qr++] = s;
      while (ql < qr) {
        int v = que[ql++];
        for (auto &e : G[v]) {
          if ((*I)[e.id] && root[e.to] == -1) {
            root[e.to] = s, dep[e.to] = dep[v] + 1, par[e.to] = e.id;
            que[qr++] = e.to;
          }
        }
      }
    };
    FOR(s, N) if (root[s] == -1) calc_frm(s);
  }

  bool can_add(int i) {
    int a = G.edges[i].frm, b = G.edges[i].to;
    return root[a] != root[b];
  }

  // i を追加して j を削除
  template <typename F>
  void for_add_rm(int i, F &&f) const {
    assert(!(*I)[i]);
    int a = G.edges[i].frm, b = G.edges[i].to;
    if (root[a] != root[b]) {
      FOR(j, G.M) {
        if ((*I)[j]) f(j);
      }
      return;
    }
    if (dep[a] > dep[b]) swap(a, b);
    while (dep[a] < dep[b]) {
      int j = par[b];
      f(j), b = G.edges[j].frm ^ G.edges[j].to ^ b;
    }
    while (a != b) {
      int j = par[a];
      f(j), a = G.edges[j].frm ^ G.edges[j].to ^ a;
      j = par[b];
      f(j), b = G.edges[j].frm ^ G.edges[j].to ^ b;
    }
  }
};
