// incremental に辺を追加してよい
// 辺の容量の変更が可能
// 変更する capacity が F のとき、O((N+M)|F|) 時間で更新
template <typename Cap>
struct MaxFlow {
  struct Edge {
    int to, rev;
    Cap cap; // 残っている容量. したがって cap+flow が定数.
    Cap flow = 0;
  };

  const int N, source, sink;
  vvc<Edge> edges;
  vc<pair<int, int>> pos;
  vc<int> prog, level;
  vc<int> que;
  bool calculated;

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
    assert(Cap(0) <= cap);
    int a = len(edges[frm]);
    int b = (frm == to ? a + 1 : len(edges[to]));
    pos.eb(frm, a);
    edges[frm].eb(Edge{to, b, cap, 0});
    edges[to].eb(Edge{frm, a, rev_cap, 0});
  }

  void change_capacity(int i, Cap after) {
    auto [frm, idx] = pos[i];
    auto& e = edges[frm][idx];
    Cap before = e.cap + e.flow;
    if (before < after) {
      calculated = (e.cap > 0);
      e.cap += after - before;
      return;
    }
    e.cap = after - e.flow;
    // 差分を押し戻す処理発生
    if (e.cap < 0) flow_push_back(e);
  }

  void flow_push_back(Edge& e0) {
    auto& re0 = edges[e0.to][e0.rev];
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

    auto find_path = [&](int s, int t, Cap lim) -> Cap {
      vc<bool> vis(N);
      prog.assign(N, 0);
      auto dfs = [&](auto& dfs, int v, Cap f) -> Cap {
        if (v == t) return f;
        for (int& i = prog[v]; i < len(edges[v]); ++i) {
          auto& e = edges[v][i];
          if (vis[e.to] || e.cap <= Cap(0)) continue;
          vis[e.to] = 1;
          Cap a = dfs(dfs, e.to, min(f, e.cap));
          assert(a >= 0);
          if (a == Cap(0)) continue;
          e.cap -= a, e.flow += a;
          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow -= a;
          return a;
        }
        return 0;
      };
      return dfs(dfs, s, lim);
    };

    while (e0.cap < 0) {
      Cap x = find_path(a, b, -e0.cap);
      if (x == Cap(0)) break;
      e0.cap += x, e0.flow -= x;
      re0.cap -= x, re0.flow += x;
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
    e0.cap += c, e0.flow -= c;
    re0.cap -= c, re0.flow += c;
    flow_ans -= c;
  }

  // frm, to, flow
  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(frm, N) {
      for (auto&& e: edges[frm]) {
        if (e.flow <= 0) continue;
        res.eb(frm, e.to, e.flow);
      }
    }
    return res;
  }

  vc<bool> vis;

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

  void debug() {
    print("source", source);
    print("sink", sink);
    print("edges (frm, to, cap, flow)");
    FOR(v, N) {
      for (auto& e: edges[v]) {
        if (e.cap == 0 && e.flow == 0) continue;
        print(v, e.to, e.cap, e.flow);
      }
    }
  }

private:
  Cap flow_ans;

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
