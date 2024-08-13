#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_e"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/sortable_array.hpp"

void solve() {
  LL(Q);
  int L = 0, R = 0;
  Sortable_Array<15'000'000> X(infty<int> + 1, vc<int>(Q));
  FOR(Q) {
    INT(t);
    if (t == 1) {
      INT(x);
      X.set(R++, x);
    }
    if (t == 2) {
      print(X.get(L));
      L++;
    }
    if (t == 3) {
      if (L < R) X.sort_inc(L, R);
    }
  }
}

signed main() {
  solve();
  return 0;
}