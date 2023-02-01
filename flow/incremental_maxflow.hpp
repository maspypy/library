template <typename Cap>
struct Incremental_MaxFlow {
  struct Edge {
    int to, rev;
    Cap cap;
  };

  int N;
  int source, sink;
  Cap flow_ans;
  vvc<Edge> G;
  vc<int> prog, level;

  Incremental_MaxFlow(int N, int source, int sinkF)
      : N(N), source(source), sink(sink), flow_ans(0) {
    G.resize(N);
  }

  void add(int frm, int to, Cap cap) {
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    if (len(G) < N) G.resize(N);
    G[frm].eb(Edge{to, (int)G[to].size(), cap});
    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});
  }

  Cap flow() {
    while (set_level(source, sink)) {
      fill(all(prog), 0);
      prog.assign(N, 0);
      while (1) {
        Cap x = flow_dfs(source, sink, infty<Cap>);
        if (x == 0) break;
        flow_ans += x;
        chmin(flow_ans, infty<Cap>);
        if (flow_ans == infty<Cap>) return flow_ans;
      }
    }
    return flow_ans;
  }

  // 残余グラフの辺
  vc<tuple<int, int, Cap>> get_edges() {
    vc<tuple<int, int, Cap>> edges;
    FOR(v, N) for (auto&& e: G[v]) { edges.eb(v, e.to, e.cap); }
    return edges;
  }

private:
  bool set_level(int source, int sink) {
    level.assign(N, -1);
    level[source] = 0;
    queue<int> que;
    que.push(source);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e: G[v]) {
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que.push(e.to);
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, int sink, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < (int)G[v].size(); ++i) {
      auto& e = G[v][i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a;
          G[e.to][e.rev].cap += a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};