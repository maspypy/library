#define PROBLEM "https://yukicoder.me/problems/no/1002"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/centroid.hpp"

void solve() {
  LL(N, K);
  Graph<int> G(N);
  G.read_tree(1);

  using T = pi;
  // -1 : no color
  // -2 : many color
  auto f = [&](T t, auto e) -> T {
    ll c = e.cost;
    if (t.fi == -2) return t;
    if (t.fi == c || t.se == c) return t;
    if (t.fi == -1) t.fi = c;
    elif (t.se == -1) t.se = c;
    else t = {-2, -2};
    if (t.se >= 0 && t.fi > t.se) swap(t.fi, t.se);
    return t;
  };

  Centroid_Decomposition<Graph<int>> CD(G);

  ll ANS = 0;
  FOR(root, N) {
    auto dats = CD.collect<T>(root, {-1, -1}, f);
    FOR(i, len(dats)) {
      auto& dat = dats[i];
      ll x0 = 0, x1 = 0, x2 = 0;
      map<ll, ll> MP1;
      map<pi, ll> MP2;
      for (auto&& [v, p]: dat) {
        if (p.fi == -2) continue;
        if (p.fi == -1) x0 += 1;
        elif (p.se < 0) {
          ++x1;
          MP1[p.fi]++;
        }
        else {
          ++x2;
          MP2[p]++;
        }
      }
      ll x00 = 0, x01 = 0, x02 = 0, x11 = 0, x12 = 0, x22 = 0;
      x00 = x0 * x0;
      x01 = 2 * x0 * x1;
      x02 = 2 * x0 * x2;
      for (auto&& [v, p]: dat) {
        if (p.fi < 0) continue;
        if (p.se < 0) {
          x11 += x1 - MP1[p.fi];
        } else {
          x12 += 2 * MP1[p.fi];
          x12 += 2 * MP1[p.se];
          x22 += MP2[p];
        }
      }
      // ll x = x00 + x01 + x02 + x11 + x12 + x22;
      ll x = x02 + x11 + x12 + x22;
      ANS += (i == 0 ? x : -x);
    }
  }
  print(ANS / 2);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
