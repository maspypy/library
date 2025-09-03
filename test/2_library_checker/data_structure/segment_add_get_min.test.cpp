#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/dynamic_lichao.hpp"

struct F {
  using value_type = ll; // operator() の戻り値
  int a;
  ll b;
  ll operator()(ll x) { return a * x + b; }
};

void solve() {
  LL(N, Q);
  Dynamic_LiChao_Tree<F, 0, 20'000'000, 1> X(-infty<int>, infty<int>);
  using np = decltype(X)::np;
  np root = X.new_root();
  FOR(N) {
    LL(l, r, a, b);
    root = X.chmin_segment(root, l, r, {int(a), b});
  }
  vc<int> points;
  FOR(Q) {
    INT(t);
    if (t == 0) {
      LL(l, r, a, b);
      root = X.chmin_segment(root, l, r, {int(a), b});
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
