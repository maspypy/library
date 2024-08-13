#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/static_range_frequency.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  Static_Range_Frequency X(A);
  FOR(Q) {
    INT(l, r, x);
    print(X.query(l, r, x));
  }
}

signed main() {
  solve();
  return 0;
}
