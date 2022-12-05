#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/dynamic_unionfind.hpp"

void solve() {
  LL(N, Q);

  Dynamic_UnionFind<true, 1'500'000> uf;
  using np = typename decltype(uf)::np;
  vc<np> roots;

  roots.eb(uf.new_node());

  FOR(Q) {
    LL(t, k, u, v);
    ++k;
    auto root = roots[k];
    if (t == 0) {
      root = uf.merge(root, u, v).se;
    } else {
      bool ok = uf.root(root, u) == uf.root(root, v);
      print(ok ? 1 : 0);
    }
    roots.eb(root);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
