// Source: https://github.com/maspypy/library/blob/main/flow/convex_min_cost_flow.hpp

/*
・各辺の費用は flow x に対して f(x) とする．f(0)=0 下凸．
・DAG = true なら負の増分費用を許し，頂点番号は topological order．
*/
template <class Cap = int, class Cost = ll, bool DAG = false>
struct Convex_Min_Cost_Flow {
 public:
  Convex_Min_Cost_Flow() {}
  explicit Convex_Min_Cost_Flow(int n, int source, int sink)
      : n(n), source(source), sink(sink), adj(n) {
    assert(0 <= source && source < n);
    assert(0 <= sink && sink < n);
    assert(source != sink);
  }

  struct edge {
    int frm, to;
    Cap cap, flow;
  };

 private:
  struct block {
    Cap end;
    Cost cost;
  };
  struct edge_data {
    edge e;
    vector<block> blocks;
    int block_idx;
  };

 public:
  int add(int frm, int to, Cap cap, Cost cost) {
    vector<block> blocks;
    if (cap) blocks.push_back({cap, cost});
    return add_blocks(frm, to, cap, std::move(blocks));
  }

  template <class F>
  int add_convex(int frm, int to, Cap cap, F&& f) {
    assert(0 <= cap);
    Cost prev = f(Cap(0));
    assert(prev == Cost(0));
    vector<block> blocks;
    for (Cap x = 0; x < cap;) {
      ++x;
      Cost now = f(x);
      Cost cost = now - prev;
      assert(DAG || Cost(0) <= cost);
      if (!blocks.empty()) assert(blocks.back().cost <= cost);
      if (!blocks.empty() && blocks.back().cost == cost)
        ++blocks.back().end;
      else
        blocks.push_back({1, cost});
      prev = now;
    }
    return add_blocks(frm, to, cap, std::move(blocks));
  }

  edge get_edge(int i) const {
    assert(0 <= i && i < int(_edges.size()));
    return _edges[i].e;
  }
  vector<edge> edges() const {
    vector<edge> res;
    res.reserve(_edges.size());
    for (auto&& x : _edges) res.push_back(x.e);
    return res;
  }

  pair<Cap, Cost> flow() { return flow(infty<Cap>); }
  pair<Cap, Cost> flow(Cap flow_limit) { return slope(flow_limit).back(); }
  vector<pair<Cap, Cost>> slope() { return slope(infty<Cap>); }
  vector<pair<Cap, Cost>> slope(Cap flow_limit) {
    assert(!solved);
    assert(0 <= flow_limit);
    solved = true;
    return run_slope(flow_limit);
  }

  vvc<int> path_decomposition() const {
    vvc<int> TO(n);
    for (auto&& e : edges()) FOR(e.flow) TO[e.frm].eb(e.to);
    vvc<int> res;
    vc<int> vis(n);
    while (!TO[source].empty()) {
      vc<int> path = {source};
      vis[source] = 1;
      while (path.back() != sink) {
        int to = POP(TO[path.back()]);
        while (vis[to]) vis[POP(path)] = 0;
        path.eb(to), vis[to] = 1;
      }
      for (auto&& v : path) vis[v] = 0;
      res.eb(path);
    }
    return res;
  }

  vc<Cost> get_potentials() const { return potential; }

 private:
  int n, source, sink;
  vector<edge_data> _edges;
  vector<vector<pair<int, int>>> adj;
  bool solved = false;
  vc<Cost> potential;

  int add_blocks(int frm, int to, Cap cap, vector<block>&& blocks) {
    assert(!solved);
    assert(0 <= frm && frm < n);
    assert(0 <= to && to < n);
    assert(0 <= cap);
    if (DAG) assert(frm < to);
    Cap end = 0;
    for (auto&& b : blocks) {
      assert(DAG || Cost(0) <= b.cost);
      end += b.end;
      b.end = end;
    }
    assert(end == cap);
    int id = int(_edges.size());
    _edges.push_back({{frm, to, cap, 0}, std::move(blocks), 0});
    adj[frm].push_back({id, +1});
    adj[to].push_back({id, -1});
    return id;
  }

  bool residual(int id, int dir, Cap& cap, Cost& cost) const {
    auto&& data = _edges[id];
    auto&& e = data.e;
    if (dir == +1) {
      if (e.flow == e.cap) return false;
      auto&& b = data.blocks[data.block_idx];
      cap = b.end - e.flow;
      cost = b.cost;
      return true;
    }
    if (e.flow == 0) return false;
    int i = data.block_idx;
    if (i == int(data.blocks.size()) || (i && e.flow == data.blocks[i - 1].end))
      --i;
    auto&& b = data.blocks[i];
    Cap begin = (i ? data.blocks[i - 1].end : 0);
    cap = e.flow - begin;
    cost = -b.cost;
    return true;
  }

