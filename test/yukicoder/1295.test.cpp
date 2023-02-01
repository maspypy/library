#define PROBLEM "https://yukicoder.me/problems/no/1295"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "graph/rerooting_dp.hpp"

/*
部分木の状態：0,1,2
0：ng
1：一方通行
2：ok
*/
void solve() {
  struct Data {
    int x0, x1, x2;
    int x_mi, x_ma;
    int mi, ma;
  };
  Data unit = {0, 0, 0, 2, 2, infty<int>, -infty<int>};
  auto fee = [&](Data x, Data y) -> Data {
    if (x.mi == infty<int>) return y;
    if (y.mi == infty<int>) return x;
    Data z;
    z.x0 = x.x0 + y.x0;
    z.x1 = x.x1 + y.x1;
    z.x2 = x.x2 + y.x2;
    z.mi = min(x.mi, y.mi);
    z.ma = max(x.ma, y.ma);
    z.x_mi = (z.mi == x.mi ? x.x_mi : y.x_mi);
    z.x_ma = (z.ma == x.ma ? x.x_ma : y.x_ma);
    return z;
  };
  auto fev = [&](Data x, int v) -> Data { return x; };

  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data {
    int p = e.to;
    int v = e.frm;
    // print(p, v, ",", x.x0, x.x1, x.x2, x.mi, x.ma, x.x_mi, x.x_ma);
    bool ok = (x.x0 == 0 && x.x1 == 0) && (x.mi > p);
    bool ok_0 = (x.x0 == 0 && x.x1 == 0);
    bool ok_1 = ok;
    bool ok_2 = ok;
    if (x.x0 == 0 && x.x1 == 1 && x.x_mi == 1) {
      if (x.mi < p) ok_1 = 1;
    }
    if (x.x0 == 0 && x.x1 == 1 && x.x_ma == 1) { ok_2 = 1; }
    int s = 0;
    if (ok_0 || ok_1 || ok_2) s = 1;
    if (ok) s = 2;
    x.x0 = (s == 0 ? 1 : 0);
    x.x1 = (s == 1 ? 1 : 0);
    x.x2 = (s == 2 ? 1 : 0);
    x.x_mi = x.x_ma = s;
    x.mi = x.ma = v;
    // print(p, v, ",", x.x0, x.x1, x.x2, x.mi, x.ma, x.x_mi, x.x_ma);
    // print();
    return x;
  };

  LL(N);
  Graph<bool, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  FOR(v, N) {
    auto x = dp[v];
    bool ok = (x.x0 == 0 && x.x1 == 0);
    if (x.x0 == 0 && x.x1 == 1 && x.x_mi == 1) ok = 1;
    if (x.x0 == 0 && x.x1 == 1 && x.x_ma == 1) ok = 1;
    Yes(ok);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
