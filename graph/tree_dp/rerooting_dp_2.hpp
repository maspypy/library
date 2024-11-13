
// 中間計算結果を全部メモリに持って, 可能な限り同じ計算を複数回しないようにする
// メモリは増えるが一度の計算が重い場合には有効?????
// 永続データ構造のマージのときに少しメモリが節約できたがわずか
// https://qoj.ac/contest/1699/problem/8518
template <typename TREE, typename Data>
struct Rerooting_dp_2 {
  static_assert(!TREE::Graph_type::is_directed);
  TREE &tree;
  vc<Data> dp;   // full tree at v
  vc<Data> dp_1; // 辺 pv に対して、部分木 v
  vc<Data> dp_2; // 辺 pv に対して、部分木 p
  vc<Data> dp_3; // rootless pv
  vc<Data> dp_4; // dp_3 の左閉区間での累積

  template <typename F1, typename F2, typename F3>
  Rerooting_dp_2(TREE &tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) : tree(tree) {
    build(f_ee, f_ev, f_ve, unit);
  }

  // v を根としたときの full tree
  Data operator[](int v) { return dp[v]; }

  // root を根としたときの部分木 v
  Data get(int v, int root) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) { return dp_1[v]; }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }

  template <typename F1, typename F2, typename F3>
  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) {
    using Edge = typename TREE::Graph_type::edge_type;
    int N = tree.N;
    // dp_1: subtree
    // dp_3: v までの左閉区間
    dp_1.assign(N, unit);
    dp_3.assign(N, unit);
    dp_4.assign(N, unit);
    FOR_R(i, N) {
      int v = tree.V[i];
      vc<Edge> ch;
      for (auto &e: tree.G[v])
        if (e.to != tree.parent[v]) ch.eb(e);
      int n = len(ch);
      FOR(i, n) {
        auto &e = ch[i];
        int c = e.to;
        dp_3[c] = f_ve(dp_1[c], e);
        dp_4[c] = (i == 0 ? dp_3[c] : f_ee(dp_4[ch[i - 1].to], dp_3[c]));
      }
      dp_1[v] = (n == 0 ? f_ev(unit, v) : f_ev(dp_4[ch[n - 1].to], v));
    }

    // dp2[v]: subtree of p, rooted at v
    dp_2.assign(N, unit);
    // dp[v]: fulltree, rooted at v
    dp.assign(N, unit);
    FOR(i, N) {
      int v = tree.V[i];
      vc<Edge> ch;
      Data x = unit;
      for (auto &e: tree.G[v]) {
        if (e.to != tree.parent[v]) ch.eb(e);
        if (e.to == tree.parent[v]) x = f_ve(dp_2[v], e);
      }
      int n = len(ch);
      FOR_R(i, n) {
        Data lprod = (i > 0 ? dp_4[ch[i - 1].to] : unit);
        dp_2[ch[i].to] = f_ev(f_ee(lprod, x), v);
        x = f_ee(x, dp_3[ch[i].to]);
      }
      dp[v] = f_ev(x, v);
    }
  }
};