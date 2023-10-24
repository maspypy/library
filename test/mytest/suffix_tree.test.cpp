#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "string/suffix_tree.hpp"
#include "alg/monoid/min_idx.hpp"
#include "ds/segtree/segtree.hpp"
#include "graph/base.hpp"

// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
// 各ノードは、suffix array での長方形領域と見なして、
// グラフおよび、領域データを作る。
// sample: test/my_test/suffix_tree.test.cpp
template <typename SUFFIX>
pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> suffix_tree_old(SUFFIX& X) {
  auto SA = X.SA;
  auto ISA = X.ISA;
  auto LCP = X.LCP;

  int N = len(SA);

  using Mono = Monoid_Min_Idx<int, 1>;

  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X { return {LCP[i], i}; });

  using T = tuple<int, int, int, int>;
  vc<T> dat;
  dat.eb(0, N, 0, 0);
  vc<pair<int, int>> edges;

  auto dfs = [&](auto& dfs, int p, int l, int r, int h) -> void {
    if (r == l + 1) {
      int i = SA[l];
      int sz = N - i;
      if (h == sz) return;
      int k = len(dat);
      dat.eb(l, l + 1, h, sz);
      edges.eb(p, k);
      return;
    }
    auto [lcp, i] = seg.prod(l, r - 1);
    if (lcp == h) {
      dfs(dfs, p, l, i + 1, h);
      dfs(dfs, p, i + 1, r, h);
      return;
    }
    int k = len(dat);
    dat.eb(l, r, h, lcp);
    edges.eb(p, k);
    dfs(dfs, k, l, r, lcp);
  };
  dfs(dfs, 0, 0, N, 0);

  Graph<int, 1> G(len(dat));
  for (auto&& [a, b]: edges) G.add(a, b);
  G.build();
  return {G, dat};
}

/*
S = aabbabbaa

suffix array
a--------
aa-------
aabbabbaa
abbaa----
abbabbaa-
baa------
babbaa---
bbaa-----
bbabbaa--

suffix tree の node はこの長方形領域を表す
1--------
12-------
123333333
14445----
14446666-
789------
780000---
7112-----
7113-----
*/

void test1() {
  string S = "aabbabbaa";
  Suffix_Array X(S);
  auto [G, dat] = suffix_tree(X);
  using T = tuple<int, int, int, int>;
  auto check_dat = [&](T t, int xl, int xr, int yl, int yr) -> void {
    auto [a, b, c, d] = t;
    assert(a == xl && b == yl && c == xr && d == yr);
  };
  auto check_edge = [&](auto e, int frm, int to) -> void {
    assert(e.frm == frm && e.to == to);
  };
  check_dat(dat[0], 0, 0, 9, 0);
  check_dat(dat[1], 0, 0, 5, 1);
  check_dat(dat[2], 1, 1, 3, 2);
  check_dat(dat[3], 2, 2, 3, 9);
  check_dat(dat[4], 3, 1, 5, 4);
  check_dat(dat[5], 3, 4, 4, 5);
  check_dat(dat[6], 4, 4, 5, 8);
  check_dat(dat[7], 5, 0, 9, 1);
  check_dat(dat[8], 5, 1, 7, 2);
  check_dat(dat[9], 5, 2, 6, 3);
  check_dat(dat[10], 6, 2, 7, 6);
  check_dat(dat[11], 7, 1, 9, 3);
  check_dat(dat[12], 7, 3, 8, 4);
  check_dat(dat[13], 8, 3, 9, 7);
  check_edge(G.edges[0], 0, 1);
  check_edge(G.edges[1], 1, 2);
  check_edge(G.edges[2], 2, 3);
  check_edge(G.edges[3], 1, 4);
  check_edge(G.edges[4], 4, 5);
  check_edge(G.edges[5], 4, 6);
  check_edge(G.edges[6], 0, 7);
  check_edge(G.edges[7], 7, 8);
  check_edge(G.edges[8], 8, 9);
  check_edge(G.edges[9], 8, 10);
  check_edge(G.edges[10], 7, 11);
  check_edge(G.edges[11], 11, 12);
  check_edge(G.edges[12], 11, 13);
}

void test2() {
  FOR(N, 1, 10) {
    FOR(100) {
      int K = RNG(1, 5);
      string S;
      FOR(N) { S += 'a' + (RNG(0, K)); }
      Suffix_Array SA(S);
      auto [G1, dat1] = suffix_tree_old(SA);
      auto [G2, dat2] = suffix_tree(SA);
      assert(dat1 == dat2);
      assert(G1.N == G2.N);
      assert(G1.M == G2.M);
      FOR(i, G1.M) {
        assert(G1.edges[i].frm == G2.edges[i].frm);
        assert(G1.edges[i].to == G2.edges[i].to);
      }
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test1();
  test2();
  solve();
  return 0;
}