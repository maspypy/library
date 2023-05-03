#define PROBLEM "https://atcoder.jp/contests/abc237/tasks/abc237_g"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/sortable_array.hpp"

void solve() {
  LL(N, Q, val);
  VEC(int, A, N);
  Sortable_Array<10'000'000> X(MAX(A) + 1, A);
  FOR(Q) {
    LL(t, L, R);
    --L;
    if (t == 1) { X.sort_inc(L, R); }
    if (t == 2) { X.sort_dec(L, R); }
  }
  A = X.get_all();
  FOR(i, N) if (A[i] == val) return print(1 + i);
}

signed main() {
  solve();
  return 0;
}