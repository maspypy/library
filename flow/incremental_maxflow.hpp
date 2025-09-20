// 流した後で辺を追加してもよい
template <typename Cap>
struct Incremental_MaxFlow {
  // flow が欲しい場合には init_cap との差分から求める. 残余グラフだけ持つ.
  struct Edge {
    int to;
    Cap cap;
  };

  vc<Edge> edges;
  vc<Cap> init_cap;

  const int N, source, sink;
  vc<int> head, nxt;
  vc<int> prog, level;
  bool calculated;
  Cap flow_ans;

  Incremental_MaxFlow(int N, int source, int sink)
      : N(N),
        source(source),
        sink(sink),
        head(N, -1),
        prog(N, -1),
        level(N, -1),
        calculated(0),
        flow_ans(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    calculated = 0;
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    if (frm == to) return;
    nxt.eb(head[frm]), head[frm] = len(nxt) - 1, edges.eb(Edge{to, cap});
    nxt.eb(head[to]), head[to] = len(nxt) - 1, edges.eb(Edge{frm, rev_cap});
    init_cap.eb(cap), init_cap.eb(rev_cap);
  }

  Cap flow() {
    if (calculated) return flow_ans;
    calculated = true;
    vc<int> level(N, -1);
    vc<int> que(N);
    auto bfs = [&]() -> void {
      fill(all(level), -1);
      int ql = 0, qr = 0;
      level[source] = 0, que[qr++] = source;
      while (ql < qr) {
        int v = que[ql++];
        for (int i = head[v]; i != -1; i = nxt[i]) {
          Edge& e = edges[i];
          if (e.cap > 0 && level[e.to] == -1) {
            level[e.to] = level[v] + 1;
            que[qr++] = e.to;
            if (e.to == sink) return;
          }
        }
      }
    };
    vc<int> prog = head;
    // ACL 参考. v までいくつ流してくるという方式.
    // source-sink上にあるところだけ探索するのでこちらの方が高速ということだと思う.
    auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {
      if (v == source) return lim;
      Cap res = 0;
      int nxt_lv = level[v] - 1;
      for (int& i = prog[v]; i != -1; i = nxt[i]) {
        auto& e = edges[i];
        if (level[e.to] != nxt_lv || edges[i ^ 1].cap == 0) continue;
        Cap a = dfs(dfs, e.to, min(lim - res, edges[i ^ 1].cap));
        e.cap += a, edges[i ^ 1].cap -= a, res += a;
        if (res == lim) return res;
      }
      level[v] = N;
      return res;
    };
    while (1) {
      bfs();
      if (level[sink] == -1) break;
      copy(all(head), prog.begin());
      Cap x = dfs(dfs, sink, infty<Cap>);
      flow_ans += x;
      if (flow_ans >= infty<Cap>) return infty<Cap>;
    }
    return flow_ans;
  }  // frm, to, flow
  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(v, N) {
      for (int i = head[v]; i != -1; i = nxt[i]) {
        Edge& e = edges[i];
        Cap f = init_cap[i] - e.cap;
        if (f > 0) res.eb(v, e.to, f);
      }
    }
    return res;
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
};
