#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "graph/ds/rolling_hash_on_tree.hpp"
#include "random/random_graph.hpp"

void test_edge() {
  ll N = RNG(1, 20);
  auto edges = random_tree(N);
  Graph<int, 0> G(N);
  for (auto& [a, b]: edges) {
    int x = RNG(0, 3);
    G.add(a, b, x);
  }
  G.build();
  Tree<decltype(G)> tree(G);

  using mint = modint61;
  mint base = RNG_64();

  Rolling_Hash_On_Tree<decltype(tree), true> RH(
      tree, [&](int i) -> int { return G.edges[i].cost; }, base);

  vvv(int, dat, N, N, 0);
  FOR(a, N) FOR(b, N) {
    vc<int> P = tree.restore_path(a, b);
    vc<int> S;
    FOR(i, len(P) - 1) {
      int eid = tree.get_eid(P[i], P[i + 1]);
      S.eb(G.edges[eid].cost);
    }
    dat[a][b] = S;
  }

  FOR(a, N) FOR(b, N) {
    mint h = 0;
    for (auto& x: dat[a][b]) { h = h * base + x; }
    assert(h == RH.get(a, b));
  }
  FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) {
    vc<int> A = dat[a][b], B = dat[c][d];
    int lcp = 0;
    while (lcp < len(A) && lcp < len(B) && A[lcp] == B[lcp]) ++lcp;
    auto [k, ch] = RH.lcp_and_comp(a, b, c, d);
    assert(k == lcp);
    if (ch == '<') assert(A < B);
    if (ch == '=') assert(A == B);
    if (ch == '>') assert(A > B);
  }
}

void test_vertex() {
  ll N = RNG(1, 20);
  auto edges = random_tree(N);
  Graph<int, 0> G(N);
  for (auto& [a, b]: edges) { G.add(a, b); }
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(0, 3);
  G.build();
  Tree<decltype(G)> tree(G);

  using mint = modint61;
  mint base = RNG_64();

  Rolling_Hash_On_Tree<decltype(tree), false> RH(
      tree, [&](int i) -> int { return A[i]; }, base);

  vvv(int, dat, N, N, 0);
  FOR(a, N) FOR(b, N) {
    vc<int> P = tree.restore_path(a, b);
    vc<int> S;
    for (auto& v: P) S.eb(A[v]);
    dat[a][b] = S;
  }

  FOR(a, N) FOR(b, N) {
    mint h = 0;
    for (auto& x: dat[a][b]) { h = h * base + x; }
    assert(h == RH.get(a, b));
  }

  FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) {
    vc<int> A = dat[a][b], B = dat[c][d];
    int lcp = 0;
    while (lcp < len(A) && lcp < len(B) && A[lcp] == B[lcp]) ++lcp;
    auto [k, ch] = RH.lcp_and_comp(a, b, c, d);
    assert(k == lcp);
    if (ch == '<') assert(A < B);
    if (ch == '=') assert(A == B);
    if (ch == '>') assert(A > B);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(300) test_edge();
  FOR(300) test_vertex();
  solve();
}
