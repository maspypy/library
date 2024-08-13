#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "seq/famous/stirling_number_1.hpp"

void test(ll n) {
  using mint = modint998;
  vc<mint> A = stirling_number_1_n<mint>(n);
  vc<mint> B = stirling_number_1_suffix<mint>(n, n);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
int main() {
  FOR(n, 1, 100) test(n);
  solve();
}
