#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

struct F {
  using value_type = ll;
  int a;
  ll b;
  ll operator()(ll x) { return a * x + b; }
};

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
  LiChao_Tree<F, 1, 1> X(points, {0, infty<ll>});
  for (auto&& [t, a, b]: query) {
    if (t == 0) X.chmin_line({a, b});
    if (t == 1) print(X.query(a).fi);
  }
}

signed main() {
  solve();
  return 0;
}