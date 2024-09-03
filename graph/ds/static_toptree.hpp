#include "graph/tree.hpp"

/*
参考 joitour tatyam
クラスタは根が virtual なもののみであるような簡易版
N 個の (頂+辺) をマージしていって，木全体＋根から親への辺とする．
single(v) : v とその親辺を合わせたクラスタ
rake(L,R) : L の boundary を維持
compress(L,R)  (top-down) 順に x,y
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
    par.assign(N, -1), lch.assign(N, -1), rch.assign(N, -1), A.assign(N, -1), B.assign(N, -1), is_compress.assign(N, 0);
    FOR(v, N) { A[v] = tree.parent[v], B[v] = v; }
    build_dfs(tree.V[0]);
    assert(len(par) == 2 * N - 1);
  }

  // 木全体での集約値を得る
  // single(v) : v とその親辺を合わせたクラスタ
  // rake(x, y, u, v) uv(top down) が boundary になるように rake (maybe v=-1)
  // compress(x,y,a,b,c)  (top-down) 順に (a,b] + (b,c]
  template <typename TREE_DP, typename F>
  typename TREE_DP::value_type tree_dp(F single) {
    using Data = typename TREE_DP::value_type;
    auto dfs = [&](auto &dfs, int k) -> Data {
      if (0 <= k && k < N) return single(k);
      Data x = dfs(dfs, lch[k]), y = dfs(dfs, rch[k]);
      if (is_compress[k]) {
        assert(B[lch[k]] == A[rch[k]]);
        return TREE_DP::compress(x, y);
      }
      return TREE_DP::rake(x, y);
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

  // height, node idx
  // compress 参考：https://atcoder.jp/contests/abc351/editorial/9910
  // ただし heavy path の選び方までは考慮しない
  pair<int, int> build_dfs(int v) {
    assert(tree.head[v] == v);
    auto path = tree.heavy_path_at(v);
    vc<pair<int, int>> stack;
    stack.eb(0, path[0]);
    auto merge_last_two = [&]() -> void {
      auto [h2, k2] = POP(stack);
      auto [h1, k1] = POP(stack);
      stack.eb(max(h1, h2) + 1, new_node(k1, k2, A[k1], B[k2], true));
    };

    FOR(i, 1, len(path)) {
      pqg<pair<int, int>> que;
      int k = path[i];
      que.emplace(0, k);
      for (auto &c: tree.collect_light(path[i - 1])) { que.emplace(build_dfs(c)); }
      while (len(que) >= 2) {
        auto [h1, i1] = POP(que);
        auto [h2, i2] = POP(que);
        if (i2 == k) swap(i1, i2);
        int i3 = new_node(i1, i2, A[i1], B[i1], false);
        if (k == i1) k = i3;
        que.emplace(max(h1, h2) + 1, i3);
      }
      stack.eb(POP(que));

      while (1) {
        int n = len(stack);
        if (n >= 3 && (stack[n - 3].fi == stack[n - 2].fi || stack[n - 3].fi <= stack[n - 1].fi)) {
          auto [h3, k3] = POP(stack);
          merge_last_two(), stack.eb(h3, k3);
        }
        elif (n >= 2 && stack[n - 2].fi <= stack[n - 1].fi) { merge_last_two(); }
        else break;
      }
    }
    while (len(stack) >= 2) { merge_last_two(); }
    return POP(stack);
  }
};