  void push(int id, int dir, Cap amount) {
    auto&& data = _edges[id];
    if (dir == +1)
      data.e.flow += amount;
    else
      data.e.flow -= amount;
    while (data.block_idx < int(data.blocks.size()) &&
           data.e.flow >= data.blocks[data.block_idx].end)
      ++data.block_idx;
    while (data.block_idx && data.e.flow < data.blocks[data.block_idx - 1].end)
      --data.block_idx;
  }

  vector<pair<Cap, Cost>> run_slope(Cap flow_limit) {
    if (DAG) assert(source == 0 && sink == n - 1);
    vector<pair<Cost, Cost>> dual_dist(n);
    vector<pair<int, int>> parent(n);
    vector<bool> vis(n);
    struct Q {
      Cost key;
      int to;
      bool operator<(Q r) const { return key > r.key; }
    };
    vector<int> que_min;
    vector<Q> que;
    auto dual_ref = [&]() {
      FOR(v, n) dual_dist[v].second = infty<Cost>;
      fill(vis.begin(), vis.end(), false);
      que_min.clear(), que.clear();
      size_t heap_r = 0;
      dual_dist[source].second = 0;
      que_min.push_back(source);
      while (!que_min.empty() || !que.empty()) {
        int v;
        if (!que_min.empty())
          v = POP(que_min);
        else {
          while (heap_r < que.size())
            push_heap(que.begin(), que.begin() + ++heap_r);
          v = que.front().to;
          pop_heap(que.begin(), que.end());
          que.pop_back();
          --heap_r;
        }
        if (vis[v]) continue;
        vis[v] = true;
        if (v == sink) break;
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (auto&& [id, dir] : adj[v]) {
          Cap cap;
          Cost edge_cost;
          if (!residual(id, dir, cap, edge_cost)) continue;
          auto&& e = _edges[id].e;
          int to = (dir == +1 ? e.to : e.frm);
          Cost cost = edge_cost - dual_dist[to].first + dual_v;
          if (dual_dist[to].second <= dist_v + cost) continue;
          Cost dist_to = dist_v + cost;
          dual_dist[to].second = dist_to;
          parent[to] = {id, dir};
          if (dist_to == dist_v)
            que_min.push_back(to);
          else
            que.push_back({dist_to, to});
        }
      }
      if (!vis[sink]) return false;
      FOR(v, n)
      if (vis[v])
        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;
      return true;
    };
    auto dual_ref_dag = [&]() {
      FOR(v, n) dual_dist[v].second = infty<Cost>;
      dual_dist[source].second = 0;
      fill(vis.begin(), vis.end(), false);
      vis[0] = true;
      FOR(v, n) {
        if (!vis[v]) continue;
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (auto&& [id, dir] : adj[v]) {
          Cap cap;
          Cost edge_cost;
          if (!residual(id, dir, cap, edge_cost)) continue;
          auto&& e = _edges[id].e;
          int to = (dir == +1 ? e.to : e.frm);
          Cost cost = edge_cost - dual_dist[to].first + dual_v;
          if (dual_dist[to].second > dist_v + cost) {
            vis[to] = true;
            dual_dist[to].second = dist_v + cost;
            parent[to] = {id, dir};
          }
        }
      }
      if (!vis[sink]) return false;
      FOR(v, n)
      if (vis[v])
        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;
      return true;
    };

    Cap flow = 0;
    Cost cost = 0, prev_cost_per_flow = 0;
    bool has_prev_cost = false;
    vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
    while (flow < flow_limit) {
      if (DAG && flow == 0 ? !dual_ref_dag() : !dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = sink; v != source;) {
        auto [id, dir] = parent[v];
        Cap cap;
        Cost edge_cost;
        bool ok = residual(id, dir, cap, edge_cost);
        assert(ok);
        chmin(c, cap);
        v = (dir == +1 ? _edges[id].e.frm : _edges[id].e.to);
      }
      for (int v = sink; v != source;) {
        auto [id, dir] = parent[v];
        int prv = (dir == +1 ? _edges[id].e.frm : _edges[id].e.to);
        push(id, dir, c);
        v = prv;
      }
      Cost d = -dual_dist[source].first;
      flow += c;
      cost += c * d;
      if (has_prev_cost && prev_cost_per_flow == d) result.pop_back();
      result.push_back({flow, cost});
      prev_cost_per_flow = d;
      has_prev_cost = true;
    }
    dual_ref();
    potential.resize(n);
    FOR(v, n) potential[v] = dual_dist[v].first;
    return result;
  }
};
