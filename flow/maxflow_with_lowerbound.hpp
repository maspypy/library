
template <typename Cap>
struct MaxFlow_With_LowerBound {
  int N, s, t, S, T;
  Cap flow_ans;
  bool prepared = 0;

  struct Edge_raw {
    int frm, to;
    Cap lo, hi;
    Edge_raw(int frm, int to, Cap lo, Cap hi) : frm(frm), to(to), lo(lo), hi(hi){};
  };
  vc<Edge_raw> dat;

  MaxFlow_With_LowerBound(int N, int s, int t) : N(N), s(s), t(t), S(N), T(N + 1), flow_ans(0) {
    assert(0 <= s && s < N);
    assert(0 <= t && t < N);
  }
  void add(int frm, int to, Cap lo, Cap hi) {
    assert(!prepared);
    assert(0 <= frm && frm < N);
    assert(0 <= to && to < N);
    assert(Cap(0) <= lo && lo <= hi);
    dat.eb(Edge_raw(frm, to, lo, hi));
  }

  struct Edge {
    int rev, to;
    Cap cap, flow;
  };

  vc<Edge> G;
  vc<int> indptr;
  vc<int> idx;
  vc<int> level, que, prog;

  void debug() {
    print("frm,to,lo,hi");
    for (auto& e: dat) print(e.frm, e.to, e.lo, e.hi);
  }

  void build() {
    assert(!prepared);
    prepared = 1;
    int M = len(dat);
    idx.assign(6 * M, -1);
    vc<int> cnt(N + 2);
    FOR(i, M) {
      auto [frm, to, lo, hi] = dat[i];
      if (frm == to) continue;
      if (lo < hi) cnt[frm]++, cnt[to]++;
      if (0 < lo) cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;
    }
    indptr = cumsum<int>(cnt);
    int m = indptr.back();
    G.resize(m);
    vc<int> prog = indptr;
    auto add = [&](int i, int j, int a, int b, Cap c) -> void {
      int p = prog[a]++, q = prog[b]++;
      idx[i] = p, idx[j] = q;
      G[p] = {q, b, c, 0};
      G[q] = {p, a, 0, 0};
    };
    FOR(i, M) {
      auto [frm, to, lo, hi] = dat[i];
      if (frm == to) continue;
      if (lo < hi) add(6 * i + 0, 6 * i + 1, frm, to, hi - lo);
      if (0 < lo) {
        add(6 * i + 2, 6 * i + 3, S, to, lo);
        add(6 * i + 4, 6 * i + 5, frm, T, lo);
        cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;
      }
    }
  }

  Cap flow() {
    build();
    Cap a = flow_st(S, T), b = flow_st(S, t), c = flow_st(s, T), d = flow_st(s, t);
    bool valid = 1;
    int M = len(dat);
    FOR(i, M) {
      auto [frm, to, lo, hi] = dat[i];
      if (lo > 0 && G[idx[6 * i + 2]].cap > 0) valid = 0;
      if (lo > 0 && G[idx[6 * i + 4]].cap > 0) valid = 0;
    }
    if (!valid) return flow_ans = -1;
    assert(a + b == a + c && c + d == b + d);
    return flow_ans = c + d;
  }

  void set_level(int s) {
    level.assign(N + 2, infty<int>);
    que.resize(N + 2);
    int ql = 0, qr = 0;
    auto upd = [&](int v, int d) -> void {
      if (chmin(level[v], d)) que[qr++] = v;
    };
    upd(s, 0);
    while (ql < qr) {
      int v = que[ql++];
      FOR(i, indptr[v], indptr[v + 1]) {
        auto& e = G[i];
        if (e.cap > 0) upd(e.to, level[v] + 1);
      }
    }
  }

  Cap flow_dfs(int s, int t) {
    prog = indptr;
    auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {
      if (v == t) return lim;
      Cap res = 0;
      for (int& i = prog[v]; i < indptr[v + 1]; ++i) {
        auto& e = G[i];
        if (e.cap > 0 && level[e.to] == level[v] + 1) {
          Cap a = dfs(dfs, e.to, min(lim, e.cap));
          if (a == Cap(0)) continue;
          e.cap -= a, e.flow += a;
          G[e.rev].cap += a, G[e.rev].flow -= a;
          res += a, lim -= a;
          if (lim == Cap(0)) break;
        }
      }
      return res;
    };
    return dfs(dfs, s, infty<Cap>);
  }

  Cap flow_st(int s, int t) {
    Cap ans = 0;
    while (1) {
      set_level(s);
      if (level[t] == infty<int>) break;
      ans += flow_dfs(s, t);
    }
    return ans;
  }

  // add した順にひととおり
  vc<Cap> get_flow_result() {
    assert(flow_ans != Cap(-1));
    int M = len(dat);
    vc<Cap> res(M);
    FOR(i, M) {
      auto [frm, to, lo, hi] = dat[i];
      Cap flow = (lo < hi ? G[idx[6 * i + 1]].cap + lo : lo);
      // print(frm, to, lo, hi, flow);
      res[i] = flow;
    }
    return res;
  }
};