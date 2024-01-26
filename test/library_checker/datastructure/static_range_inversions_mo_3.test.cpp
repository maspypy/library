#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_01.hpp"
#include "ds/offline_query/mo.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  auto I = argsort(A);
  vc<int> B(N);
  FOR(i, N) B[I[i]] = i;
  swap(A, B);

  FenwickTree_01 bit(N);

  Mo mo;
  vi ANS(Q);
  FOR(Q) {
    LL(L, R);
    mo.add(L, R);
  }

  ll inv = 0;
  auto add_l = [&](int i) -> void {
    int x = A[i];
    inv += bit.sum(x);
    bit.add(x, +1);
  };
  auto rm_l = [&](int i) -> void {
    int x = A[i];
    bit.add(x, -1);
    inv -= bit.sum(x);
  };
  auto add_r = [&](int i) -> void {
    int x = A[i];
    inv += bit.sum_all() - bit.sum(x + 1);
    bit.add(x, +1);
  };
  auto rm_r = [&](int i) -> void {
    int x = A[i];
    bit.add(x, -1);
    inv -= bit.sum_all() - bit.sum(x + 1);
  };
  auto calc = [&](int i) -> void { ANS[i] = inv; };
  mo.calc(add_l, add_r, rm_l, rm_r, calc);
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();

  return 0;
}
