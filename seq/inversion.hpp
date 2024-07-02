#pragma once
#include "ds/fenwicktree/fenwicktree_01.hpp"

template <typename T>
ll inversion(vc<T> A) {
  int N = len(A);
  if (A.empty()) return 0;
  ll ANS = 0;
  FenwickTree_01 bit(N);
  auto I = argsort(A);
  for (auto& i: I) {
    ANS += bit.sum_all() - bit.sum(i);
    bit.add(i, 1);
  }
  return ANS;
}

// i 番目：A_i が先頭になるように rotate したときの転倒数
template <typename T, bool SMALL = false>
vi inversion_rotate(vc<T>& A) {
  const int N = len(A);
  if (!SMALL) {
    auto key = A;
    UNIQUE(key);
    for (auto&& x: A) x = LB(key, x);
  }
  ll K = MAX(A) + 1;
  ll ANS = 0;
  FenwickTree<Monoid_Add<int>> bit(K);
  for (auto&& x: A) {
    ANS += bit.sum(x + 1, K);
    bit.add(x, 1);
  }
  vi res(N);
  FOR(i, N) {
    res[i] = ANS;
    ll x = A[i];
    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);
  }
  return res;
}

// inv[i][j] = inversion A[i:j) であるような (N+1, N+1) テーブル
template <typename T>
vvc<int> all_range_inversion(vc<T>& A) {
  int N = len(A);
  vv(int, dp, N + 1, N + 1);
  FOR_R(L, N + 1) FOR(R, L + 2, N + 1) {
    dp[L][R] = dp[L][R - 1] + dp[L + 1][R] - dp[L + 1][R - 1];
    if (A[L] > A[R - 1]) ++dp[L][R];
  }
  return dp;
}

template <typename T>
ll inversion_between(vc<T> A, vc<T> B) {
  int N = len(A);
  map<T, vc<int>> MP;
  FOR(i, N) MP[B[i]].eb(i);
  vc<int> TO(N);
  FOR_R(i, N) {
    auto& I = MP[A[i]];
    if (I.empty()) return -1;
    TO[i] = POP(I);
  }
  return inversion(TO);
}