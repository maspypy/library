#include "graph/base.hpp"

template <typename GT>
vc<int> find_centroids(GT& G) {
  int N = G.N;
  vc<int> par(N, -1);
  vc<int> V(N);
  vc<int> sz(N);
  int l = 0, r = 0;
  V[r++] = 0;
  while (l < r) {
    int v = V[l++];
    for (auto&& e: G[v])
      if (e.to != par[v]) {
        par[e.to] = v;
        V[r++] = e.to;
      }
  }
  FOR_R(i, N) {
    int v = V[i];
    sz[v] += 1;
    int p = par[v];
    if (p != -1) sz[p] += sz[v];
  }

  int M = N / 2;
  auto check = [&](int v) -> bool {
    if (N - sz[v] > M) return false;
    for (auto&& e: G[v]) {
      if (e.to != par[v] && sz[e.to] > M) return false;
    }
    return true;
  };
  vc<int> ANS;
  FOR(v, N) if (check(v)) ANS.eb(v);
  return ANS;
}

template <typename GT>
struct Centroid_Decomposition {
  using edge_type = typename GT::edge_type;
  GT& G;
  int N;
  vc<int> sz;
  vc<int> par;
  vector<int> cdep; // depth in centroid tree
  bool calculated;

  Centroid_Decomposition(GT& G)
      : G(G), N(G.N), sz(G.N), par(G.N), cdep(G.N, -1) {
    calculated = 0;
    build();
  }

private:
  int find(int v) {
    vc<int> V = {v};
    par[v] = -1;
    int p = 0;
    while (p < len(V)) {
      int v = V[p++];
      sz[v] = 0;
      for (auto&& e: G[v]) {
        if (e.to == par[v] || cdep[e.to] != -1) continue;
        par[e.to] = v;
        V.eb(e.to);
      }
    }
    while (len(V)) {
      int v = V.back();
      V.pop_back();
      sz[v] += 1;
      if (p - sz[v] <= p / 2) return v;
      sz[par[v]] += sz[v];
    }
    return -1;
  }
  void build() {
    assert(G.is_prepared());
    assert(!G.is_directed());
    assert(!calculated);
    calculated = 1;

    vc<pair<int, int>> st;
    st.eb(0, 0);
    while (!st.empty()) {
      auto [lv, v] = st.back();
      st.pop_back();
      auto c = find(v);
      cdep[c] = lv;
      for (auto&& e: G[c]) {
        if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }
      }
    }
  }

public:
  /*
  root を重心とする木において、(v, path data v) の vector
  を、方向ごとに集めて返す ・0 番目：root からのパスすべて（root を含む）
  ・i番目：i 番目の方向
  f: E x edge -> E
  */
  template <typename E, typename F>
  vc<vc<pair<int, E>>> collect(int root, E root_val, F f) {
    vc<vc<pair<int, E>>> res = {{{root, root_val}}};
    for (auto&& e: G[root]) {
      int nxt = e.to;
      if (cdep[nxt] < cdep[root]) continue;
      vc<pair<int, E>> dat;
      int p = 0;
      dat.eb(nxt, f(root_val, e));
      par[nxt] = root;
      while (p < len(dat)) {
        auto [v, val] = dat[p++];
        for (auto&& e: G[v]) {
          if (e.to == par[v]) continue;
          if (cdep[e.to] < cdep[root]) continue;
          par[e.to] = v;
          dat.eb(e.to, f(val, e));
        }
      }
      res.eb(dat);
      res[0].insert(res[0].end(), all(dat));
    }
    return res;
  }

  vc<vc<pair<int, int>>> collect_dist(int root) {
    auto f = [&](int x, auto e) -> int { return x + 1; };
    return collect(root, 0, f);
  }

  // (V, H), V[i] は、H における頂点 i の G における番号
  // 頂点は EulerTour 順に並ぶ
  pair<vc<int>, Graph<typename GT::cost_type, true>> get_subgraph(int root) {
    static vc<int> conv;
    while (len(conv) < N) conv.eb(-1);

    vc<int> V;
    using cost_type = typename GT::cost_type;
    vc<tuple<int, int, cost_type>> edges;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
      conv[v] = len(V);
      V.eb(v);
      for (auto&& e: G[v]) {
        int to = e.to;
        if (to == p) continue;
        if (cdep[to] < cdep[root]) continue;
        dfs(dfs, to, v);
        edges.eb(conv[v], conv[to], e.cost);
      }
    };
    dfs(dfs, root, -1);
    int n = len(V);
    Graph<typename GT::cost_type, true> H(n);
    for (auto&& [a, b, c]: edges) H.add(a, b, c);
    H.build();
    for (auto&& v: V) conv[v] = -1;
    return {V, H};
  }
};
