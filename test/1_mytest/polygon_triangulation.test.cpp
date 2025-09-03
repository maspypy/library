#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_polygon.hpp"
#include "geo/polygon_triangulation.hpp"

void test() {
  auto check = [&](vc<Point<ll>> point) -> void {
    int N = len(point);
    auto dat = polygon_triangulation(point);
    assert(len(dat) == N - 2);
    // 簡易テスト. 面積和がいい感じの N-2 個になってればいいことにする.
    ll AREA = 0, AREA3 = 0;
    FOR(i, N) AREA += point[i].det(point[(i + 1) % N]);
    for (auto& [a, b, c]: dat) {
      ll S = (point[b] - point[a]).det(point[c] - point[a]);
      assert(S > 0);
      AREA3 += S;
    }
    assert(AREA == AREA3);
  };

  FOR(10000) {
    int N = RNG(3, 20);
    int K = RNG(3, 10);
    vc<Point<ll>> point = random_polygon(N, K);
    check(point);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
