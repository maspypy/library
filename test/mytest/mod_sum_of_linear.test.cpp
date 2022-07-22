#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/random.hpp"

#include "mod/mod_sum_of_linear.hpp"

void test() {
  RandomNumberGenerator RNG;
  FOR(100) {
    int L = RNG(1000);
    int R = RNG(1000);
    if (L > R) swap(L, R);
    int a = RNG(-1000, 1000);
    int b = RNG(-1000, 1000);
    int mod = RNG(1, 1000);

    ll ANS = 0;
    FOR(x, L, R) {
      ll v = a * x + b;
      v %= mod;
      if (v < 0) v += mod;
      ANS += v;
    }
    assert(ANS == mod_sum_of_linear(L, R, a, b, mod));
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
