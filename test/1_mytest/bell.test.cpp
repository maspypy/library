#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "seq/famous/stirling_number_2.hpp"
#include "seq/famous/bell_number_large.hpp"

void test() {
  const int P = 13, N = 100;
  using mint = modint<P>;
  auto S = stirling_number_2_2d<mint>(N, N);
  vc<mint> B(N);
  FOR(i, N) B[i] = SUM<mint>(S[i]);
  FOR(i, N) { assert(B[i] == Bell_Number_large<mint>(i)); }
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
