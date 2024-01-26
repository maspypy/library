#include "ds/fenwicktree/fenwicktree.hpp"

struct FenwickTree_01 {
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

  template <typename F>
  void build(int m, F f) {
    N = m;
    n = ceil<int>(N + 1, 64);
    dat.assign(n, u64(0));
    FOR(i, N) { dat[i / 64] |= u64(1) << (i % 64); }
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

  void add(int k, int x) {
    if (x == 1) add(k);
    if (x == -1) remove(k);
  }

  void add(int k) {
    dat[k / 64] |= u64(1) << (k % 64);
    bit.add(k / 64, 1);
  }
  void remove(int k) {
    dat[k / 64] &= ~(u64(1) << (k % 64));
    bit.add(k / 64, -1);
  }
};