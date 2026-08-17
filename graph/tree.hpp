
#include "graph/base.hpp"

// HLD euler tour をとっていろいろ
// HLD=false: 入力辺順で preorder
template <typename GT, bool HLD = true>
struct Tree {
  using Graph_type = GT;
  GT &G;
  using WT = typename GT::cost_type;
  int N;
  vector<int> LID, RID, head, V, parent, VtoE;
  vc<int> depth;
  vc<WT> depth_weighted;
  vc<int> memo_tail;

  Tree(GT &G, int r = 0) : G(G) { build(r); }

  void build(int r = 0) {
    if (r == -1) return;  // build を遅延したいとき
    if constexpr (!HLD)
      build_simple(r);
    else
      build_HLD(r);
  }

  vc<int> heavy_path_at(int v) {
    static_assert(HLD);
    assert(head[v] == v);
    int k = LID[v];
    vc<int> P;
    while (k < N && head[V[k]] == v) P.eb(V[k++]);
    return P;
  }

  int heavy_child(int v) {
    static_assert(HLD);
    if (RID[v] == LID[v] + 1) return -1;
    return V[LID[v] + 1];
  }

  int tail(int v) {
    static_assert(HLD);
    if (memo_tail.empty()) {
      memo_tail.assign(N, -1);
      FOR_R(i, N) {
        int v = V[i];
        int w = heavy_child(v);
        memo_tail[v] = (w == -1 ? v : memo_tail[w]);
      }
    }
    return memo_tail[v];
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
  }
  int v_to_e(int v) { return VtoE[v]; }
  int get_eid(int u, int v) {
    if (parent[u] != v) swap(u, v);
    assert(parent[u] == v);
    return VtoE[u];
  }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  // 目標地点へ進む個数が k
  int LA(int v, int k) {
    static_assert(HLD);
    assert(k <= depth[v]);
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int LCA(int u, int v) {
    static_assert(HLD);
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  int meet(int a, int b, int c) {
    static_assert(HLD);
    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);
  }

  int subtree_size(int v) { return RID[v] - LID[v]; }

  int subtree_size(int v, int root) {
    static_assert(HLD);
    if (v == root) return N;
    int x = jump(v, root, 1);
    if (in_subtree(v, x)) return RID[v] - LID[v];
    return N - RID[x] + LID[x];
  }

  int dist(int a, int b) {
    static_assert(HLD);
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  WT dist_weighted(int a, int b) {
    static_assert(HLD);
    int c = LCA(a, b);
    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];
  }

  // a is in b
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int jump(int a, int b, ll k) {
    static_assert(HLD);
    if (k == 1) {
      if (a == b) return -1;
      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
    }
    int c = LCA(a, b);
    int d_ac = depth[a] - depth[c];
    int d_bc = depth[b] - depth[c];
    if (k > d_ac + d_bc) return -1;
    if (k <= d_ac) return LA(a, k);
    return LA(b, d_ac + d_bc - k);
  }

  vc<int> collect_child(int v) {
    vc<int> res;
    for (auto &&e : G[v])
      if (e.to != parent[v]) res.eb(e.to);
    return res;
  }

  vc<int> collect_subtree(int v) {
    return {V.begin() + LID[v], V.begin() + RID[v]};
  }

  vc<int> collect_light(int v) {
    static_assert(HLD);
    vc<int> res;
    for (auto &&e : G[v]) {
      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);
    }
    return res;
  }

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    static_assert(HLD);
    // [始点, 終点] の"閉"区間列。
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
  }

  // 辺の列の情報 (frm,to,str)
  // str = "heavy_up", "heavy_down", "light_up", "light_down"
  vc<tuple<int, int, string>> get_path_decomposition_detail(int u, int v) {
    static_assert(HLD);
    vc<tuple<int, int, string>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        if (v != head[v]) down.eb(head[v], v, "heavy_down"), v = head[v];
        down.eb(parent[v], v, "light_down"), v = parent[v];
      } else {
        if (u != head[u]) up.eb(u, head[u], "heavy_up"), u = head[u];
        up.eb(u, parent[u], "light_up"), u = parent[u];
      }
    }
    if (LID[u] < LID[v]) down.eb(u, v, "heavy_down");
    elif (LID[v] < LID[u]) up.eb(u, v, "heavy_up");
    reverse(all(down));
    concat(up, down);
    return up;
  }

  vc<int> restore_path(int u, int v) {
    vc<int> L, R;
    while (depth[u] > depth[v]) L.eb(u), u = parent[u];
    while (depth[u] < depth[v]) R.eb(v), v = parent[v];
    while (u != v) L.eb(u), R.eb(v), u = parent[u], v = parent[v];
    L.eb(u);
    while (len(R)) L.eb(POP(R));
    return L;
  }

  // path [a,b] と [c,d] の交わり. 空ならば {-1,-1}.
  // https://codeforces.com/problemset/problem/500/G
  pair<int, int> path_intersection(int a, int b, int c, int d) {
    static_assert(HLD);
    int ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);
    int bc = lca(b, c), bd = lca(b, d), cd = lca(c, d);
    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;  // meet(a,b,c), meet(a,b,d)
    if (x != y) return {x, y};
    int z = ac ^ ad ^ cd;
    if (x != z) x = -1;
    return {x, x};
  }

  // uv path 上で check(v) を満たす最後の v
  // なければ （つまり check(v) が ng ）-1
  template <class F>
  int max_path(F check, int u, int v) {
    static_assert(HLD);
    if (!check(u)) return -1;
    auto pd = get_path_decomposition(u, v, false);
    for (auto [a, b] : pd) {
      if (!check(V[a])) return u;
      if (check(V[b])) {
        u = V[b];
        continue;
      }
      int c =
          binary_search([&](int c) -> bool { return check(V[c]); }, a, b, 0);
      return V[c];
    }
    return u;
  }

 private:
  void build_simple(int r = 0) {
    N = G.N;
    LID.assign(N, 0), RID.assign(N, 0);
    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);
    depth.assign(N, 0), depth_weighted.assign(N, 0);
    assert(G.is_prepared());

    // 1st dfs.
    int k = 0;
    vc<int> st;
    st.reserve(N);
    st.eb(r);
    while (len(st)) {
      int v = POP(st);
      LID[v] = k, V[k] = v;
      ++k;
      for (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {
        auto &e = G.csr_edges[i];
        if (e.to == parent[v]) continue;
        parent[e.to] = v;
        depth[e.to] = depth[v] + 1;
        depth_weighted[e.to] = depth_weighted[v] + e.cost;
        VtoE[e.to] = e.id;
        st.eb(e.to);
      }
    }

    FOR_R(i, N) {
      int v = V[i];
      chmax(RID[v], LID[v] + 1);
      if (parent[v] != -1) chmax(RID[parent[v]], RID[v]);
    }
  }

  void build_HLD(int r = 0) {
    N = G.N;
    LID.assign(N, 0), RID.assign(N, 0), head.assign(N, r);
    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);
    depth.assign(N, 0), depth_weighted.assign(N, 0);
    memo_tail.clear();
    assert(G.is_prepared());

    // 1st dfs.
    {
      int k = 0;
      vc<int> st;
      st.reserve(N);
      st.eb(r);
      while (len(st)) {
        int v = POP(st);
        V[k++] = v;
        for (auto &e : G[v]) {
          if (e.to == parent[v]) continue;
          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;
          depth_weighted[e.to] = depth_weighted[v] + e.cost;
          VtoE[e.to] = e.id;
        }
      }
      // 一時的に RID[v] := sz[v]
      FOR_R(i, N) {
        int v = V[i];
        RID[v] += 1;
        if (parent[v] != -1) RID[parent[v]] += RID[v];
      }
    }
    // 2nd dfs.
    {
      int k = 0;
      vc<int> st;
      st.reserve(N);
      st.eb(r);
      while (len(st)) {
        int v = POP(st);
        V[k] = v, LID[v] = k;
        RID[v] = k + RID[v];
        ++k;
        int max_sz = 0, max_ch = -1;
        for (auto &e : G[v]) {
          if (e.to == parent[v]) continue;
          if (chmax(max_sz, RID[e.to])) max_ch = e.to;
        }
        for (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {
          auto &e = G.csr_edges[i];
          if (e.to == parent[v] || e.to == max_ch) continue;
          st.eb(e.to), head[e.to] = e.to;
        }
        if (max_ch != -1) st.eb(max_ch), head[max_ch] = head[v];
      }
    }
  }
};
