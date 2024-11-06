#include "flow/mincostflow.hpp"
#include "graph/shortest_path/dijkstra.hpp"

/*
potential p[v]
距離を L 以上にしたい : L<=p[t]-p[s]
辺 (u,v,w)
伸ばす量 max(0,p[v]-p[u]-w)
- t から s に費用-L, 容量INF
- u から v に費用 w, 容量 1
これの循環流
*/

// https://qoj.ac/contest/1435/problem/7737
template <typename T = ll, bool DAG = false>
struct Longest_Shortest_Path {
  int N, s, t;
  T F, L, K;
  bool solved;
  vc<tuple<int, int, T, T>> dat;
  vc<T> pot;
  Longest_Shortest_Path(int N, int s, int t) : N(N), s(s), t(t), F(0), solved(0) {}

  // 現在の長さ, 長さを+1するコスト
  void add(int frm, int to, T length, T cost) {
    assert(0 <= frm && frm < N && 0 <= to && to < N && !solved);
    if (DAG) assert(frm < to);
    dat.eb(frm, to, length, cost);
  }

  T init_dist() {
    Graph<T, 1> G(N);
    for (auto& [a, b, c, d]: dat) G.add(a, b, c);
    G.build();
    auto [dist, par] = dijkstra<T>(G, s);
    return dist[t];
  }

  // 距離が L 以上になるようにせよ. return: min cost.
  T solve_by_target_length(T target_length) {
    L = target_length;
    assert(!solved && L >= init_dist());
    solved = 1;
    Min_Cost_Flow<T, T, DAG> G(N, s, t);
    for (auto& [a, b, length, cost]: dat) { G.add(a, b, cost, length); }
    T ans = -infty<T>;
    for (auto& [x, y]: G.slope()) {
      if (chmax(ans, x * L - y)) F = x;
    }
    return K = ans;
  }

  // コストが K で最大距離にせよ. return: max dist.
  T solve_by_cost(T K) {}

  // frm, to, cost. add_edge 順.
  vc<T> get_potentials() {
    assert(solved);
    if (len(pot)) return pot;
    Min_Cost_Flow<T, T, DAG> G(N, s, t);
    for (auto& [a, b, length, cost]: dat) { G.add(a, b, cost, length); }
    G.flow(F);
    pot = G.get_potentials();
    Graph<T, 1> resG(N);
    auto add = [&](int a, int b, T x) -> void {
      x = x + pot[a] - pot[b];
      resG.add(a, b, x);
    };
    for (auto& e: G.edges()) {
      if (e.cap > e.flow) add(e.frm, e.to, e.cost);
      if (e.flow > 0) add(e.to, e.frm, -e.cost);
    }
    add(s, t, L), add(t, s, -L);
    resG.build();
    vc<T> dist = dijkstra<ll>(resG, s).fi;
    FOR(x, N) pot[x] += dist[x];
    return pot;
  }

  // 変更後の長さ
  vc<T> get_edges() {
    get_potentials();
    vc<T> res;
    for (auto [frm, to, length, cost]: dat) { res.eb(max<T>(length, pot[to] - pot[frm])); }
    return res;
  }
};
