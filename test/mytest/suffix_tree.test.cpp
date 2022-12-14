#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffix_tree.hpp"

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
void test() {
  string S = "aabbabbaa";
  SuffixArray X(S);
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

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  test();

  ll T = 1;
  FOR(T) solve();

  return 0;
}