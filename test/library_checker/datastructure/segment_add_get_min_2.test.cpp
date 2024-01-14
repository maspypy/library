#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

struct F {
  using value_type = ll; // operator() の戻り値
  int a;
  ll b;
  ll operator()(ll x) { return a * x + b; }
};

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
  LiChao_Tree<F, 1, 1> X(points, {0, infty<ll>});
  for (auto&& [t, l, r, a, b]: query) {
    if (t == 0) X.add_segment(l, r, {a, b});
    if (t == 1) {
      auto [fx, f] = X.query(l);
      if (fx == infty<ll>)
        print("INFINITY");
      else
        print(fx);
    }
  }
}

signed main() {
  solve();
  return 0;
}
