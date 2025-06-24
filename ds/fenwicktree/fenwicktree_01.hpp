#pragma once

#include "ds/fenwicktree/fenwicktree.hpp"

struct FenwickTree_01 {
  using MX = Monoid_Add<int>;
  int N, n;
  vc<u64> dat;
  FenwickTree<Monoid_Add<int>> bit;
  FenwickTree_01() {}
  FenwickTree_01(int n) { build(n); }
  template <typename F>
  FenwickTree_01(int n, F f) {
    build(n, f);
  }

  void build(int m) {
    N = m;
    n = ceil<int>(N + 1, 64);
    dat.assign(n, u64(0));
    bit.build(n);
  }
  void build(vc<int> dat) {
    build(len(dat), [&](int i) -> int { return dat[i]; });
  }

  template <typename F>
  void build(int m, F f) {
    N = m;
    n = ceil<int>(N + 1, 64);
    dat.assign(n, u64(0));
    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }
    bit.build(n, [&](int i) -> int { return popcnt(dat[i]); });
  }

  int sum_all() { return bit.sum_all(); }
  int sum(int k) { return prefix_sum(k); }
  int prefix_sum(int k) {
    int ans = bit.sum(k / 64);
    ans += popcnt(dat[k / 64] & ((u64(1) << (k % 64)) - 1));
    return ans;
  }
  int sum(int L, int R) {
    if (L == 0) return prefix_sum(R);
    int ans = 0;
    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));
    ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));
    ans += bit.sum(L / 64, R / 64);
    return ans;
  }
  int prod(int L, int R) { return sum(L, R); }

  void add(int k, int x) {
    if (x == 1) add(k);
    elif (x == -1) remove(k);
    else assert(0);
  }
  void multiply(int k, int x) { add(k, x); }

  void add(int k) {
    dat[k / 64] |= u64(1) << (k % 64);
    bit.add(k / 64, 1);
  }
  void remove(int k) {
    dat[k / 64] &= ~(u64(1) << (k % 64));
    bit.add(k / 64, -1);
  }

  int kth(int k, int L = 0) {
    if (k >= sum_all()) return N;
    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));
    L /= 64;
    int mid = 0;
    auto check = [&](auto e) -> bool {
      if (e <= k) chmax(mid, e);
      return e <= k;
    };
    int idx = bit.max_right(check, L);
    if (idx == n) return N;
    k -= mid;
    u64 x = dat[idx];
    int p = popcnt(x);
    if (p <= k) return N;
    k = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; }, 0, 64, 0);
    return 64 * idx + k;
  }

  int next(int k) {
    int idx = k / 64;
    k %= 64;
    u64 x = dat[idx] & ~((u64(1) << k) - 1);
    if (x) return 64 * idx + lowbit(x);
    idx = bit.kth(0, idx + 1);
    if (idx == n || !dat[idx]) return N;
    return 64 * idx + lowbit(dat[idx]);
  }

  int prev(int k) {
    if (k == N) --k;
    int idx = k / 64;
    k %= 64;
    u64 x = dat[idx];
    if (k < 63) x &= (u64(1) << (k + 1)) - 1;
    if (x) return 64 * idx + topbit(x);
    idx = bit.min_left([&](auto e) -> bool { return e <= 0; }, idx) - 1;
    if (idx == -1) return -1;
    return 64 * idx + topbit(dat[idx]);
  }
};