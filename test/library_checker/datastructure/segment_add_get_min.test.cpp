#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/dynamic_lichao.hpp"

void solve() {
  LL(N, Q);
  Dynamic_LiChao_Tree<ll, 0, 15'000'000, 1> X(-infty<int>, infty<int>);
  using np = decltype(X)::np;
  np root = X.new_root();
  FOR(N) {
    LL(l, r, a, b);
    root = X.add_segment(root, l, r, {a, b});
  }
  vc<int> points;
  FOR(Q) {
    INT(t);
    if (t == 0) {
      LL(l, r, a, b);
      root = X.add_segment(root, l, r, {a, b});
    }
    if (t == 1) {
      INT(x);
      auto [fval, fid] = X.query(root, x);
      if (fid == -1) print("INFINITY");
      if (fid != -1) print(fval);
    }
  }
}

signed main() {
  solve();
  return 0;
}
