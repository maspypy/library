/*
左側に K 頂点、右側に N 頂点、流量 N の二部最小費用流を
O((K^2logN+K^3)N) で解く
https://ac.nowcoder.com/acm/contest/33188/B
*/
template <typename T>
struct Unbalanced_Transportation_Problem {
  int K, N;
  vc<int> supply;
  vvc<T> cost;
  vc<int> FRM;
  Unbalanced_Transportation_Problem(int K, int N, vc<int>& supply)
      : K(K), N(N), supply(supply) {
    assert(SUM(supply) == N);
    cost.assign(K, vc<T>(N, infty<T>));
    FRM.assign(N, -1);
  }

  void add(int a, int b, T c) {
    assert(0 <= a && a < K);
    assert(0 <= b && b < N);
    cost[a][b] = c;
  }

  // 流量 -> 費用
  vc<T> calc() {
    using Q = pqg<pair<T, int>>;
    vc<T> res = {0};
    T MCF = 0;
    vv(Q, edge, K, K);
    vc<Q> unused(K);
    FOR(a, K) FOR(b, N) {
      T c = cost[a][b];
      if (c == infty<T>) continue;
      unused[a].emplace(c, b);
    }
    while (1) {
      // update prique
      FOR(a, K) {
        auto& que = unused[a];
        while (len(que)) {
          auto [x, b] = que.top();
          if (FRM[b] == -1) break;
          que.pop();
        }
      }
      FOR(a, K) FOR(b, K) {
        auto& que = edge[a][b];
        while (len(que)) {
          auto [x, c] = que.top();
          if (FRM[c] == b) { break; }
          que.pop();
        }
      }

      // グラフを作る
      vv(T, dist_0, K, K, infty<T>);
      FOR(a, K) FOR(b, K) {
        if (len(edge[a][b]) == 0) continue;
        auto [c, idx] = edge[a][b].top();
        dist_0[a][b] = c;
      }
      // source からの最短路
      vc<T> dist(K, infty<T>);
      vc<bool> in_que(K);
      queue<int> que;
      vc<int> par(K, -1);
      FOR(k, K) {
        if (supply[k]) { dist[k] = 0, in_que[k] = 1, que.emplace(k); }
      }
      while (!que.empty()) {
        int v = que.front();
        que.pop(), in_que[v] = 0;
        FOR(to, K) {
          if (dist_0[v][to] == infty<T>) continue;
          if (chmin(dist[to], dist[v] + dist_0[v][to])) {
            par[to] = v;
            if (!in_que[to]) {
              in_que[to] = 1;
              que.emplace(to);
            }
          }
        }
      }
      int best = -1;
      T best_c = infty<T>;
      FOR(k, K) {
        if (dist[k] == infty<T>) continue;
        T x = dist[k] + unused[k].top().fi;
        if (chmin(best_c, x)) best = k;
      }
      if (best == -1) break;
      auto match = [&](int a, int b) -> void {
        int c = FRM[b];
        if (c != -1) MCF -= cost[c][b];
        FRM[b] = a;
        MCF += cost[a][b];
        FOR(v, K) {
          if (v == a || cost[v][b] == infty<T>) continue;
          edge[v][a].emplace(cost[v][b] - cost[a][b], b);
        }
      };

      int v = best;
      match(v, unused[v].top().se);
      while (par[v] != -1) {
        match(par[v], edge[par[v]][v].top().se);
        v = par[v];
      }
      supply[v]--;
      res.eb(MCF);
    }
    return res;
  }
};