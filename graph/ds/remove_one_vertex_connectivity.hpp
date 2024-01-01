#include "graph/base.hpp"

// 1 点消したときに
// u,v が連結か / 連結成分数 / v の連結成分サイズ
struct Remove_One_Vertex_Connectivity {
  int N, M, n_comp_base;
  vc<int> root;
  vc<int> LID, RID;
  vc<int> low;
  vvc<int> ch;
  vc<int> rm_sz, rm_comp;

  template <typename GT>
  Remove_One_Vertex_Connectivity(GT& G) {
    build(G);
  }

  template <typename GT>
  void build(GT& G) {
    N = G.N, M = G.M;
    root.assign(N, -1);
    LID.assign(N, -1), RID.assign(N, -1), low.assign(N, -1);
    ch.resize(N);
    int p = 0;
    n_comp_base = 0;
    auto dfs = [&](auto& dfs, int v, int last_e) -> void {
      low[v] = LID[v] = p++;
      for (auto&& e: G[v]) {
        if (e.id == last_e) continue;
        if (root[e.to] == -1) {
          root[e.to] = root[v];
          ch[v].eb(e.to);
          dfs(dfs, e.to, e.id);
          chmin(low[v], low[e.to]);
        } else {
          chmin(low[v], LID[e.to]);
        }
      }
      RID[v] = p;
    };
    FOR(v, N) {
      if (root[v] == -1) { n_comp_base++, root[v] = v, dfs(dfs, v, -1); }
    }
    rm_sz.assign(N, 0);
    rm_comp.assign(N, n_comp_base);
    FOR(v, N) {
      if (root[v] == v) {
        rm_comp[v] += len(ch[v]) - 1;
      } else {
        rm_sz[v] = subtree_size(root[v]) - 1;
        for (auto& c: ch[v]) {
          if (low[c] >= LID[v]) { rm_sz[v] -= subtree_size(c), rm_comp[v]++; }
        }
      }
    }
  }

  int n_comp(int rm) { return rm_comp[rm]; }

  bool is_connected(int rm, int u, int v) {
    assert(u != rm && v != rm);
    if (root[u] != root[v]) return false;
    if (root[u] != root[rm]) return true;
    bool in_u = in_subtree(u, rm), in_v = in_subtree(v, rm);
    if (in_u) { u = jump(rm, u), in_u = low[u] >= LID[rm]; }
    if (in_v) { v = jump(rm, v), in_v = low[v] >= LID[rm]; }
    if (in_u != in_v) return false;
    return (in_u ? u == v : true);
  }

  int size(int rm, int v) {
    assert(rm != v);
    if (root[v] != root[rm]) return subtree_size(root[v]);
    if (rm == root[v]) { return subtree_size(jump(rm, v)); }
    if (!in_subtree(v, rm)) { return rm_sz[rm]; }
    v = jump(rm, v);
    return (LID[rm] <= low[v] ? subtree_size(v) : rm_sz[rm]);
  }

private:
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }
  int subtree_size(int v) { return RID[v] - LID[v]; }
  int jump(int r, int v) {
    assert(r != v && in_subtree(v, r));
    int n = len(ch[r]);
    int k = binary_search(
        [&](int k) -> bool {
          int c = ch[r][k];
          return LID[c] <= LID[v];
        },
        0, n);
    return ch[r][k];
  }
};
