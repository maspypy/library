#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

void solve() {
  LL(N, Q);
  const int LIM = 1'000'000'000;
  LiChao_Tree<ll, 0, 0, 400'000, 1> X(-LIM, LIM + 1);
  using np = decltype(X)::np;
  np root = X.new_root();
  FOR(N) {
    LL(a, b);
    root = X.add_line(root, {a, b});
  }
  FOR(Q) {
    INT(t);
    if (t == 0) {
      LL(a, b);
      root = X.add_line(root, {a, b});
    }
    if (t == 1) {
      INT(x);
      print(X.query(root, x).fi);
    }
  }
}

signed main() {
  solve();
  return 0;
}
