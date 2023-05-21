template <typename Cap>
struct MaxFlowGraph {
  struct Edge {
    int to, rev;
    Cap cap;
  };

  int N;
  vc<tuple<int, int, Cap, Cap>> dat;
  vc<int> prog, level;
  vc<int> que;
  vc<Edge> G;
  vc<int> indptr;
  Cap flow_ans;
  bool calculated;
  bool is_prepared;

  MaxFlowGraph(int N) : N(N), calculated(0), is_prepared(0) {}

  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= cap);
    if (frm == to) return;
    dat.eb(frm, to, cap, rev_cap);
  }

  void build() {
    assert(!is_prepared);
    int M = len(dat);
    is_prepared = 1;
    indptr.assign(N, 0);
    for (auto&& [a, b, c, d]: dat) indptr[a]++, indptr[b]++;
    indptr = cumsum<int>(indptr);
    vc<int> nxt_idx = indptr;
    G.resize(2 * M);
    for (auto&& [a, b, c, d]: dat) {
      int p = nxt_idx[a]++;
      int q = nxt_idx[b]++;
      G[p] = Edge{b, q, c};
      G[q] = Edge{a, p, d};
    }
  }

  Cap flow(int source, int sink) {
    assert(is_prepared);
    if (calculated) return flow_ans;
    calculated = true;
    flow_ans = 0;
    while (set_level(source, sink)) {
      prog = indptr;
      while (1) {
        Cap x = flow_dfs(source, sink, infty<Cap>);
        if (x == 0) break;
        flow_ans += x;
        chmin(flow_ans, infty<Cap>);
        if (flow_ans == infty<Cap>) return flow_ans;
      }
    }
    return flow_ans;
  }

  // 最小カットの値および、カットを表す 01 列を返す
  pair<Cap, vc<int>> cut(int source, int sink) {
    Cap f = flow(source, sink);
    vc<int> res(N);
    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);
    return {f, res};
  }

  // 残余グラフの辺
  vc<tuple<int, int, Cap>> get_edges() {
    vc<tuple<int, int, Cap>> edges;
    FOR(v, N) {
      FOR(k, indptr[v], indptr[v + 1]) {
        auto& e = G[k];
        edges.eb(v, e.to, e.cap);
      }
    }
    return edges;
  }

private:
  bool set_level(int source, int sink) {
    que.resize(N);
    level.assign(N, -1);
    level[source] = 0;
    int l = 0, r = 0;
    que[r++] = source;
    while (l < r) {
      int v = que[l++];
      FOR(k, indptr[v], indptr[v + 1]) {
        auto& e = G[k];
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[v] + 1;
          if (e.to == sink) return true;
          que[r++] = e.to;
        }
      }
    }
    return false;
  }

  Cap flow_dfs(int v, int sink, Cap lim) {
    if (v == sink) return lim;
    Cap res = 0;
    for (int& i = prog[v]; i < indptr[v + 1]; ++i) {
      auto& e = G[i];
      if (e.cap > 0 && level[e.to] == level[v] + 1) {
        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));
        if (a > 0) {
          e.cap -= a;
          G[e.rev].cap += a;
          res += a;
          lim -= a;
          if (lim == 0) break;
        }
      }
    }
    return res;
  }
};

void solve() {
  LL(H, W, X, Y);

  auto idx = [&](int x, int y, int side) -> int {
    return (W + W) * x + (2 * y + side);
  };

  VEC(string, shape, H);
  VEC(string, color, H);
  VV(int, cost, H, W);

  using P = pair<int, int>;
  using T = array<P, 3>;
  vvv(T, dat, H, W, 2);

  // 三角形の座標
  FOR(x, H) FOR(y, W) FOR(s, 2) {
    if (s == 0) {
      dat[x][y][s][0] = {x, y};
      dat[x][y][s][1] = {x + 1, y};
      if (shape[x][y] == '/') {
        dat[x][y][s][2] = {x, y + 1};
      } else {
        dat[x][y][s][2] = {x + 1, y + 1};
      }
    }
    if (s == 1) {
      dat[x][y][s][0] = {x, y + 1};
      dat[x][y][s][1] = {x + 1, y + 1};
      if (shape[x][y] == '/') {
        dat[x][y][s][2] = {x + 1, y};
      } else {
        dat[x][y][s][2] = {x, y};
      }
    };
  }

  UnionFind uf(2 * H * W);
  auto merge = [&](int x1, int y1, int s1, int x2, int y2, int s2) -> void {
    if (color[x1][2 * y1 + s1] != '#') return;
    if (color[x2][2 * y2 + s2] != '#') return;
    uf.merge(idx(x1, y1, s1), idx(x2, y2, s2));
  };

  // merge black cells
  FOR(x1, H) FOR(y1, W) {
    // share vertex
    FOR(dx, -1, 2) FOR(dy, -1, 2) {
      int x2 = x1 + dx, y2 = y1 + dy;
      if (x2 < 0 || x2 >= H) continue;
      if (y2 < 0 || y2 >= W) continue;
      FOR(s1, 2) FOR(s2, 2) {
        T A = dat[x1][y1][s1];
        T B = dat[x2][y2][s2];
        bool ok = 0;
        FOR(i, 3) FOR(j, 3) if (A[i] == B[j]) ok = 1;
        if (ok) merge(x1, y1, s1, x2, y2, s2);
      }
    }
  }

  vc<int> roots;
  FOR(x, H) FOR(y, W) FOR(s, 2) {
    int i = idx(x, y, s);
    if (uf[i] != i) continue;
    if (color[x][2 * y + s] != '#') continue;
    roots.eb(i);
  }

  vc<tuple<int, int, int>> edge;
  auto add = [&](int a, int b, int c) -> void { edge.eb(a, b, c); };

  int sink = 2 * H * W;
  // diagonal
  FOR(x, H) FOR(y, W) {
    int c = cost[x][y];
    if (color[x][2 * y + 0] == '#' || color[x][2 * y + 1] == '#') {
      c = infty<int>;
    }
    add(idx(x, y, 0), idx(x, y, 1), c);
    // add(idx(x, y, 1), idx(x, y, 0), c);
  }
  // x,x+1
  FOR(x, -1, H) FOR(y, W) {
    int c = X;
    int a = sink;
    if (x >= 0) {
      int s = (shape[x][y] == '/' ? 1 : 0);
      if (color[x][2 * y + s] == '#') { c = infty<int>; }
      a = idx(x, y, s);
    }
    int b = sink;
    if (x + 1 < H) {
      int s = (shape[x + 1][y] == '/' ? 0 : 1);
      if (color[x + 1][2 * y + s] == '#') { c = infty<int>; }
      b = idx(x + 1, y, s);
    }
    add(a, b, c);
    // add(b, a, c);
  }
  // y,y+1
  FOR(x, H) FOR(y, -1, W) {
    int c = Y;
    int a = sink;
    if (y >= 0) {
      int s = (shape[x][y] == '/' ? 1 : 1);
      if (color[x][2 * y + s] == '#') { c = infty<int>; }
      a = idx(x, y, s);
    }
    int b = sink;
    if (y + 1 < W) {
      int s = (shape[x][y + 1] == '/' ? 0 : 0);
      if (color[x][2 * (y + 1) + s] == '#') { c = infty<int>; }
      b = idx(x, y + 1, s);
    }
    add(a, b, c);
    // add(b, a, c);
  }