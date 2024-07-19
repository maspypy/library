#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"

template <typename Monoid>
struct Static_Range_Sum {
  using MX = Monoid;
  using X = Monoid::value_type;
  int n;
  vc<X> dat;
  Static_Range_Sum() {}
  void build(vc<X>& A) {
    n = len(A);
    dat.assign(n + 1, MX::unit());
    for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);
  }
  X prod(int l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }
  X sum(int l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }
};

template <bool SMALL_Y>
void test(int N) {
  int MAX = RNG(2, 1 << 10);
  vc<int> A(N);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(MAX);
  FOR(i, N) A[i] = RNG(MAX);

  Wavelet_Matrix<int, false, Static_Range_Sum<Monoid_Add<int>>> WM(A, X);

  int Q = 100;
  FOR(Q) {
    int L = RNG(0, max(1, N));
    int R = RNG(0, max(1, N + 1));
    if (L > R) swap(L, R);
    int lo = RNG(0, MAX);
    int hi = RNG(0, MAX);
    if (lo > hi) swap(lo, hi);
    ++hi;
    vc<int> B = {A.begin() + L, A.begin() + R};
    vc<int> Y = {X.begin() + L, X.begin() + R};
    int t = RNG(0, 7);
    if (t == 0) { // count
      SHOW(A);
      SHOW(L, R, lo, hi);
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) cnt += 1;
      assert(WM.count(L, R, lo, hi) == cnt);
    }
    // if (t == 1) { // sm
    //   int sm = 0;
    //   FOR(i, L, R) if (lo <= A[i] && A[i] < hi) sm += X[i];
    //   assert(WM.sum(L, R, lo, hi) == sm);
    // }
    // if (t == 2) { // kth
    //   if (L == R) continue;
    //   int k = RNG(R - L);
    //   sort(all(B));
    //   assert(WM.kth(L, R, k) == B[k]);
    // }
    // if (t == 3) { // max_right
    //   int a = RNG(0, 10);
    //   int b = RNG(0, 10);
    //   int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);
    //   auto check
    //       = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };
    //   auto p = WM.max_right(check, L, R);
    //   int k = binary_search(
    //       [&](int k) -> bool {
    //         int sm = WM.sum_index_range(L, R, 0, k);
    //         return check(k, sm);
    //       },
    //       0, R - L + 1);
    //   int sm = WM.sum_index_range(L, R, 0, k);
    //   assert(p.fi == k && p.se == sm);
    // }
    // if (t == 4) { // k-th value and sum
    //   int k = RNG(0, R - L + 1);
    //   B.eb(infty<int>);
    //   auto I = argsort(B);
    //   int val = B[I[k]];
    //   int sm = 0;
    //   FOR(i, k) sm += Y[I[i]];
    //   auto p = WM.kth_value_sum(L, R, k);
    //   assert(p.fi == val && p.se == sm);
    // }
    // if (t == 5) { // next
    //   int x = RNG(-1, MAX + 2);
    //   int ans = infty<int>;
    //   for (auto& b: B) {
    //     if (x <= b) chmin(ans, b);
    //   }
    //   assert(ans == WM.next(L, R, x));
    // }
    // if (t == 6) { // prev
    //   int x = RNG(-1, MAX + 1);
    //   int ans = -infty<int>;
    //   for (auto& b: B) {
    //     if (b <= x) chmax(ans, b);
    //   }
    //   assert(ans == WM.prev(L, R, x));
    // }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(N, 64) { FOR(50) test<true>(N); }
  FOR(N, 64) { FOR(50) test<false>(N); }
  solve();

  return 0;
}
