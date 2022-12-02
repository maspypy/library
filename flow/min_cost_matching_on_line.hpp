#include "ds/func/slope.hpp"

// 座標 0, ..., N-1 に A_i 個ある
// 座標 0, ..., N-1 で B_i 個まで受け入れられる
ll min_cost_matching_on_line_1(vi A, vi B) {
  assert(SUM<ll>(A) <= SUM<ll>(B));
  const int N = len(A);
  Slope_Trick f(vi(N + 1, 0), vi());
  FOR(i, N) {
    ll c = A[i] - B[i];
    f.shift(c);
    f.clear_right();
    f.add_abs(0);
  }
  return f.eval(0);
}
