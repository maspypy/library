#include "seq/hook_length_formula.hpp"

template <typename mint>
mint domino_standard_tableaux(vc<int> A) {
  int N = len(A);
  if (N == 0) return mint(1);
  FOR(i, N - 1) assert(A[i] >= A[i + 1]);
  int x = 0;
  FOR(i, N) {
    if (A[i] % 2 == 1) { x += (i % 2 == 0 ? 1 : -1); }
  }
  if (x != 0) return 0;
  FOR(i, N) A[i] += N - 1 - i;
  int ev = 0, od = 0;
  vc<int> P, Q;
  FOR_R(i, N) {
    if (A[i] % 2 == 0) { P.eb(A[i] / 2 - ev), ++ev; }
    if (A[i] % 2 == 1) { Q.eb(A[i] / 2 - od), ++od; }
  }
  reverse(all(P)), reverse(all(Q));
  int b = SUM<int>(P), c = SUM<int>(Q);
  return C<mint>(b + c, b) * hook_length_formula<mint>(P)
         * hook_length_formula<mint>(Q);
}
