#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "nt/sigma_0_sum.hpp"

void test() {
  FOR(N, 1, 10000) {
    u64 ans = 0;
    FOR(x, 1, N + 1) ans += N / x;
    assert(ans == sigma_0_sum_small(N));
    assert(ans == sigma_0_sum_large(N));
  }
  u64 N = 1'000'000'000'000'000;
  u64 ANS = 34'693'207'724'724'246; // https://oeis.org/A057494
  u64 a = sigma_0_sum_small(N);
  u64 b = sigma_0_sum_small(N);
  assert(a == ANS && b == ANS);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

int main() {
  test();
  solve();
}
