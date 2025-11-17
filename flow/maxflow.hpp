template <typename Cap>
struct MaxFlow {
  struct Edge {
    int to, rev;
    Cap cap;
  };

  vc<Edge> edges;
  vc<int> indptr, level;
  vc<Cap> init_cap;
  vc<tuple<int, int, Cap, Cap>> edge_pool;

  const int N, source, sink;
  bool calculated;
  Cap flow_ans;
  vc<int> pos;

  MaxFlow(int N, int source, int sink)
      : N(N), source(source), sink(sink), calculated(0), flow_ans(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    calculated = 0;
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    edge_pool.eb(frm, to, cap, rev_cap);
  }

  void build_csr() {
    int M = len(edge_pool);
    indptr.assign(N + 1, 0);
    for (auto [a, b, c, d] : edge_pool) indptr[a + 1]++, indptr[b + 1]++;
    FOR(i, N) indptr[i + 1] += indptr[i];
    vc<int> prog = indptr;
    edges.resize(2 * M);
    init_cap.resize(2 * M);
    for (auto [a, b, c, d] : edge_pool) {
      int I1 = prog[a], I2 = prog[b];
      edges[I1] = Edge{b, I2, c}, init_cap[I1] = c, prog[a]++;
      edges[I2] = Edge{a, I1, d}, init_cap[I2] = d, prog[b]++;
      pos.eb(I1);
    }
  }

  Cap flow() {
    if (calculated) return flow_ans;
    calculated = true;
    if (indptr.empty()) build_csr();
    vc<int> prog = indptr;
    level.resize(N);
    vc<int> que(N);
    auto bfs = [&]() -> void {
      fill(all(level), -1);
      int ql = 0, qr = 0;
      level[source] = 0, que[qr++] = source;
      while (ql < qr) {
        int v = que[ql++];
        FOR(i, indptr[v], indptr[v + 1]) {
          Edge& e = edges[i];
          if (e.cap > 0 && level[e.to] == -1) {
            level[e.to] = level[v] + 1;
            que[qr++] = e.to;
            if (e.to == sink) return;
          }
        }
      }
    };

    // ACL 参考. v までいくつ流してくるという方式.
    // source-sink上にあるところだけ探索するのでこちらの方が高速ということだと思う.
    auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {
      if (v == source) return lim;
      Cap res = 0;
      int nxt_lv = level[v] - 1;
      for (int& i = prog[v]; i < indptr[v + 1]; ++i) {
        auto& e = edges[i];
        if (level[e.to] != nxt_lv || edges[e.rev].cap == 0) continue;
        Cap a = dfs(dfs, e.to, min(lim - res, edges[e.rev].cap));
        if (a <= 0) continue;
        e.cap += a, edges[e.rev].cap -= a, res += a;
        if (res == lim) return res;
      }
      level[v] = N;
      return res;
    };
    while (1) {
      bfs();
      if (level[sink] == -1) break;
      copy(all(indptr), prog.begin());
      Cap x = dfs(dfs, sink, infty<Cap>);
      flow_ans += x;
      if (flow_ans >= infty<Cap>) return infty<Cap>;
    }
    return flow_ans;
  }

  void change_capacity(int i, Cap after) {
    i = pos[i];
    auto& e = edges[i];
    Cap before = init_cap[i];
    Cap f = before - e.cap;
    init_cap[i] = after;
    if (before < after) {
      calculated = (e.cap > 0);
      e.cap += after - before;
      return;
    }
    e.cap = after - f;
    // 差分を押し戻す処理発生
    if (e.cap < 0) flow_push_back(e);
  }

  void flow_push_back(Edge& e0) {
    auto& re0 = edges[e0.rev];
    int a = re0.to;
    int b = e0.to;
    /*
    辺 e0 の容量が正になるように戻す
    path-cycle 分解を考えれば、
    - uv 辺を含むサイクルを消す
    - suvt パスを消す
    前者は残余グラフで ab パス（flow_ans が変わらない）
    後者は残余グラフで tb, as パス
    */

    vc<int> prog(N + 1);
    auto find_path = [&](int s, int t, Cap lim) -> Cap {
      vc<bool> vis(N);
      copy(all(indptr), prog.begin());
      auto dfs = [&](auto& dfs, int v, Cap f) -> Cap {
        if (v == t) return f;
        for (int& i = prog[v]; i < indptr[v + 1]; ++i) {
          auto& e = edges[i];
          if (vis[e.to] || e.cap <= Cap(0)) continue;
          vis[e.to] = 1;
          Cap a = dfs(dfs, e.to, min(f, e.cap));
          assert(a >= 0);
          if (a == Cap(0)) continue;
          e.cap -= a, edges[e.rev].cap += a;
          return a;
        }
        return 0;
      };
      return dfs(dfs, s, lim);
    };

    while (e0.cap < 0) {
      Cap x = find_path(a, b, -e0.cap);
      if (x == Cap(0)) break;
      e0.cap += x, re0.cap -= x;
    }
    Cap c = -e0.cap;
    while (c > 0 && a != source) {
      Cap x = find_path(a, source, c);
      assert(x > 0);
      c -= x;
    }
    c = -e0.cap;
    while (c > 0 && b != sink) {
      Cap x = find_path(sink, b, c);
      assert(x > 0);
      c -= x;
    }
    c = -e0.cap;
    e0.cap += c, re0.cap -= c;
    flow_ans -= c;
  }

  // frm, to, flow
  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(v, N) {
      FOR(i, indptr[v], indptr[v + 1]) {
        Edge& e = edges[i];
        Cap f = init_cap[i] - e.cap;
        if (f > 0) res.eb(v, e.to, f);
      }
    }
    return res;
  }

  // まだ使ったことがないはずなので要確認
  Graph<int, 1> res_graph() {
    Graph<int, 1> G(N);
    vc<tuple<int, int, Cap>> res;
    FOR(v, N) {
      FOR(i, indptr[v], indptr[v + 1]) {
        Edge& e = edges[i];
        if (e.cap > 0) {
          G.add(v, e.to);
        }
      }
    }
    G.build();
    return G;
  }

  // 最小カットの値および、カットを表す 01 列を返す
  pair<Cap, vc<int>> cut() {
    flow();
    vc<int> res(N);
    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);
    return {flow_ans, res};
  }

  // O(F(N+M)) くらい使って経路復元
  // simple path になる
  vvc<int> path_decomposition() {
    flow();
    auto edges = get_flow_edges();
    vvc<int> TO(N);
    for (auto&& [frm, to, flow] : edges) {
      FOR(flow) TO[frm].eb(to);
    }
    vvc<int> res;
    vc<int> vis(N);

    FOR(flow_ans) {
      vc<int> path = {source};
      vis[source] = 1;
      while (path.back() != sink) {
        int to = POP(TO[path.back()]);
        while (vis[to]) {
          vis[POP(path)] = 0;
        }
        path.eb(to), vis[to] = 1;
      }
      for (auto&& v : path) vis[v] = 0;
      res.eb(path);
    }
    return res;
  }

  void debug() {
#ifdef LOCAL
    print("source", source);
    print("sink", sink);
    print("edges (frm, to, cap, flow)");
    FOR(v, N) {
      FOR(i, indptr[v], indptr[v + 1]) {
        Edge& e = edges[i];
        Cap f = init_cap[i] - e.cap;
        SHOW(i, v, e.to, e.cap, f);
      }
    }
#endif
  }
};
