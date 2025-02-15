#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/base.hpp"
#include "mod/mod_log_998244353.hpp"

using mint = modint998;

void test() {
  int mod = 998244353;
  FOR(100000) {
    int a = RNG(1, mod - 1);
    int k = mod_log_998_primitive_root(a);
    int b = mint(3).pow(k).val;
    assert(a == b);
  }
  FOR(100000) {
    int a = RNG(1, mod - 1);
    int b = RNG(1, mod - 1);
    int k = mod_log_998(a, b);
    if (k != -1) {
      int c = mint(a).pow(k).val;
      assert(b == c);
    }
  }
  FOR(100000) {
    int a = RNG(1, mod - 1);
    int k = RNG(0, mod - 2);
    int b = mint(a).pow(k).val;
    k = mod_log_998(a, b);
    assert(k != -1);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() { solve(); }
