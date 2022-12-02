#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwick/fenwick.hpp"
#include "ds/offline_query/mo.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  vi key = A;
  UNIQUE(key);

  for (auto&& x: A) x = LB(key, x);
  ll K = len(key);
  FenwickTree<Monoid_Add<int>> bit(K);

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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
