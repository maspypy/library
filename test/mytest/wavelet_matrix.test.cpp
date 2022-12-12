#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"
#include "random/base.hpp"

void test_compress() {
  int N = RNG(1, 64);
  int MAX = 1 << 10;
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix<int, true> WM(A);

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
    int k = RNG(R - L);
    vc<int> B = {A.begin() + L, A.begin() + R};

    int t = RNG(0, 3);
    if (t == 0) { // freq
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) ++cnt;
      assert(WM.freq(L, R, lo, hi) == cnt);
    }
    if (t == 1) { // freq upper
      int cnt = 0;
      for (auto&& x: B)
        if (x < hi) ++cnt;
      assert(WM.freq_upper(L, R, hi) == cnt);
    }
    if (t == 2) { // kth
      sort(all(B));
      assert(WM.kth(L, R, k) == B[k]);
    }
  }
}

void test_not_compress() {
  int N = RNG(1, 64);
  int MAX = 64;
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix<int, false> WM(A, 6);

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
    int k = RNG(R - L);
    int xor_val = RNG(MAX);
    vc<int> B = {A.begin() + L, A.begin() + R};

    int t = RNG(0, 6);
    if (t == 0) { // freq
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) ++cnt;
      assert(WM.freq(L, R, lo, hi) == cnt);
    }
    if (t == 1) { // freq upper
      int cnt = 0;
      for (auto&& x: B)
        if (x < hi) ++cnt;
      assert(WM.freq_upper(L, R, hi) == cnt);
    }
    if (t == 2) { // kth
      sort(all(B));
      assert(WM.kth(L, R, k) == B[k]);
    }
    if (t == 3) { // xor_freq
      for (auto&& x: B) x ^= xor_val;
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) ++cnt;
      assert(WM.xor_freq(L, R, lo, hi, xor_val) == cnt);
    }
    if (t == 4) { // xor_freq_upper
      for (auto&& x: B) x ^= xor_val;
      int cnt = 0;
      for (auto&& x: B)
        if (x < hi) ++cnt;
      assert(WM.xor_freq_upper(L, R, hi, xor_val) == cnt);
    }
    if (t == 5) { // xor_kth
      for (auto&& x: B) x ^= xor_val;
      sort(all(B));
      assert(WM.xor_kth(L, R, k, xor_val) == B[k]);
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
