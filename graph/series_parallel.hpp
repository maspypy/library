// https://codeforces.com/problemset/problem/2206/G
// two-terminal series parallel
// series:次数2の点からなるパスの縮約
// parallel:多重辺の縮約
// これを使ってひとつの辺 st にする仮定を木で表す
struct Series_Parallel {
  enum Etype { EDGE, S, P };
  struct Node {
    int s, t;
    Etype type;
    vector<int> ch;
  };

  int N, M, root;
  vector<Node> nodes;

  template <typename F>
  Series_Parallel(int N, int M, F f) : N(N), M(M), root(-1) {
    VtoE.resize(N), deg.resize(N);
    FOR(i, M) {
      auto [a, b] = f(i);
      add_node(a, b, Etype::EDGE, {});
    }
  }

  // SP graph でなかったら false が返る
  bool build(int S, int T) {
    if (deg[S] == 0 || deg[T] == 0) return false;
    while (1) {
      if (len(queS)) {
        int v = POP(queS);
        if (v == S || v == T || deg[v] != 2) continue;
        int a = -1, b = -1;
        for (auto& idx : VtoE[v]) {
          if (!active[idx]) continue;
          (a == -1 ? a : b) = idx;
        }
        int s = nodes[a].s + nodes[a].t - v;
        int t = nodes[b].s + nodes[b].t - v;
        if (s == t) return false;
        deactivate(a), deactivate(b);
        add_node(s, t, Etype::S, {a, b});
        continue;
      }
      if (len(queP)) {
        pair<int, int> k = POP(queP);
        vc<int> E = PtoE[k];
        if (len(E) <= 1) continue;
        assert(len(E) >= 2);
        PtoE[k].clear();
        for (auto& idx : E) deactivate(idx);
        add_node(k.fi, k.se, Etype::P, E);
        continue;
      }
      break;
    }
    // success?
    FOR(i, len(nodes) - 1) if (active[i]) return false;

    // normalize
    vc<bool> vis(len(nodes));
    auto dfs = [&](auto& dfs, int i, int s) -> void {
      vis[i] = 1;
      // nodes[i] を正規化
      if (nodes[i].s != s) {
        swap(nodes[i].s, nodes[i].t);
        reverse(all(nodes[i].ch));
      }
      assert(nodes[i].s == s);
      if (nodes[i].type == Etype::EDGE) return;
      // 違うタイプの子だけを改めて並べる
      vc<int> ch;
      auto F = [&](auto& F, int j, int s) -> void {
        if (nodes[j].s != s) {
          swap(nodes[j].s, nodes[j].t);
          reverse(all(nodes[j].ch));
        }
        if (nodes[i].type != nodes[j].type) {
          ch.eb(j);
        } else {
          int v = s;
          for (int k : nodes[j].ch) {
            F(F, k, v);
            v = (nodes[j].type == Etype::P ? v : nodes[k].t);
          }
        }
      };
      F(F, i, s);
      nodes[i].ch = ch;
      int v = s;
      for (auto& c : ch) {
        dfs(dfs, c, v);
        v = (nodes[i].type == Etype::P ? v : nodes[c].t);
      }
    };
    dfs(dfs, len(nodes) - 1, S);

    // 無視されたノードを除外
    vc<int> new_idx(len(nodes), -1);
    int p = 0;
    FOR(i, len(nodes)) if (vis[i]) { new_idx[i] = p, nodes[p] = nodes[i], p++; }
    nodes.resize(p);
    FOR(i, p) {
      for (auto& j : nodes[i].ch) j = new_idx[j];
    }
    root = p - 1;
    return true;
  }

 private:
  vc<int> deg;
  vc<bool> active;
  map<pair<int, int>, vc<int>> PtoE;
  vvc<int> VtoE;
  vc<pair<int, int>> queP;
  vc<int> queS;

  void add_node(int s, int t, Etype type, vector<int> ch) {
    if (s > t) {
      swap(s, t);
      reverse(all(ch));
    }
    int idx = len(nodes);
    nodes.eb(Node{s, t, type, ch});
    active.eb(true);

    // pair -> edges
    pair<int, int> k = {s, t};
    PtoE[k].eb(idx);
    VtoE[s].eb(idx), VtoE[t].eb(idx);
    deg[s]++, deg[t]++;

    if (len(PtoE[k]) >= 2) queP.eb(k);
    if (deg[s] == 2) queS.eb(s);
    if (deg[t] == 2) queS.eb(t);
  }

  void deactivate(int k) {
    int s = nodes[k].s, t = nodes[k].t;
    deg[s]--, deg[t]--, active[k] = false;
  }
};
