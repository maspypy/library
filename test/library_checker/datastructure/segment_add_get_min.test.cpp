#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

void solve() {
  LL(N, Q);
  using T = tuple<ll, ll, ll, ll, ll>;
  vc<T> dat(N + Q);
  FOR(i, N) {
    LL(l, r, a, b);
    dat[i] = {0, l, r, a, b};
  }
  vi X;
  FOR3(i, N, N + Q) {
    LL(t);
    if (t == 1) {
      LL(x);
      dat[i] = {1, x, 0, 0, 0};
      X.eb(x);
    } else {
      LL(l, r, a, b);
      dat[i] = {0, l, r, a, b};
    }
  }

  const ll INF = 1LL << 60;
  LiChaoTree<ll> seg(X, INF);
  FOR(i, N + Q) {
    auto [t, l, r, a, b] = dat[i];
    if (t == 0) {
      seg.add(l, r, a, b);
    } else {
      ll y = seg.get_min(l);
      if (y == INF)
        print("INFINITY");
      else
        print(y);
    }
  }
}

signed main() {
  solve();

  return 0;
}
