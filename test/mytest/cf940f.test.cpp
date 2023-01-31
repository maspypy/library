#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/mo_3d.hpp"

using T = tuple<int, int, int>;

// https://codeforces.com/contest/940/problem/F
vc<int> solve_CF940F(int N, int Q, vc<int> A, vc<T> query) {
  vc<int> X;
  for (auto&& x: A) X.eb(x);
  for (auto&& [t, a, b]: query) {
    --a;
    if (t == 2) X.eb(b);
  }
  UNIQUE(X);
  for (auto&& x: A) x = LB(X, x);
  for (auto&& [t, a, b]: query) {
    if (t == 2) b = LB(X, b);
  }

  vc<T> change;
  vc<int> A0 = A;

  Q = 0;

  Mo_3d mo;
  for (auto&& [t, a, b]: query) {
    if (t == 1) {
      mo.add_query(len(change), a, b);
      ++Q;
    }
    if (t == 2) {
      change.eb(a, A[a], b);
      A[a] = b;
    }
  }
  A = A0;

  vc<int> CNT_1(len(X));
  vc<int> CNT_2(N + 1);
  CNT_2[0] = 1 << 30;
  vc<int> ANS(Q);

  auto ADD_ELEM = [&](int x, int cnt) -> void {
    int& n = CNT_1[x];
    CNT_2[n]--, n += cnt, CNT_2[n]++;
  };

  auto ADD = [&](int i) -> void { ADD_ELEM(A[i], 1); };
  auto RM = [&](int i) -> void { ADD_ELEM(A[i], -1); };
  auto ADD_CHANGE = [&](int t, int l, int r) -> void {
    auto [i, a, b] = change[t];
    if (l <= i && i < r) { ADD_ELEM(a, -1), ADD_ELEM(b, 1); }
    A[i] = b;
  };
  auto RM_CHANGE = [&](int t, int l, int r) -> void {
    auto [i, a, b] = change[t];
    if (l <= i && i < r) { ADD_ELEM(b, -1), ADD_ELEM(a, +1); }
    A[i] = a;
  };
  auto CALC = [&](int q) -> void {
    int mex = 0;
    while (CNT_2[mex]) ++mex;
    ANS[q] = mex;
  };

  mo.calc(ADD, ADD, RM, RM, ADD_CHANGE, RM_CHANGE, CALC);
  return ANS;
}

void test_CF940F() {
  int N = 10, Q = 4;
  vc<int> A = {1, 2, 3, 1, 1, 2, 2, 2, 9, 9};
  vc<T> query;
  query.eb(1, 1, 1);
  query.eb(1, 2, 8);
  query.eb(2, 7, 1);
  query.eb(1, 2, 8);
  auto ANS = solve_CF940F(N, Q, A, query);
  assert(ANS == vc<int>({2, 3, 2}));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_CF940F();
  solve();
  return 0;
}