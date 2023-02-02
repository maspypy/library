#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

void solve() {
  LL(N, Q);
  using T = tuple<int, int, int, int, ll>;
  vc<T> query;
  query.reserve(N + Q);
  FOR(N) {
    LL(l, r, a, b);
    query.eb(0, l, r, a, b);
  }
  vc<int> points;
  FOR(Q) {
    INT(t);
    if (t == 0) {
      LL(l, r, a, b);
      query.eb(0, l, r, a, b);
    }
    if (t == 1) {
      INT(x);
      query.eb(1, x, 0, 0, 0);
      points.eb(x);
    }
  }
  LiChao_Tree<ll, 1, 1> X(points);
  for (auto&& [t, l, r, a, b]: query) {
    if (t == 0) X.add_segment(l, r, {a, b});
    if (t == 1) {
      auto [fval, fid] = X.query(l);
      if (fid == -1) print("INFINITY");
      if (fid != -1) print(fval);
    }
  }
}

signed main() {
  solve();
  return 0;
}
