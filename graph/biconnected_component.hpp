#include "graph/base.hpp"

/*
孤立点は、辺のない component で、block になる。関節点ではない。
block cut treeの頂点番号：
[0, n_block)：block
[n_block, n_block + n_cut)：cut （関節点）
*/
template <typename GT>
struct Biconnected_Component {
  GT& G;
  vc<pair<int, int>> BCT_edges;
  int n_block, n_cut;
  vc<vc<int>> comp_e;
  vc<vc<int>> comp_v; // block -> vs
  vc<int> BCT_idx_edge;
  vc<int> BCT_idx_vertex;

  Biconnected_Component(GT& G) : G(G) {
    auto [ord, low] = calculate_lowlink();
    calculate_bcc(ord, low);
    build_bct();
  }

  int BCT_idx_v(int v) { return BCT_idx_vertex[v]; }
  int BCT_idx_e(int eid) { return BCT_idx_edge[eid]; }
  Graph<int> BCT() {
    Graph<int> bct(n_block + n_cut);
    for (auto&& [a, b]: BCT_edges) bct.add(a, b);
    bct.build();
    return bct;
  }
  bool is_articulation(int v) { return BCT_idx_v(v) >= n_block; }

private:
  void build_bct() {
    int n = G.N;
    vvc<int> nbd(n);
    n_block = len(comp_e);
    comp_v.resize(n_block);
    n_cut = 0;
    BCT_idx_edge.resize(G.M);
    BCT_idx_vertex.resize(G.N);

    auto add = [&](int v, int c) -> void {
      if (len(nbd[v]) && nbd[v].back() == c) return;
      nbd[v].eb(c);
    };

    FOR(c, len(comp_e)) {
      for (auto&& eid: comp_e[c]) {
        BCT_idx_edge[eid] = c;
        auto& e = G.edges[eid];
        add(e.frm, c);
        add(e.to, c);
      }
    }

    FOR(v, n) {
      if (len(nbd[v]) == 0) {
        // 孤立点は辺のない block
        BCT_idx_vertex[v] = n_block++;
        comp_v.eb(vc<int>({int(v)}));
      }
      if (len(nbd[v]) >= 2) {
        BCT_idx_vertex[v] = n_block + n_cut;
        for (auto&& c: nbd[v]) {
          BCT_edges.eb(n_block + n_cut, c);
          comp_v[c].eb(v);
        }
        n_cut++;
      }
      elif (len(nbd[v]) == 1) {
        int c = nbd[v][0];
        BCT_idx_vertex[v] = c;
        comp_v[c].eb(v);
      }
    }

    comp_e.resize(n_block);
  }

  pair<vc<int>, vc<int>> calculate_lowlink() {
    int n = G.N;
    vc<bool> used(n);
    vc<int> low(n), ord(n);
    int k = 0;
    auto dfs = [&](auto self, int v, int eid) -> void {
      used[v] = 1;
      low[v] = ord[v] = k++;
      for (auto&& e: G[v]) {
        if (e.id == eid) continue;
        if (!used[e.to]) {
          self(self, e.to, e.id);
          chmin(low[v], low[e.to]);
        } else {
          chmin(low[v], ord[e.to]);
        }
      }
    };
    FOR(v, n) if (!used[v]) dfs(dfs, v, -1);
    return {ord, low};
  }

  void calculate_bcc(vc<int>& ord, vc<int>& low) {
    int n = G.N;
    vc<bool> used(n);
    vc<int> buf;
    auto dfs = [&](auto self, int v, int eid) -> void {
      used[v] = 1;
      for (auto&& e: G[v]) {
        if (e.id == eid) continue;
        if (!used[e.to] || ord[e.to] < ord[v]) buf.eb(e.id);
        if (used[e.to]) continue;
        self(self, e.to, e.id);
        if (low[e.to] < ord[v]) continue;
        vc<int> edges;
        while (1) {
          edges.eb(buf.back());
          buf.pop_back();
          if (edges.back() == e.id) break;
        }
        comp_e.eb(edges);
      }
    };
    FOR(v, n) if (!used[v]) dfs(dfs, v, -1);
  }
};
