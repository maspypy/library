#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_d"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/my_multiset.hpp"

void solve() {
  LL(Q);
  My_Multiset<ll, int> X;
  FOR(Q) {
    LL(t, x);
    if (t == 1) {
      X.insert(x);
      continue;
    }
    LL(k);
    if (t == 2) {
      int n = X.get_range(-infty<int>, x + 1).fi - 1;
      n -= k - 1;
      if (0 <= n && n < len(X)) {
        print(X.get_kth(n).fi);
      } else {
        print(-1);
      }
    }
    if (t == 3) {
      int n = X.get_range(-infty<int>, x).fi;
      n += k - 1;
      if (0 <= n && n < len(X)) {
        print(X.get_kth(n).fi);
      } else {
        print(-1);
      }
    }
  };
}

signed main() {
  solve();
  return 0;
}