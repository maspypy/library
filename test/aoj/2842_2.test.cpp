#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree2d_dense.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(H, W, T, Q);
  deque<tuple<ll, ll, ll>> que;
  const ll INF = 1LL << 60;
  vv(ll, time, H, W, INF);

  SegTree2D_dense<Group_Add<ll>> A(H, W);
  SegTree2D_dense<Group_Add<ll>> B(H, W);

  deque<tuple<ll, ll, ll>> end;

  FOR(Q) {
    LL(t, c, x, y);
    --x, --y;
    while (len(end) && get<2>(end.front()) <= t) {
      auto [x, y, t] = end.front();
      end.pop_front();
      A.set(x, y, 1);
      B.set(x, y, 0);
    }
    if (c == 0) {
      B.set(x, y, 1);
      end.eb(x, y, t + T);
    }
    elif (c == 1) {
      if (A.prod(x, x + 1, y, y + 1)) A.set(x, y, 0);
    }
    elif (c == 2) {
      LL(x2, y2);
      print(A.prod(x, x2, y, y2), B.prod(x, x2, y, y2));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
