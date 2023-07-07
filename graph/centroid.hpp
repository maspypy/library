#include "graph/base.hpp"

// (v,w) or (v,-1)
template <typename GT>
pair<int, int> find_centroids(GT& G) {
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
  pair<int, int> ANS = {-1, -1};
  FOR(v, N) if (check(v)) {
    if (ANS.fi != -1) {
      ANS.se = v;
    } else {
      ANS.fi = v;
    }
  }
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
  // V, dat, grp
  template <typename T, typename F>
  tuple<vc<int>, vc<T>, vc<int>> collect_path_data(int root, T root_val, F f) {
    vc<int> V = {root};
    vc<T> dp = {root_val};
    vc<int> grp = {-1};
    int nxt_grp = 0;
    for (auto&& e: G[root]) {
      int nxt = e.to;
      if (cdep[nxt] < cdep[root]) continue;
      int p = len(V);
      V.eb(nxt);
      dp.eb(f(root_val, e));
      grp.eb(nxt_grp);
      par[nxt] = root;
      while (p < len(V)) {
        int v = V[p];
        T val = dp[p];
        p++;
        for (auto&& e: G[v]) {
          if (e.to == par[v]) continue;
          if (cdep[e.to] < cdep[root]) continue;
          par[e.to] = v;
          V.eb(e.to);
          grp.eb(nxt_grp);
          dp.eb(f(val, e));
        }
      }
      ++nxt_grp;
    }
    return {V, dp, grp};
  }

  // V, dist, grp
  tuple<vc<int>, vc<int>, vc<int>> collect_dist(int root) {
    auto f = [&](int x, auto e) -> int { return x + 1; };
    return collect_path_data(root, 0, f);
  }

  // (V, H, grp), (V[i] in G) = (i in H).
  // 0,1,2... is a dfs order in H.
  tuple<vc<int>, Graph<typename GT::cost_type, true>, vc<int>> get_subgraph(
      int root) {
    static vc<int> conv;
    while (len(conv) < N) conv.eb(-1);

    vc<int> V = {root};
    vc<int> grp = {-1};
    conv[root] = 0;
    int nxt_grp = 0;
    using cost_type = typename GT::cost_type;
    vc<tuple<int, int, cost_type>> edges;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
      conv[v] = len(V);
      V.eb(v), grp.eb(nxt_grp);
      for (auto&& e: G[v]) {
        int to = e.to;
        if (to == p) continue;
        if (cdep[to] < cdep[root]) continue;
        dfs(dfs, to, v);
        edges.eb(conv[v], conv[to], e.cost);
      }
    };
    for (auto&& e: G[root]) {
      if (cdep[e.to] < cdep[root]) continue;
      dfs(dfs, e.to, root);
      edges.eb(conv[root], conv[e.to], e.cost);
      ++nxt_grp;
    }
    int n = len(V);
    Graph<typename GT::cost_type, true> H(n);
    for (auto&& [a, b, c]: edges) H.add(a, b, c);
    H.build();
    for (auto&& v: V) conv[v] = -1;
    return {V, H, grp};
  }
};
