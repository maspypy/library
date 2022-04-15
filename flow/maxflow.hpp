template <typename Cap = int>
struct MaxFlowGraph {
  const Cap INF;

  struct Edge {
    int frm, to;
    Cap cap;
    int idx;
  };

  int N;
  vc<int> indptr;
  vc<Edge> edges;
  vc<Cap> edge_flow;

  vc<Edge> csr_edges;
  vc<int> rev;
  vc<int> level, deq;
  bool calculated;

  MaxFlowGraph() : INF(numeric_limits<Cap>::max()), N(0), calculated(0) {}

  void add(int frm, int to, Cap cap) {
    chmax(N, frm + 1);
    chmax(N, to + 1);
    edges.eb(Edge({frm, to, cap, int(edges.size())}));
  }

  void _build() {
    indptr.resize(N + 1);
    level.resize(N);
    deq.resize(N);
    int M = len(edges);
    for (auto&& e: edges) { indptr[e.frm + 1]++, indptr[e.to + 1]++; }
    FOR(v, N) indptr[v + 1] += indptr[v];
    auto counter = indptr;

    edge_flow.resize(M);
    csr_edges.resize(2 * M);
    rev.resize(2 * M);
    for (auto&& e: edges) {
      int i = counter[e.frm], j = counter[e.to];
      rev[i] = j, rev[j] = i;
      csr_edges[i] = {e.frm, e.to, e.cap, e.idx};
      csr_edges[j] = {e.to, e.frm, Cap(0), ~e.idx};
      counter[e.frm]++, counter[e.to]++;
    }
  }

  bool set_level(int source, int sink) {
    // bfs
    fill(all(level), -1);
    int l = 0, r = 0;
    deq[r++] = source;
    level[source] = 0;
    while (l < r) {
      int v = deq[l++];
      FOR3(i, indptr[v], indptr[v + 1]) {
        auto& e = csr_edges[i];
        if (e.cap == 0 || level[e.to] >= 0) continue;
        level[e.to] = level[v] + 1;
        if (e.to == sink) return true;
        deq[r++] = e.to;
      }
    }
    return false;
  }

  Cap flow_dfs(int v, int sink, Cap lim) {
    if (v == sink) return lim;
    FOR3(i, indptr[v], indptr[v + 1]) {
      auto& e = csr_edges[i];
      if (e.cap == 0 || level[v] >= level[e.to]) continue;
      Cap x = flow_dfs(e.to, sink, min(lim, e.cap));
      if (x > Cap(0)) {
        e.cap -= x;
        int j = rev[i];
        csr_edges[j].cap += x;
        if (e.idx >= 0)
          edge_flow[e.idx] += x;
        else
          edge_flow[~e.idx] -= x;
        return x;
      }
    }
    level[v] = -1;
    return 0;
  }

  Cap flow(int source, int sink) {
    assert(!calculated);
    calculated = true;
    _build();
    Cap f = 0;
    while (set_level(source, sink)) {
      while (1) {
        Cap x = flow_dfs(source, sink, INF);
        if (x == 0) break;
        f += x;
      }
    }
    return f;
  }

  vc<tuple<int, int, Cap>> get_edges() {
    vc<tuple<int, int, Cap>> res;
    for (auto&& e: edges) {
      Cap f = edge_flow[e.idx];
      if (f > Cap(0)) res.eb(e.frm, e.to, f);
    }
    return res;
  }

  void debug() {
    for (auto&& e: edges) print(e.frm, e.to, e.cap);
  }
};
