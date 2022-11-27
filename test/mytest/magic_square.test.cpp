#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/magic_square.hpp"

void test() {
  vc<int> ns = {1, 3, 5, 7, 9};

  for (auto&& N: ns) {
    auto A = magic_square(N);
    vc<int> SM;
    FOR(i, N) {
      ll sm = 0;
      FOR(j, N) sm += A[i][j];
      SM.eb(sm);
    }
    FOR(j, N) {
      ll sm = 0;
      FOR(i, N) sm += A[i][j];
      SM.eb(sm);
    }
    ll sm1 = 0, sm2 = 0;
    FOR(i, N) {
      sm1 += A[i][i];
      sm2 += A[i][N - 1 - i];
    }
    SM.eb(sm1);
    SM.eb(sm2);
    assert(MIN(SM) == MAX(SM));
    vc<int> done(N * N + 1);
    FOR(i, N) FOR(j, N) done[A[i][j]] = 1;
    assert(SUM<int>(done) = N * N);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}