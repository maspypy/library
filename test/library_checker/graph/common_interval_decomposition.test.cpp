#define PROBLEM \
  "https://judge.yosupo.jp/problem/common_interval_decomposition_tree"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/common_interval_decomposition.hpp"

void solve() {
  LL(N);
  VEC(int, P, N);
  Common_Inverval_Decomposition<1000000> X(P);
  int nxt = 0;
  auto dfs = [&](auto& dfs, auto n, int p) -> void {
    string t = (n->inc || n->dec || (n->r - n->l == 1) ? "linear" : "prime");
    print(p, n->l, n->r - 1, t);
    int v = nxt++;
    for (auto&& c: n->ch) dfs(dfs, c, v);
  };
  print(X.pid);
  dfs(dfs, X.root, -1);
}

signed main() {
  solve();

  return 0;
}