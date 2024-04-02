#include "graph/tree.hpp"

/*
参考 joitour tatyam
クラスタとは根が欠けた状態
N 個の (頂+辺) をマージしていって，木全体＋根から親への辺とする．
single(v) : v とその親辺を合わせたクラスタ
rake(x, y, u, v) uv(top down) が boundary になるように rake (maybe v=-1)
compress(x,y,a,b,c)  (top-down) 順に (a,b] + (b,c]
*/
template <typename TREE>
struct Static_TopTree {
  int N;
  TREE &tree;
  vc<int> par, lch, rch, A, B; // A, B boundary (top-down)
  vc<bool> is_compress;

  Static_TopTree(TREE &tree) : tree(tree) { build(); }

  void build() {
    N = tree.N;
    par.assign(N, -1), lch.assign(N, -1), rch.assign(N, -1), A.assign(N, -1),
        B.assign(N, -1), is_compress.assign(N, 0);
    FOR(v, N) { A[v] = tree.parent[v], B[v] = v; }
    build_dfs(tree.V[0]);
    assert(len(par) == 2 * N - 1);
  }

  // 木全体での集約値を得る
  // single(v) : v とその親辺を合わせたクラスタ
  // rake(x, y, u, v) uv(top down) が boundary になるように rake (maybe v=-1)
  // compress(x,y,a,b,c)  (top-down) 順に (a,b] + (b,c]
  template <typename Data, typename F1, typename F2, typename F3>
  Data tree_dp(F1 single, F2 rake, F3 compress) {
    auto dfs = [&](auto &dfs, int k) -> Data {
      if (0 <= k && k < N) return single(k);
      Data x = dfs(dfs, lch[k]), y = dfs(dfs, rch[k]);
      if (is_compress[k]) {
        assert(B[lch[k]] == A[rch[k]]);
        return compress(x, y, A[lch[k]], B[lch[k]], B[rch[k]]);
      }
      return rake(x, y, A[k], B[k]);
    };
    return dfs(dfs, 2 * N - 2);
  }

private:
  int new_node(int l, int r, int a, int b, bool c) {
    int v = len(par);
    par.eb(-1), lch.eb(l), rch.eb(r), A.eb(a), B.eb(b), is_compress.eb(c);
    par[l] = par[r] = v;
    return v;
  }
  int build_dfs(int v) {
    assert(tree.head[v] == v);
    auto path = tree.heavy_path_at(v);
    auto dfs = [&](auto &dfs, int l, int r) -> int {
      // path[l:r)
      if (l + 1 < r) {
        int m = (l + r) / 2;
        int x = dfs(dfs, l, m);
        int y = dfs(dfs, m, r);
        return new_node(x, y, A[x], B[y], true);
      }
      assert(r == l + 1);
      if (l == 0) { return path[l]; }
      // sz, idx
      pqg<pair<int, int>> que;
      int p = path[l - 1];
      for (auto &to: tree.collect_light(p)) {
        int x = build_dfs(to);
        que.emplace(tree.subtree_size(to), x);
      }
      if (que.empty()) { return path[l]; }
      while (len(que) >= 2) {
        auto [s1, x] = POP(que);
        auto [s2, y] = POP(que);
        int z = new_node(x, y, p, -1, false);
        que.emplace(s1 + s2, z);
      }
      auto [s, x] = POP(que);
      return new_node(path[l], x, p, path[l], false);
    };
    return dfs(dfs, 0, len(path));
  }
};