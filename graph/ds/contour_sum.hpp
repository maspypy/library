#include "ds/fenwicktree/fenwicktree.hpp"

// 点加算、距離区間での和
template <typename GT, typename AbelGroup>
struct Contour_Sum {
  int N;
  GT& G;
  using X = typename AbelGroup::value_type;
  FenwickTree<AbelGroup> bit;
  // centroid ごと、方向ごと
  vvc<int> bit_range;
  // 方向ラベル、重心からの距離、bit でのindex
  vvc<tuple<int, int, int>> dat;

  Contour_Sum(GT& G) : N(G.N), G(G) {
    assert(!G.is_directed());
    vc<X> v_vals(N, AbelGroup::unit());
    build(v_vals);
  }
  Contour_Sum(GT& G, const vc<X>& v_vals) : N(G.N), G(G) {
    assert(!G.is_directed());
    build(v_vals);
  }

  void add(int v, X val) {
    for (auto&& [k, x, i]: dat[v]) bit.add(i, val);
  }

  // v を中心として、距離 [l, r) の範囲の和
  X sum(int v, int l, int r) {
    X sm = AbelGroup::unit();
    for (auto [k, x, i]: dat[v]) {
      int lo = l - x, hi = r - x;
      int K = k;
      if (k < 0) { lo -= 2, hi -= 2, K = ~k; }
      int n = len(bit_range[K]) - 2;
      chmax(lo, 0);
      chmin(hi, n + 1);
      if (lo >= hi) continue;
      int a = bit_range[K][lo], b = bit_range[K][hi];
      X val = bit.prod(a, b);
      if (k < 0) { val = AbelGroup::inverse(val); }
      sm = AbelGroup::op(sm, val);
    }
    return sm;
  }

  void build(const vc<X>& v_vals) {
    int nxt_bit_idx = 0;
    vc<int> done(N, 0);
    vc<int> sz(N, 0);
    vc<int> par(N, -1);
    vc<int> dist(N, -1);
    vc<pair<int, int>> st;
    bit_range.resize(N);
    dat.resize(N);
    st.eb(0, N);

    while (len(st)) {
      int v0 = st.back().fi;
      int n = st.back().se;
      st.pop_back();
      int c = -1;
      {
        auto dfs = [&](auto& dfs, int v) -> int {
          sz[v] = 1;
          for (auto&& e: G[v])
            if (e.to != par[v] && !done[e.to]) {
              par[e.to] = v;
              sz[v] += dfs(dfs, e.to);
            }
          if (c == -1 && n - sz[v] <= n / 2) { c = v; }
          return sz[v];
        };
        dfs(dfs, v0);
      }
      // center からの bfs。部分木サイズもとっておく。
      done[c] = 1;
      {
        int off = nxt_bit_idx;
        vc<int> que;
        auto add = [&](int v, int d, int p) -> void {
          if (dist[v] != -1) return;
          sz[v] = 1;
          dist[v] = d;
          par[v] = p;
          que.eb(v);
        };
        int p = 0;
        add(c, 0, -1);
        while (p < len(que)) {
          auto v = que[p++];
          for (auto&& e: G[v]) {
            if (done[e.to]) continue;
            add(e.to, dist[v] + 1, v);
          }
        }
        FOR_R(i, 1, len(que)) {
          int v = que[i];
          sz[par[v]] += sz[v];
        }
        // 距離ごとのカウント
        int max_d = dist[que.back()];
        vc<int> count(max_d + 1);
        // 重心、方向ラベル、重心からの距離、bit でのindex
        for (auto&& v: que) {
          dat[v].eb(c, dist[v], nxt_bit_idx++);
          count[dist[v]]++;
          par[v] = -1;
          dist[v] = -1;
        }
        bit_range[c] = cumsum<int, int>(count);
        for (auto&& x: bit_range[c]) x += off;
      }
      // 方向ごとの bfs
      for (auto&& e: G[c]) {
        int off = nxt_bit_idx;
        int nbd = e.to;
        if (done[nbd]) continue;
        int K = len(bit_range);
        vc<int> que;
        auto add = [&](int v, int d) -> void {
          if (dist[v] != -1 || v == c) return;
          dist[v] = d;
          que.eb(v);
        };
        int p = 0;
        add(nbd, 0);
        while (p < len(que)) {
          auto v = que[p++];
          for (auto&& e: G[v]) {
            if (done[e.to]) continue;
            add(e.to, dist[v] + 1);
          }
        }
        // 距離ごとのカウント
        int max_d = dist[que.back()];
        vc<int> count(max_d + 1);
        // 重心、方向ラベル、重心からの距離、bit でのindex
        for (auto&& v: que) {
          dat[v].eb(~K, dist[v], nxt_bit_idx++);
          count[dist[v]]++;
          par[v] = -1;
          dist[v] = -1;
        }
        bit_range.eb(cumsum<int>(count));
        for (auto&& x: bit_range[K]) x += off;
        st.eb(nbd, sz[nbd]);
      }
    }
    // FenwickTree
    vc<X> bit_raw(nxt_bit_idx);
    FOR(v, N) {
      for (auto&& [k, x, i]: dat[v]) { bit_raw[i] = v_vals[v]; }
    }
    bit.build(bit_raw);
  }
};
