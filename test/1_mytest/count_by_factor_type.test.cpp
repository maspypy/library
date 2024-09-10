#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "nt/count_by_factor_type.hpp"
#include "nt/factor.hpp"

void test() {
  map<vc<int>, ll> god;
  FOR(N, 1, 1000) {
    vc<int> S;
    for (auto& [p, e]: factor(N)) S.eb(e);
    sort(all(S));
    reverse(all(S));
    god[S]++;
    map<vc<int>, ll> ans = count_by_factor_type(N);
    assert(god == ans);
  }
}

void solve() {
  int x, y;
  cin >> x >> y;
  cout << x + y << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}