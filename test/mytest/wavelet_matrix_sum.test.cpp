#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix_sum.hpp"
#include "random/base.hpp"

void test_compress() {
  int N = RNG(1, 64);
  int MAX = RNG(2, 1 << 10);
  vc<int> A(N);
  vc<int> add_val(MAX);
  FOR(i, MAX) add_val[i] = RNG(0, MAX);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix_Sum<int, true> WM([&](int x) -> int { return add_val[x]; }, A);
  using P = pair<int, int>;

  int Q = 100;
  FOR(Q) {
    int L = RNG(0, N);
    int R = RNG(0, N);
    if (L > R) swap(L, R);
    ++R;
    int lo = RNG(0, MAX);
    int hi = RNG(0, MAX);
    if (lo > hi) swap(lo, hi);
    ++hi;
    vc<int> B = {A.begin() + L, A.begin() + R};

    int t = RNG(0, 5);
    if (t == 0) { // count
      int cnt = 0, sm = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) cnt += 1, sm += add_val[x];
      assert(WM.count(L, R, lo, hi) == P({cnt, sm}));
    }
    if (t == 1) { // count_prefix
      int cnt = 0, sm = 0;
      for (auto&& x: B)
        if (x < hi) ++cnt, sm += add_val[x];
      assert(WM.count_prefix(L, R, hi) == P({cnt, sm}));
    }
    if (t == 2) { // kth
      int k = RNG(R - L + 1);
      sort(all(B));
      B.eb(WM.INF);
      int sm = 0;
      FOR(i, k) sm += add_val[B[i]];
      assert(WM.kth(L, R, k) == P({B[k], sm}));
    }
    if (t == 3) { // max_right_value
      int sm = RNG(0, MAX * (R - L) + 1);
      int val = WM.max_right_value([&](int e) { return e <= sm; }, L, R);
      int val2 = binary_search(
          [&](int val) -> bool { return WM.count_prefix(L, R, val).se <= sm; },
          0, MAX + 1);
      if (val2 == MAX) val2 = WM.INF;
      assert(val == val2);
    }

    if (t == 4) { // max_right_count
      int sm = RNG(0, MAX * (R - L) + 1);
      int k = WM.max_right_count([&](int e) { return e <= sm; }, L, R);
      int k2 = binary_search(
          [&](int k) -> bool { return WM.kth(L, R, k).se <= sm; }, 0,
          R - L + 1);
      assert(k == k2);
    }
  }
}

void test_not_compress() {
  int N = RNG(1, 64);
  int log = RNG(1, 7);
  int MAX = 1 << log;
  vc<int> A(N);
  vc<int> add_val(MAX);
  FOR(i, MAX) add_val[i] = RNG(0, MAX);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix_Sum<int, false> WM([&](int x) { return add_val[x]; }, A, log);
  using P = pair<int, int>;

  int Q = 100;
  FOR(Q) {
    int L = RNG(0, N);
    int R = RNG(0, N);
    if (L > R) swap(L, R);
    ++R;
    int lo = RNG(0, MAX);
    int hi = RNG(0, MAX);
    int xor_val = RNG(0, MAX);
    if (lo > hi) swap(lo, hi);
    ++hi;
    vc<int> B = {A.begin() + L, A.begin() + R};

    int t = RNG(0, 5);
    if (t == 0) { // count
      int cnt = 0, sm = 0;
      for (auto&& x: B) {
        int y = x ^ xor_val;
        if (lo <= y && y < hi) cnt += 1, sm += add_val[x];
      }
      assert(WM.count(L, R, lo, hi, xor_val) == P({cnt, sm}));
    }
    if (t == 1) { // count_prefix
      int cnt = 0, sm = 0;
      for (auto&& x: B) {
        int y = x ^ xor_val;
        if (y < hi) cnt += 1, sm += add_val[x];
      }
      assert(WM.count_prefix(L, R, hi, xor_val) == P({cnt, sm}));
    }
    if (t == 2) { // kth
      int k = RNG(R - L + 1);
      for (auto&& x: B) x ^= xor_val;
      sort(all(B));
      B.eb(WM.INF);
      int sm = 0;
      FOR(i, k) sm += add_val[B[i] ^ xor_val];
      assert(WM.kth(L, R, k, xor_val) == P({B[k], sm}));
    }
    if (t == 3) { // max_right_value
      int sm = RNG(0, MAX * (R - L) + 1);
      int val
          = WM.max_right_value([&](int e) { return e <= sm; }, L, R, xor_val);
      int val2 = binary_search(
          [&](int val) -> bool {
            return WM.count_prefix(L, R, val, xor_val).se <= sm;
          },
          0, MAX + 1);
      if (val2 == MAX) val2 = WM.INF;
      assert(val == val2);
    }
    if (t == 4) { // max_right_count
      int sm = RNG(0, MAX * (R - L) + 1);
      int k = WM.max_right_count([&](int e) { return e <= sm; }, L, R, xor_val);
      int k2 = binary_search(
          [&](int k) -> bool { return WM.kth(L, R, k, xor_val).se <= sm; }, 0,
          R - L + 1);
      assert(k == k2);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  FOR(1000) test_compress();
  FOR(1000) test_not_compress();
  solve();

  return 0;
}
