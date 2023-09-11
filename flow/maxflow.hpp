// incremental に辺を追加してよい
template <typename Cap>
struct MaxFlow {
  struct Edge {
    int to, rev;
    Cap cap;
    Cap flow = 0;
  };

  const int N, source, sink;
  vvc<Edge> edges;
  vc<int> prog, level;
  vc<int> que;
  bool calculated;
  Cap flow_ans;

  MaxFlow(int N, int source, int sink)
      : N(N),
        source(source),
        sink(sink),
        edges(N),
        calculated(0),
        flow_ans(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    calculated = 0;
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(frm != to);
    assert(Cap(0) <= cap);
    if (frm == to) return;
    int a = len(edges[frm]);
    int b = len(edges[to]);
    edges[frm].eb(Edge{to, b, cap, 0});
    edges[to].eb(Edge{frm, a, cap, 0});
  }

  // frm, to, flow
  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(frm, N) {
      for (auto&& e: edges[frm]) {
        if (e.flow == 0) continue;
        res.eb(frm, e.to, e.flow);
      }
    }
    return res;
  }

  // 差分ではなくこれまでの総量
  Cap flow() {
    if (calculated) return flow_ans;
    calculated = true;
    while (set_level()) {
      prog.assign(N, 0);
      while (1) {
        Cap x = flow_dfs(source, infty<Cap>);
        if (x == 0) break;
        flow_ans += x;
        chmin(flow_ans, infty<Cap>);
        if (flow_ans == infty<Cap>) return flow_ans;
      }
    }
    return flow_ans;
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
    for (auto&& [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to); }
    vvc<int> res;
    vc<int> vis(N);

    FOR(flow_ans) {
      vc<int> path = {source};
      vis[source] = 1;
      while (path.back() != sink) {
        int to = POP(TO[path.back()]);
        while (vis[to]) { vis[POP(path)] = 0; }
        path.eb(to), vis[to] = 1;
      }
      for (auto&& v: path) vis[v] = 0;
      res.eb(path);
    }
    return res;
  }

private:
  bool set_level() {
    que.resize(N);
    level.assign(N, -1);
    level[source] = 0;
    int l = 0, r = 0;
    que[r++] = source;
    while (l < r) {
      int v = que[l++];
      for (auto&& e: edges[v]) {
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que[r++] = e.to;
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < len(edges[v]); ++i) {
      auto& e = edges[v][i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a, e.flow += a;
          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow -= a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};
