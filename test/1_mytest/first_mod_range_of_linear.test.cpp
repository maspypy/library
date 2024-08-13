#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/first_mod_range_of_linear.hpp"
#include "random/base.hpp"

ll naive(ll L, ll R, ll a, ll b, ll mod) {
  FOR(x, mod) {
    FOR(y, L, R) {
      if (((a * x + b) - y) % mod == 0) return x;
    }
  }
  return -1;
}

void test() {
  ll K = 15;
  FOR(L, -K, K) {
    FOR(R, L, K) {
      FOR(mod, 1, K) {
        FOR(a, -K, K) {
          FOR(b, -K, K) {
            ll X = naive(L, R, a, b, mod);
            ll Y = first_mod_range_of_linear(L, R, a, b, mod);
            assert(X == Y);
          }
        }
      }
    }
  }

  K = 10000;
  FOR(100) {
    ll L = RNG(-K, K);
    ll R = RNG(-K, K);
    if (L > R) swap(L, R);
    ll mod = RNG(1, K);
    ll a = RNG(-K, K);
    ll b = RNG(-K, K);
    ll X = naive(L, R, a, b, mod);
    ll Y = first_mod_range_of_linear(L, R, a, b, mod);
    assert(X == Y);
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