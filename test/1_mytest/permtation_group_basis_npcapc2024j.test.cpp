#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "seq/permutation_group_basis.hpp"
#include "mod/modint.hpp"
#include "string/split.hpp"

using mint = modint998;

mint mysolve(vvc<int> A) {
  int N = len(A[0]), M = len(A);
  FOR(i, M) FOR(j, N)-- A[i][j];
  Permutation_Group_Basis<30> P(N, A);

  mint ANS = 0;
  // FOR(i, N) {
  //   for (auto& X: P.Basis[i]) { SHOW(i, X); }
  // }

  FOR(a, N) {
    // (a, a より大きい要素) の場所を追跡
    vv(mint, dp, N, N);
    FOR(b, a + 1, N) dp[a][b] = 1;
    FOR_R(i, N) {
      vv(mint, newdp, N, N);
      for (auto& X: P.Basis[i]) {
        FOR(a, N) FOR(b, N) { newdp[X[a]][X[b]] += dp[a][b]; }
      }
      swap(dp, newdp);
    }
    FOR(i, N) FOR(j, i) ANS += dp[i][j];
  }
  return ANS;
}

void test_sample_1() {
  vv(int, A, 2, 3);
  A[0] = {1, 2, 3};
  A[1] = {2, 3, 1};
  assert(mysolve(A) == mint(4));
}

void test_sample_2() {
  vv(int, A, 2, 5);
  A[0] = {3, 4, 5, 1, 2};
  A[1] = {1, 5, 4, 3, 2};
  assert(mysolve(A) == mint(50));
}

void test_sample_3() {
  vv(int, A, 12, 30);
  auto from_text = [&](string txt) -> vc<int> {
    vc<int> row;
    for (auto& x: split(txt, " ")) row.eb(stoi(x));
    return row;
  };
  A[0] = from_text("1 2 9 4 5 6 7 8 3 10 11 12 19 14 15 25 17 18 20 26 21 22 23 24 16 29 27 28 13 30");
  A[1] = from_text("9 2 27 4 5 10 7 8 1 25 11 12 24 14 15 16 17 18 19 20 21 22 23 28 6 26 3 13 29 30");
  A[2] = from_text("1 5 3 29 2 6 7 8 9 10 11 12 13 16 15 18 17 14 19 20 21 22 28 27 25 26 24 23 4 30");
  A[3] = from_text("7 2 3 25 5 6 1 28 21 15 11 12 13 14 10 17 16 18 19 20 9 22 23 24 4 26 27 8 29 30");
  A[4] = from_text("1 2 5 4 16 6 7 8 9 11 10 3 13 14 15 12 17 23 19 20 21 29 18 24 25 26 27 28 22 30");
  A[5] = from_text("19 24 3 4 1 6 7 8 9 10 11 12 13 21 15 16 17 18 5 22 20 14 23 2 25 26 27 28 29 30");
  A[6] = from_text("1 2 3 4 5 6 27 8 9 10 29 12 24 14 15 16 17 18 30 20 7 22 13 23 25 26 21 28 11 19");
  A[7] = from_text("1 2 25 4 5 6 7 8 9 20 23 12 13 14 15 16 17 18 19 10 29 22 3 24 11 26 27 28 30 21");
  A[8] = from_text("1 2 16 4 5 6 3 8 9 10 11 12 22 29 13 7 17 18 19 20 21 15 23 24 14 26 27 28 25 30");
  A[9] = from_text("1 13 3 4 5 6 21 8 24 10 7 12 20 14 15 16 17 2 19 18 11 22 23 9 25 26 27 28 29 30");
  A[10] = from_text("1 2 3 4 5 6 25 8 9 19 11 12 13 7 10 16 21 18 15 20 17 22 23 24 28 26 27 14 29 30");
  A[11] = from_text("1 2 27 21 5 6 7 8 9 10 18 24 13 14 15 16 17 12 19 11 4 22 23 20 25 26 3 28 29 30");
  assert(mysolve(A) == mint(701414999));
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_sample_1();
  test_sample_2();
  test_sample_3();
  solve();
  return 0;
}
