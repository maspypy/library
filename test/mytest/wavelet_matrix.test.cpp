#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"
#include "random/base.hpp"

void test_compress() {
  int N = RNG(1, 64);
  int MAX = RNG(2, 1 << 10);
  vc<int> A(N);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(MAX);
  FOR(i, N) A[i] = RNG(MAX);

  Wavelet_Matrix<int, true> WM(A, X);

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
    vc<int> Y = {X.begin() + L, X.begin() + R};

    int t = RNG(0, 5);
    if (t == 0) { // count
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) cnt += 1;
      assert(WM.count(L, R, lo, hi) == cnt);
    }
    if (t == 1) { // sm
      int sm = 0;
      int k1 = RNG(R - L + 1);
      int k2 = RNG(R - L + 1);
      if (k1 > k2) swap(k1, k2);
      auto I = argsort(B);
      FOR(i, k1, k2) sm += Y[I[i]];
      assert(WM.sum(L, R, k1, k2) == sm);
    }
    if (t == 2) { // kth
      int k = RNG(R - L);
      sort(all(B));
      assert(WM.kth(L, R, k) == B[k]);
    }
    if (t == 3) { // max_right
      int a = RNG(0, 10);
      int b = RNG(0, 10);
      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);
      auto check
          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };
      auto p = WM.max_right(check, L, R);
      int k = binary_search(
          [&](int k) -> bool {
            int sm = WM.sum(L, R, 0, k);
            return check(k, sm);
          },
          0, R - L + 1);
      int sm = WM.sum(L, R, 0, k);
      assert(p.fi == k && p.se == sm);
    }
    if (t == 4) { // k-th value and sum
      int k = RNG(0, R - L + 1);
      B.eb(infty<int>);
      auto I = argsort(B);
      int val = B[I[k]];
      int sm = 0;
      FOR(i, k) sm += Y[I[i]];
      auto p = WM.kth_value_and_sum(L, R, k);
      assert(p.fi == val && p.se == sm);
    }
  }
}

void test_not_compress() {
  int N = RNG(1, 64);
  int log = RNG(1, 7);
  int MAX = 1 << log;
  vc<int> A(N);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(0, MAX);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix<int, false> WM(A, X, log);

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
    vc<int> Y = {X.begin() + L, X.begin() + R};
    for (auto&& x: B) x ^= xor_val;

    int t = RNG(0, 5);
    if (t == 0) { // count
      int cnt = 0;
      for (auto&& x: B) {
        if (lo <= x && x < hi) cnt += 1;
      }
      assert(WM.count(L, R, lo, hi, xor_val) == cnt);
    }
    if (t == 1) { // sm
      int sm = 0;
      int k1 = RNG(R - L + 1);
      int k2 = RNG(R - L + 1);
      if (k1 > k2) swap(k1, k2);
      auto I = argsort(B);
      FOR(i, k1, k2) sm += Y[I[i]];
      assert(WM.sum(L, R, k1, k2, xor_val) == sm);
    }
    if (t == 2) { // kth
      int k = RNG(R - L);
      sort(all(B));
      assert(WM.kth(L, R, k, xor_val) == B[k]);
    }
    if (t == 3) { // max_right
      int a = RNG(0, 10);
      int b = RNG(0, 10);
      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);
      auto check
          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };
      auto p = WM.max_right(check, L, R, xor_val);
      int k = binary_search(
          [&](int k) -> bool {
            int sm = WM.sum(L, R, 0, k, xor_val);
            return check(k, sm);
          },
          0, R - L + 1);
      int sm = WM.sum(L, R, 0, k, xor_val);
      assert(k == p.fi && sm == p.se);
    }
    if (t == 4) { // k-th value and sum
      int k = RNG(0, R - L + 1);
      B.eb(infty<int>);
      auto I = argsort(B);
      int val = B[I[k]];
      int sm = 0;
      FOR(i, k) sm += Y[I[i]];
      auto p = WM.kth_value_and_sum(L, R, k, xor_val);
      assert(p.fi == val && p.se == sm);
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
