
// https://codeforces.com/blog/entry/111290
// https://codeforces.com/gym/421334/problem/A
// https://atcoder.jp/contests/npcapc_2024/tasks/npcapc_2024_j
template <int NMAX>
struct Permutation_Group_Basis {
  using A = array<u8, NMAX>;
  int n;
  // Basis[i]: i 未満は固定して i を動かす部分
  // 作れる群：g=g[0]g[1]...g[n-1]
  // g[i]: i 未満を固定して i を動かす写像
  // g から g[i] を復元するには，小さい i から順に決める
  vvc<A> Basis;

  // q := p
  void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i] = p[i]; }
  // r := pq
  void op(int lv, const A& p, A& q, A& r) { FOR(i, lv, n) r[i] = p[q[i]]; }
  // q := inv(p)
  void inv(int lv, const A& p, A& q) { FOR(i, lv, n) q[p[i]] = i; }

  // N^2 個以下生成元を sims filter で管理
  struct S {
    int n, lv;
    A dat[NMAX][NMAX];
    A idat[NMAX][NMAX];
    bool exist[NMAX][NMAX];
    S(int n, int lv) : n(n), lv(lv) { FOR(i, NMAX) FOR(j, NMAX) exist[i][j] = 0; }
    void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i] = p[i]; }
    void op(int lv, const A& p, A& q, A& r) { FOR(i, lv, n) r[i] = p[q[i]]; }
    void inv(int lv, const A& p, A& q) { FOR(i, lv, n) q[p[i]] = i; }
    void add(A& p) {
      static A tmp;
      FOR(i, lv, n) {
        if (p[i] == i) continue;
        if (!exist[i][p[i]]) {
          cp(i, p, dat[i][p[i]]);
          inv(i, p, idat[i][p[i]]);
          exist[i][p[i]] = 1;
          break;
        }
        op(i, idat[i][p[i]], p, tmp);
        cp(i, tmp, p);
      }
    }
    vc<A> get_all() {
      vc<A> ANS;
      FOR(i, lv, n) {
        FOR(j, i, n) {
          if (!exist[i][j]) continue;
          A a = dat[i][j];
          FOR(k, i) a[k] = k;
          ANS.eb(a);
        }
      }
      return ANS;
    }
  };

  Permutation_Group_Basis(int n, vvc<int> generator) : n(n), Basis(n) {
    S gen(n, 0);
    for (auto& pp: generator) {
      assert(len(pp) == n);
      A a;
      FOR(i, n) a[i] = pp[i];
      gen.add(a);
    }
    FOR(lv, n) gen = step(gen);
  }

private:
  S step(S gen) {
    auto X = gen.get_all();
    int lv = gen.lv;
    vc<A> basis(n);
    vc<A> ibasis(n);
    vc<bool> vis(n);
    auto dfs = [&](auto& dfs, int v) -> void {
      auto& p = basis[v];
      for (auto& q: X) {
        int w = q[v];
        if (vis[w]) continue;
        vis[w] = 1;
        op(lv, q, p, basis[w]);
        inv(lv, basis[w], ibasis[w]);
        dfs(dfs, w);
      }
    };
    vis[lv] = 1;
    FOR(i, n) basis[lv][i] = ibasis[lv][i] = i;
    dfs(dfs, lv);

    S nxtgen(n, lv + 1);
    static A tmp, tmp2;
    FOR(u, lv, n) {
      if (!vis[u]) continue;
      FOR(i, lv) basis[u][i] = i;
      Basis[lv].eb(basis[u]);
      for (auto& s: X) {
        assert(vis[s[u]]);
        op(lv, ibasis[s[u]], s, tmp);
        op(lv, tmp, basis[u], tmp2);
        assert(tmp2[lv] == lv);
        nxtgen.add(tmp2);
      }
    }
    return nxtgen;
  }
};
