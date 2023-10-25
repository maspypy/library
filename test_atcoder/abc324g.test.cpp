#define PROBLEM "https://atcoder.jp/contests/abc324/tasks/abc324_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/wavelet_matrix.hpp"

void solve() {
  INT(N);
  VEC(int, A, N);
  using T = tuple<int, int, int, int>;
  vc<T> dat;
  dat.eb(0, N, 0, MAX(A) + 1);

  Wavelet_Matrix<int, 0> WM(A);

  INT(Q);
  FOR(Q) {
    INT(t, s, x);
    auto [L, R, lo, hi] = dat[s];
    if (t == 1) {
      auto check = [&](int M) -> bool { return WM.count(L, M, lo, hi) >= x; };
      if (!check(R)) {
        dat.eb(0, 0, 0, 0);
      } else {
        int M = binary_search(check, R, L - 1);
        dat[s] = {L, M, lo, hi};
        dat.eb(M, R, lo, hi);
      }
    }
    if (t == 2) {
      if (x >= hi) { dat.eb(0, 0, 0, 0); }
      elif (x < lo) {
        dat[s] = {0, 0, 0, 0};
        dat.eb(L, R, lo, hi);
      }
      else {
        dat[s] = {L, R, lo, x + 1};
        dat.eb(L, R, x + 1, hi);
      }
    }

    {
      auto [L, R, lo, hi] = dat.back();
      int ANS = WM.count(L, R, lo, hi);
      print(ANS);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
