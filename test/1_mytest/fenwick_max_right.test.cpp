#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "random/base.hpp"

void test(int N) {
  FenwickTree<Monoid_Add<int>> bit(N);

  FOR(1 << 15) {
    bit.set(RNG(0, N), RNG(0, 10));
    ll s = RNG(0, N + 1);
    ll sm = bit.sum(s, N);
    ll K = RNG(0, 2 * sm + 1);
    {
      ll god = bit.max_right([&](ll x) -> bool { return x <= K; }, s);
      ll ans = binary_search([&](ll r) -> bool { return bit.prod(s, r) <= K; },
                             s, N + 1);
      assert(god == ans);
    }
  }

  FOR(1 << 15) {
    bit.set(RNG(0, N), RNG(0, 10));
    ll s = RNG(0, N + 1);
    ll sm = bit.sum(s, N);
    ll K = s + RNG(0, 2 * sm + 1);
    {
      ll god = bit.max_right_with_index(
          [&](ll i, ll x) -> bool { return i + x <= K; }, s);
      ll ans = binary_search(
          [&](ll r) -> bool { return r + bit.prod(s, r) <= K; }, s, N + 1);
      assert(god == ans);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(N, 1, 100) test(N);
  solve();
}
