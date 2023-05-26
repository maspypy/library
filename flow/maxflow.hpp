template <typename Cap>
struct MaxFlowGraph {
  struct Edge {
    int to, rev;
    Cap cap;
    Cap flow = 0;
  };

  int N;
  vc<tuple<int, int, Cap, Cap>> dat;
  vc<int> prog, level;
  vc<int> que;
  vc<Edge> edges;
  vc<int> indptr;
  Cap flow_ans;
  bool calculated;
  bool is_prepared;

  MaxFlowGraph(int N) : N(N), calculated(0), is_prepared(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    if (frm == to) return;
    dat.eb(frm, to, cap, rev_cap);
  }

  void build() {
    assert(!is_prepared);
    int M = len(dat);
    is_prepared = 1;
    indptr.assign(N, 0);
    for (auto&& [a, b, c, d]: dat) indptr[a]++, indptr[b]++;
    indptr = cumsum<int>(indptr);
    vc<int> nxt_idx = indptr;
    edges.resize(2 * M);
    for (auto&& [a, b, c, d]: dat) {
      int p = nxt_idx[a]++;
      int q = nxt_idx[b]++;
      edges[p] = Edge{b, q, c};
      edges[q] = Edge{a, p, d};
    }
  }

  vc<tuple<int, int, Cap>> get_flow_edges() {
    vc<tuple<int, int, Cap>> res;
    FOR(frm, N) {
      FOR(k, indptr[frm], indptr[frm + 1]) {
        auto& e = edges[k];
        if (e.flow <= 0) continue;
        res.eb(frm, e.to, e.flow);
      }
    }
    return res;
  }

  Cap flow(int source, int sink) {
    assert(is_prepared);
    if (calculated) return flow_ans;
    calculated = true;
    flow_ans = 0;
    while (set_level(source, sink)) {
      prog = indptr;
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

  // 最小カットの値および、カットを表す 01 列を返す
  pair<Cap, vc<int>> cut(int source, int sink) {
    Cap f = flow(source, sink);
    vc<int> res(N);
    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);
    return {f, res};
  }

private:
  bool set_level(int source, int sink) {
    que.resize(N);
    level.assign(N, -1);
    level[source] = 0;
    int l = 0, r = 0;
    que[r++] = source;
    while (l < r) {
      int v = que[l++];
      FOR(k, indptr[v], indptr[v + 1]) {
        auto& e = edges[k];
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que[r++] = e.to;
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, int sink, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < indptr[v + 1]; ++i) {
      auto& e = edges[i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a, e.flow += a;
          edges[e.rev].cap += a, edges[e.rev].flow -= a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};
