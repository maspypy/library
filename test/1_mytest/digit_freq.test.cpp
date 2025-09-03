#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "nt/digit_frequency.hpp"

void test() {
  array<ll, 10> X{};
  FOR(N, 1, 1 << 24) {
    auto ANS = digit_frequency(1, N);
    assert(X == ANS);
    string S = to_string(N);
    for (auto& ch : S) X[ch - '0']++;
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
}