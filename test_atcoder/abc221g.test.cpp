#define PROBLEM "https://atcoder.jp/contests/abc221/tasks/abc221_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "knapsack/subset_sum.hpp"

void solve() {
  LL(N, A, B);
  VEC(int, D, N);
  ll PLUS = A + B;
  ll MINUS = A - B;
  ll SM = SUM<int>(D);
  if ((PLUS + SM) % 2 != 0) return No();
  PLUS = (PLUS + SM) / 2;
  MINUS = (MINUS + SM) / 2;
  if (PLUS < 0 || SM < PLUS) return No();
  if (MINUS < 0 || SM < MINUS) return No();
  auto X = subset_sum(D, PLUS);
  auto Y = subset_sum(D, MINUS);
  if (PLUS != 0 && len(X) == 0) return No();
  if (MINUS != 0 && len(Y) == 0) return No();
  Yes();
  vi ANS(N);
  for (auto&& x: X) ANS[x] |= 1;
  for (auto&& y: Y) ANS[y] |= 2;
  string S;
  string cmd = "LUDR";
  FOR(i, N) { S += cmd[ANS[i]]; }
  print(S);
}

signed main() {
  solve();

  return 0;
}