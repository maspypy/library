#include "random/base.hpp"
#include "graph/tree.hpp"
#include "mod/modint61.hpp"

// 木の辺に文字がちょうどひとつ書いてある (static)
template <typename TREE, bool EDGE>
struct Rolling_Hash_On_Tree {
  using mint = modint61;

  TREE& tree;
  int N;
  mint base;
  // edge に文字があると思って
  // dp1: [root,v]
  // dp2: [v,root]
  vc<int> dat;
  vc<mint> dp1, dp2;
  vc<mint> pow, ipow;

  template <typename F>
  Rolling_Hash_On_Tree(TREE& tree, F f, mint base_ = 0)
      : tree(tree), N(tree.N), base(base_) {
    if (base == mint(0)) base = RNG(mint::get_mod());
    build(f);
  }

  template <typename F>
  void build(F f) {
    dat.resize(N);
    if constexpr (EDGE) {
      FOR(i, N - 1) { dat[tree.e_to_v(i)] = f(i); }
    } else {
      FOR(i, N) { dat[i] = f(i); }
    }
    pow.resize(N + 1), ipow.resize(N + 1);
    pow[0] = 1, pow[1] = base;
    ipow[0] = 1, ipow[1] = base.inverse();
    FOR(i, 2, N + 1) pow[i] = pow[i - 1] * pow[1];
    FOR(i, 2, N + 1) ipow[i] = ipow[i - 1] * ipow[1];
    int root = tree.V[0];
    dp1.resize(N), dp2.resize(N);
    dp1[root] = dp2[root] = dat[0];
    FOR(i, 1, N) {
      int v = tree.V[i];
      int d = tree.depth[v], p = tree.parent[v];
      dp1[v] = base * dp1[p] + dat[v];
      dp2[v] = dp2[p] + pow[d] * dat[v];
    }
  }

  mint get(int a, int b) {
    int c = tree.lca(a, b);
    mint x1 = get_du(a, c), x2 = get_ud(c, b);
    int n2 = tree.depth[b] - tree.depth[c];
    if constexpr (!EDGE) { x1 = x1 * base + dat[c]; }
    return x1 * pow[n2] + x2;
  }

  int lcp(int s1, int t1, int s2, int t2) {
    return lcp_and_comp(s1, t1, s2, t2).fi;
  }

  // <=>
  char comp(int s1, int t1, int s2, int t2) {
    return lcp_and_comp(s1, t1, s2, t2).se;
  }

  pair<int, char> lcp_and_comp(int s1, int t1, int s2, int t2) {
    int lcp = 0;
    // heavy path の頂点列
    auto path1 = tree.get_path_decomposition(s1, t1, EDGE);
    auto path2 = tree.get_path_decomposition(s2, t2, EDGE);
    reverse(all(path1));
    reverse(all(path2));
    while (len(path1) && len(path2)) {
      int a, b, c, d;
      tie(a, b) = POP(path1), tie(c, d) = POP(path2);
      ll n1 = abs(a - b) + 1, n2 = abs(c - d) + 1;
      ll n = min(n1, n2);
      if (n < n1) {
        if (a <= b) { path1.eb(a + n, b), b = a + n - 1; }
        if (a > b) { path1.eb(a - n, b), b = a - n + 1; }
      }
      if (n < n2) {
        if (c <= d) { path2.eb(c + n, d), d = c + n - 1; }
        if (c > d) { path2.eb(c - n, d), d = c - n + 1; }
      }
      mint x1 = from_hld_pair(a, b), x2 = from_hld_pair(c, d);
      if (x1 == x2) {
        lcp += n;
        continue;
      }
      auto check = [&](ll n) -> bool {
        if (n == 0) return 1;
        mint x1 = (a <= b ? from_hld_pair(a, a + n - 1)
                          : from_hld_pair(a, a - n + 1));
        mint x2 = (c <= d ? from_hld_pair(c, c + n - 1)
                          : from_hld_pair(c, c - n + 1));
        return x1 == x2;
      };
      ll k = binary_search(check, 0, n);
      lcp += k;
      a = (a <= b ? a + k : a - k);
      c = (c <= d ? c + k : c - k);
      a = tree.V[a], c = tree.V[c];
      if (dat[a] < dat[c]) return {lcp, '<'};
      if (dat[a] == dat[c]) return {lcp, '='};
      if (dat[a] > dat[c]) return {lcp, '>'};
    }
    if (!path1.empty()) return {lcp, '>'};
    if (!path2.empty()) return {lcp, '<'};
    return {lcp, '='};
  }

private:
  mint get_ud(int a, int b) {
    return (a == -1 ? dp1[b]
                    : dp1[b] - dp1[a] * pow[tree.depth[b] - tree.depth[a]]);
  }
  mint get_du(int a, int b) {
    return (b == -1 ? dp2[a] : (dp2[a] - dp2[b]) * ipow[tree.depth[b] + 1]);
  }
  mint from_hld_pair(int a, int b) {
    if (a <= b) { return get_ud(tree.parent[tree.V[a]], tree.V[b]); }
    return get_du(tree.V[a], tree.parent[tree.V[b]]);
  }
};
