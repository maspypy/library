#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "random/shuffle.hpp"

#include "convex/nth_element_from_sorted_lists.hpp"

void test() {
  ll N = RNG(1, 20);
  vi S(N);
  FOR(i, N) S[i] = RNG(0, 20);
  vvc<int> dat(N);
  vc<int> A;
  FOR(i, N) FOR(S[i]) A.eb(i);
  shuffle(A);
  FOR(p, len(A)) dat[A[p]].eb(p);
  int K = RNG(0, SUM<ll>(S) + 1);

  set<pair<int, int>> st;
  auto f = [&](int i, int j) -> int { return dat[i][j]; };
  vi L = nth_element_from_sorted_lists<int>(S, K, f);
  FOR(i, N) {
    FOR(j, L[i]) { assert(dat[i][j] < K); }
    FOR(j, L[i], len(dat[i])) { assert(dat[i][j] >= K); }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(500000) test();
  solve();
  return 0;
}