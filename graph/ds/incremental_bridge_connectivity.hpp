
// O((N + Q) log N)
struct Incremental_Bridge_Connectivity {
  int n;
  UnionFind uf, uf_bridge;

  Incremental_Bridge_Connectivity(int n)
      : n(n), uf(n), uf_bridge(n), par(n, -1), vis(n, -1), time(0) {}

  void add_edge(int a, int b) {
    a = uf_bridge[a], b = uf_bridge[b];
    if (a == b) return;
    if (uf[a] != uf[b]) {
      // bridge
      if (uf.size(a) < uf.size(b)) swap(a, b);
      make_root(b);
      par[b] = a;
      uf.merge(a, b);
      return;
    }

    // cycle. some 2ecc are merged.
    P.clear(), Q.clear();
    int t = time++;
    int p = a, q = b;
    int lca = [&]() -> int {
      while (1) {
        if (p != -1) {
          if (vis[p] == t) return p;
          P.eb(p), vis[p] = t, p = par[p];
          if (p != -1) p = uf_bridge[p];
        }
        if (q != -1) {
          if (vis[q] == t) return q;
          Q.eb(q), vis[q] = t, q = par[q];
          if (q != -1) q = uf_bridge[q];
        }
      }
      assert(0);
      return -1;
    }();
    // merge path
    for (int i : P) {
      uf_bridge.merge(i, a);
      if (i == lca) break;
    }
    for (int i : Q) {
      uf_bridge.merge(i, a);
      if (i == lca) break;
    }
    int r = uf_bridge[a];
    par[r] = par[lca];
  }

  int count_bridges() const { return uf_bridge.n_comp - uf.n_comp; }

 private:
  // 2 edge component からなる森を管理
  // uf_bridge の代表元の親を正しく保持する
  // ただし行先は森の中の 1 点なので、uf_bridge に入れると正しくなる
  vc<int> par;
  void make_root(int v) {
    assert(uf_bridge[v] == v);
    int ch = -1;
    while (v != -1) {
      int p = par[v];
      if (p != -1) p = uf_bridge[p];
      par[v] = ch;
      ch = v;
      v = p;
    }
  }

  // lca 計算用
  vc<int> vis;
  vc<int> P, Q;
  int time;
};
