template <typename Cap, typename Cost>
struct MinCostFlow {
 protected:
  using P = pair<Cost, int>;
  struct edge {
    int to;
    Cap cap;
    Cost cost;
    int rev;
    bool isrev;
  };
  vector<Cost> h;
  vector<Cost> dist;
  vector<int> prevv, preve;
  bool negative;

 public:
  int V;
  vector<vector<edge>> G;
  Cost INF = numeric_limits<Cost>::max();
  MinCostFlow() {}
  MinCostFlow(int v) : h(v), dist(v), prevv(v), preve(v), negative(false), V(v), G(v) {}
  void add(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < V);
    assert(0 <= to && to < V);
    assert(0 <= cap);
    if (cap == 0) return;
    if (cost < 0) negative = true;
    G[from].push_back({to, cap, cost, (int)G[to].size(), false});
    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1, true});
  }
  Cost min_cost_flow(int s, int t, Cap f, bool DAG = false) {
    assert(0 <= s && s < V);
    assert(0 <= t && t < V);
    assert(s != t);
    assert(0 < f);
    Cost res = 0;
    fill(h.begin(), h.end(), 0);
    auto dijkstra = [&]() {
      priority_queue<P, vector<P>, greater<P>> pq;
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      pq.push(P(0, s));
      while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
          edge& e = G[v][i];
          if (e.cap <= 0 || dist[e.to] <= dist[v] + e.cost + h[v] - h[e.to]) continue;
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          pq.push(P(dist[e.to], e.to));
        }
      }
    };

    if (DAG) {
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      vector<int> deg_in(V);
      for (int i = 0; i < V; i++) {
        for (const auto& e : G[i]) deg_in[e.to] += (e.cap > 0);
      }
      vector<int> st;
      for (int i = 0; i < V; i++)
        if (!deg_in[i]) st.push_back(i);
      for (int n = 0; n < V; n++) {
        if (int(st.size()) == n) assert(false);
        int now = st[n];
        for (int i = 0; i < (int)G[now].size(); i++) {
          edge& e = G[now][i];
          if (e.isrev) continue;
          deg_in[e.to]--;
          if (deg_in[e.to] == 0) st.push_back(e.to);
          if (e.cap <= 0 || dist[now] == INF || dist[e.to] <= dist[now] + e.cost) continue;
          dist[e.to] = dist[now] + e.cost;
          prevv[e.to] = now;
          preve[e.to] = i;
        }
      }
    } else if (!negative)
      dijkstra();
    else {
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
          for (int i = 0; i < (int)G[v].size(); i++) {
            edge& e = G[v][i];
            if (e.cap <= 0 || dist[v] == INF || dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            if (u == V - 1) assert(false);
          }
        }
      }
    }
    while (true) {
      if (dist[t] == INF) return INF;
      for (int v = 0; v < V; v++) h[v] += dist[v];

      Cap d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge& e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
      if (f == 0) break;
      dijkstra();
    }
    return res;
  }
};
