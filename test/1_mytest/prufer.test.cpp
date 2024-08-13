#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "enumerate/product.hpp"
#include "graph/prufer_code.hpp"

void test(int n) {
  /*
  F: 列 -> 木
  G: 木 -> 列
  ・写像になっていること
  ・GF(A)=A
  これが示されれば、個数が等しいことは知っているので全単射がいえる
  */
  enumerate_product(vc<int>(n - 1, n), [&](vc<int> A) -> void {
    if (n >= 2 && A.back() != n - 1) return;
    Graph<int, 0> G = from_prufer_code(A);
    UnionFind uf(n);
    for (auto& e: G.edges) assert(uf.merge(e.frm, e.to));
    assert(uf.n_comp == 1);
    vc<int> B = to_prufer_code(G);
    assert(A == B);
  });
}

void solve() {
  int x, y;
  cin >> x >> y;
  cout << x + y << "\n";
}

signed main() {
  FOR(n, 2, 8) test(n);
  solve();
  return 0;
}