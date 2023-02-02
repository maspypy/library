#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

void solve() {
  LL(N, Q);
  using T = tuple<int, int, ll>;
  vc<T> query;
  query.reserve(N + Q);
  FOR(N) {
    LL(a, b);
    query.eb(0, a, b);
  }
  vc<int> points;
  FOR(Q) {
    INT(t);
    if (t == 0) {
      LL(a, b);
      query.eb(0, a, b);
    }
    if (t == 1) {
      INT(x);
      query.eb(1, x, 0);
      points.eb(x);
    }
  }
  LiChao_Tree<ll, 1, 1> X(points);
  for (auto&& [t, a, b]: query) {
    if (t == 0) X.add_line({a, b});
    if (t == 1) print(X.query(a).fi);
  }
}

signed main() {
  solve();
  return 0;
}
