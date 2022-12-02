#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, Q);
  UnionFind uf(N);
  FOR(_, Q) {
    LL(t, a, b);
    if (t == 0) {
      uf.merge(a, b);
    } else {
      print(uf[a] == uf[b]);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
