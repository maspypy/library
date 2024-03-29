#include "graph/tree.hpp"

/*
tute さんの実装 https://yukicoder.me/submissions/838092 を参考にしている.
いわゆる toptree （辺からはじめてマージ過程を木にする）とは少し異なるはず.
木を「heavy path 上の辺で分割」「根を virtual にする」
「light edges の分割」「light edge を消す」で頂点に分割していく.
逆にたどれば，1 頂点からはじめて木全体を作る高さ O(logN) の木になる.
高さについて：https://www.mathenachia.blog/mergetech-and-logn/
・lch == rch == -1：頂点
・rch == -1：
  ・heavy なら light の集約に頂点を付加したもの
  ・light なら 根付き木に light edge を付加したもの
・子が 2 つ
  ・heavy なら heavy path を辺で結合したもの
  ・light なら light edge たちのマージ
*/
template <typename TREE>
struct Static_TopTree {
  TREE &tree;

  vc<int> par, lch, rch, A, B;
  vc<bool> heavy;
  vc<int> v_to_k;

  vc<Data> dp;

  Static_TopTree(TREE &tree) : tree(tree) {}

  void init() {
    int root = tree.V[0];
    build(root);
    // relabel
    int n = len(par);
    reverse(all(par)), reverse(all(lch)), reverse(all(rch)), reverse(all(A)),
        reverse(all(B)), reverse(all(heavy));
    for (auto &x: par) x = (x == -1 ? -1 : n - 1 - x);
    for (auto &x: lch) x = (x == -1 ? -1 : n - 1 - x);
    for (auto &x: rch) x = (x == -1 ? -1 : n - 1 - x);
    dp.resize(n);
    v_to_k.resize(n, -1);
  }

  // 木全体での集約値を得る
  // from_vertex(v)
  // add_vertex(x, v)
  // add_edge(x, u, v)  : u が親
  // merge_light(x, y)
  // merge_heavy(x, y, a, b, c, d)  : [a,b] + [c,d] = [a,d]
  template <typename Data, typename F1, typename F2, typename F3, typename F4,
            typename F5>
  Data init_dp(F1 from_vertex, F2 add_vertex, F3 add_edge, F4 merge_light,
               F5 merge_heavy) {
    auto dfs = [&](auto &dfs, int k) -> Data {
      if (lch[k] == -1 && rch[k] == -1) {
        v_to_k[A[k]] = k;
        return dp[k] = from_vertex(A[k]);
      }
      if (rch[k] == -1) {
        Data x = dfs(dfs, lch[k]);
        if (heavy[k]) {
          v_to_k[A[k]] = k;
          return dp[k] = add_vertex(x, A[k]);
        } else {
          return dp[k] = add_edge(x, A[k], B[lch[k]]);
        }
      }
      Data x = dfs(dfs, lch[k]);
      Data y = dfs(dfs, rch[k]);
      if (heavy[k]) {
        return dp[k]
               = merge_heavy(x, y, A[lch[k]], B[lch[k]], A[rch[k]], B[rch[k]]);
      }
      return dp[k] = merge_light(x, y);
    };
    return dfs(dfs, 0);
  }

  Data update(int v, F1 from_vertex, F2 add_vertex, F3 add_edge, F4 merge_light,
              F5 merge_heavy) {
    int k = v_to_k[v];
    assert(k != -1);
    for (k = v_to_k[v]; k != -1; k = par[k]) {
      if (lch[k] == -1 && rch[k] == -1) {
        dp[k] = from_vertex(A[k]);
        continue;
      }
      if (rch[k] == -1) {
        Data x = dp[lch[k]];
        if (heavy[k]) {
          v_to_k[A[k]] = k;
          dp[k] = add_vertex(x, A[k]);
        } else {
          dp[k] = add_edge(x, A[k], B[lch[k]]);
        }
        continue;
      }
      Data x = dfs(dfs, lch[k]);
      Data y = dfs(dfs, rch[k]);
      if (heavy[k]) {
        dp[k] = merge_heavy(x, y, A[lch[k]], B[lch[k]], A[rch[k]], B[rch[k]]);
        continue;
      }
      dp[k] = merge_light(x, y);
    }
    return dp[0];
  }

private:
  int add_node(int l, int r, int a, int b, bool h) {
    int ret = len(par);
    par.eb(-1), lch.eb(l), rch.eb(r), A.eb(a), B.eb(b), heavy.eb(h);
    if (l != -1) par[l] = ret;
    if (r != -1) par[r] = ret;
    return ret;
  }

  int build(int v) {
    // v は heavy path の根なので v を根とする部分木に対応するノードを作る
    assert(tree.head[v] == v);
    auto path = tree.heavy_path_at(v);
    reverse(all(path));

    auto dfs = [&](auto &dfs, int l, int r) -> int {
      // path[l:r)
      if (l + 1 < r) {
        int m = (l + r) / 2;
        int x = dfs(dfs, l, m);
        int y = dfs(dfs, m, r);
        return add_node(x, y, path[l], path[r - 1], true);
      }
      assert(r == l + 1);
      int me = path[l];
      // sz, idx
      pqg<pair<int, int>> que;
      for (auto &to: tree.collect_light(me)) {
        int x = build(to);
        int y = add_node(x, -1, me, me, false);
        que.emplace(tree.subtree_size(to), y);
      }
      if (que.empty()) { return add_node(-1, -1, me, me, true); }
      while (len(que) >= 2) {
        auto [s1, x] = POP(que);
        auto [s2, y] = POP(que);
        int z = add_node(x, y, me, me, false);
        que.emplace(s1 + s2, z);
      }
      auto [s, x] = POP(que);
      return add_node(x, -1, me, me, true);
    };
    return dfs(dfs, 0, len(path));
  }

private:
  template <typename Data, typename F1, typename F2, typename F3, typename F4,
            typename F5>
  Data calc_at(int k, F1 from_vertex, F2 add_vertex, F3 add_edge,
               F4 merge_light, F5 merge_heavy) {
    if (lch[k] == -1 && rch[k] == -1) { return dp[k] = from_vertex(A[k]); }
    if (rch[k] == -1) {
      Data x = dfs(dfs, lch[k]);
      if (heavy[k]) {
        return dp[k] = add_vertex(x, A[k]);
      } else {
        return dp[k] = add_edge(x, A[k], B[lch[k]]);
      }
    }
    Data x = dfs(dfs, lch[k]);
    Data y = dfs(dfs, rch[k]);
    if (heavy[k]) {
      return dp[k]
             = merge_heavy(x, y, A[lch[k]], B[lch[k]], A[rch[k]], B[rch[k]]);
    }
    return dp[k] = merge_light(x, y);
  }
};