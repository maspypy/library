#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "enumerate/labeled_tree.hpp"
#include "ds/unionfind/unionfind.hpp"

void test(ll N) {
  vvc<pair<int, int>> dat;
  enumerate_labeled_tree(N, [&](vc<pair<int, int>> G) -> void {
    assert(len(G) == N - 1);
    UnionFind uf(N);
    for (auto& [a, b]: G) { uf.merge(a, b); }
    assert(uf.n_comp == 1);
    for (auto& [a, b]: G) {
      if (a > b) swap(a, b);
    }
    sort(all(G));
    dat.eb(G);
  });
  ll K = 1;
  FOR(N - 2) K *= N;
  assert(len(dat) == K);
  UNIQUE(dat);
  assert(len(dat) == K);
}

void solve() {
  int x, y;
  cin >> x >> y;
  cout << x + y << "\n";
}

signed main() {
  FOR(N, 1, 8) test(N);
  solve();
  return 0;
}