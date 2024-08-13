#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "nt/pytagorean_triple.hpp"

void test() {
  int LIM = 10000;
  int A = 0, B = 0;
  FOR(y, 1, LIM) {
    FOR(x, 1, y) {
      int z = sqrtl(x * x + y * y);
      if (z > LIM) break;
      if (x * x + y * y != z * z) continue;
      A += 1;
      B += gcd(x, y) == 1;
    }
  }
  enumerate_pytagorean_triple<false>(LIM, [&](int a, int b, int c) -> void {
    assert(0 <= a && a <= b && b <= c && c <= LIM && a * a + b * b == c * c);
    --A;
  });
  enumerate_pytagorean_triple<true>(LIM, [&](int a, int b, int c) -> void {
    assert(0 <= a && a <= b && b <= c && c <= LIM && a * a + b * b == c * c);
    assert(gcd(a, b) == 1);
    --B;
  });
  assert(A == 0 && B == 0);
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