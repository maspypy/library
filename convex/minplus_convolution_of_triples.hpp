#include "convex/minplus_convolution_convex.hpp"

// https://codeforces.com/contest/436/problem/E
// 長さ 3 の数列 {a[i][0], a[i][1], a[i][2]} たちの畳み込み, O(NlogN)
// 同種の問題：(a_i,b_i) があって、b_i は a_i を取ってからだけ取れる
template <typename T>
struct MinPlus_Convolution_of_Triples {
  int N = 0;
  T sm0 = 0;
  vc<array<T, 3>> dat;
  vc<T> dp1, dp2, dp;
  vc<int> I1, I2;
  bool solved = false;

  void add(T x0, T x1, T x2) { sm0 += x0, dat.eb(array<T, 3>{x0, x1, x2}); }

  void solve() {
    solved = true;
    N = dat.size();
    FOR(i, N) {
      int a = dat[i][1] - dat[i][0], b = dat[i][2] - dat[i][1];
      (a <= b ? I1 : I2).eb(i);
    };
    sort(all(I2), [&](int i, int j) -> bool {
      return dat[i][2] - dat[i][0] < dat[j][2] - dat[j][0];
    });
    solve_1();
    solve_2();
    dp = minplus_convolution_convex<T, true, false>(dp1, dp2);
    for (auto&& x: dp) x += sm0;
  }

  T operator[](int i) { return dp[i]; }

  vc<int> restore(int k) {
    assert(solved);
    int k1 = -1, k2 = -1;
    FOR(i, k + 1) {
      int j = k - i;
      if (0 <= i && i < len(dp1) && 0 <= j && j < len(dp2)
          && dp1[i] + dp2[j] + sm0 == dp[k]) {
        k1 = i, k2 = j;
        break;
      }
    }
    assert(k1 != -1 && k2 != -1);
    vc<int> x(N);
    vc<int> x1 = restore_1(k1);
    vc<int> x2 = restore_2(k2);
    for (int i = 0; i < N; ++i) x[i] = x1[i] + x2[i];
    // check
    T sm = 0;
    for (int i = 0; i < N; ++i) sm += dat[i][x[i]];
    assert(sm == dp[k]);
    return x;
  }

private:
  void solve_1() {
    dp1.reserve(len(I1));
    for (int i: I1) {
      dp1.eb(dat[i][1] - dat[i][0]), dp1.eb(dat[i][2] - dat[i][1]);
    }
    sort(all(dp1));
    dp1 = cumsum<T>(dp1);
  }

  vc<int> restore_1(int k) {
    vc<pair<T, int>> A;
    for (int i: I1) {
      A.eb(dat[i][1] - dat[i][0], i);
      A.eb(dat[i][2] - dat[i][1], i);
    }
    nth_element(A.begin(), A.begin() + k, A.end());
    vc<int> x(N);
    FOR(i, k) x[A[i].se]++;
    return x;
  }

  void solve_2() {
    // B-A > C-B のケース
    // 解の構造を考えると、ほとんどすべてで x=0 or x=2 というとりかたになる
    // 既に C-A でソート済
    auto& I = I2;
    int n = len(I);
    dp2.assign(2 * n + 1, infty<T>);
    // 偶数個
    dp2[0] = 0;
    for (int i = 0; i < n; ++i) {
      dp2[2 * i + 2] = dp2[2 * i] + (dat[I[i]][2] - dat[I[i]][0]);
    }
    // 奇数個, prefix からひとつキャンセルする
    T ma = -infty<T>;
    for (int i = 0; i < n; ++i) {
      chmax(ma, dat[I[i]][2] - dat[I[i]][1]);
      chmin(dp2[2 * i + 1], dp2[2 * i + 2] - ma);
    }
    // 奇数個, suffix からひとつ追加する
    T mi = infty<T>;
    for (int i = n - 1; i >= 0; --i) {
      chmin(mi, dat[I[i]][1] - dat[I[i]][0]);
      chmin(dp2[2 * i + 1], dp2[2 * i] + mi);
    }
    return;
  }

  vc<int> restore_2(int k) {
    auto& I = I2;
    int n = len(I);
    vc<int> x(N);
    if (k % 2 == 0) {
      FOR(i, k / 2) x[I[i]] = 2;
      return x;
    }
    pair<T, int> ma = {-infty<T>, -1};
    FOR(i, (k + 1) / 2) {
      if (chmax(ma.fi, dat[I[i]][2] - dat[I[i]][1])) ma.se = I[i];
    }
    if (dp2[k] == dp2[k + 1] - ma.fi) {
      FOR(i, (k + 1) / 2) x[I[i]] = 2;
      x[ma.se]--;
      return x;
    }
    pair<T, int> mi = {infty<T>, -1};
    for (int i = n - 1; i >= k / 2; --i) {
      if (chmin(mi.fi, dat[I[i]][1] - dat[I[i]][0])) mi.se = I[i];
    }
    if (dp2[k] == dp2[k - 1] + mi.fi) {
      FOR(i, (k - 1) / 2) x[I[i]] = 2;
      x[mi.se] = 1;
      return x;
    }
    assert(0);
    return x;
  }
};