#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "nt/primesum_mod6.hpp"

void test_count() {
  ll LIM = 10000;
  vc<int> A1(LIM), A5(LIM);
  for (auto&& p: primetable(LIM))
    if (p % 6 == 1) { A1[p]++; }
  for (auto&& p: primetable(LIM))
    if (p % 6 == 5) { A5[p]++; }
  A1 = cumsum<int>(A1, 0);
  A5 = cumsum<int>(A5, 0);

  FOR(N, LIM) {
    PrimeSum_Mod_6<int> X(N);
    X.calc_count();
    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }
  }
}

void test_sum() {
  ll LIM = 10000;
  vc<int> A1(LIM), A5(LIM);
  for (auto&& p: primetable(LIM))
    if (p % 6 == 1) { A1[p] += p; }
  for (auto&& p: primetable(LIM))
    if (p % 6 == 5) { A5[p] += p; }
  A1 = cumsum<int>(A1, 0);
  A5 = cumsum<int>(A5, 0);

  FOR(N, LIM) {
    PrimeSum_Mod_6<int> X(N);
    X.calc_sum();
    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_count();
  test_sum();
  solve();

  return 0;
}
