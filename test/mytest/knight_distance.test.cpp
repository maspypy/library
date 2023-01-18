#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/knight_distance.hpp"

void test() {
  ll LIM = 20;
  map<pi, int> dist;
  deque<pi> que;
  auto add = [&](int x, int y, int d) -> void {
    if (abs(x) > 2 * LIM || abs(y) > 2 * LIM) return;
    pi key = {x, y};
    if (dist.count(key)) return;
    dist[key] = d;
    que.eb(x, y);
  };
  add(0, 0, 0);
  ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
  ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
  while (len(que)) {
    auto [x, y] = POP(que);
    FOR(d, 8) {
      ll nx = x + dx[d], ny = y + dy[d];
      pi key = {x, y};
      add(nx, ny, dist[key] + 1);
    }
  }
  for (auto&& [key, d]: dist) {
    auto [x, y] = key;
    assert(knight_distance(x, y) == d);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
