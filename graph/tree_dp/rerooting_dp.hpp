template <typename TREE, typename Data>
struct Rerooting_DP {
  TREE& tree;

  // full tree rooted at v
  vc<Data> dp;
  // subtree v with respect to the original root
  vc<Data> dp_subtree;
  // component containing parent[v] after removing edge parent[v]-v,
  // rooted at parent[v]
  vc<Data> dp_parent;

  template <typename F1, typename F2, typename F3>
  Rerooting_DP(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data id)
      : tree(tree) {
    build(f_ee, f_ev, f_ve, id);
  }

  Data operator[](int v) const { return dp[v]; }

  // root を根としたときの部分木 v
  Data get(int v, int root) const {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) return dp_subtree[v];
    int w = tree.jump(v, root, 1);
    return dp_parent[w];
  }

  template <typename F1, typename F2, typename F3>
  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data id) {
    int N = tree.N;
    dp.assign(N, id);
    dp_subtree.assign(N, id);
    dp_parent.assign(N, id);
    FOR_R(i, N) {
      int v = tree.V[i];
      Data X = id;
      for (int c : tree.collect_child(v)) {
        dp[c] = X;
        dp_parent[c] = f_ve(dp_subtree[c], c, v);
        X = f_ee(X, dp_parent[c]);
      }
      dp_subtree[v] = f_ev(X, v);
    }
    FOR(i, N) {
      int v = tree.V[i];
      auto ch = tree.collect_child(v);

      Data X = id;
      if (tree.parent[v] != -1) {
        X = f_ve(dp_parent[v], tree.parent[v], v);
      }

      FOR_R(k, len(ch)) {
        int c = ch[k];
        Data Y = f_ee(dp[c], X);
        Data branch = dp_parent[c];
        X = f_ee(branch, X);
        dp_parent[c] = f_ev(Y, v);
      }
      dp[v] = f_ev(X, v);
    }
  }
};