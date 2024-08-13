#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, Q);
  UnionFind uf(N);
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) {
      uf.merge(a, b);
    } else {
      print(uf[a] == uf[b] ? 1 : 0);
    }
  }
}

signed main() {
  solve();
  return 0;
}
