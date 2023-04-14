#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_d"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/my_multiset.hpp"

void solve() {
  LL(Q);
  My_Multiset<ll, int, int, false, 200'000> X;
  auto root = X.new_root();

  FOR(Q) {
    LL(t, x);
    if (t == 1) {
      root = X.add(root, x, 1);
      continue;
    }
    LL(k);
    --k;
    if (t == 2) {
      ll n = X.get_range(root, -infty<ll>, x + 1).fi;
      if (k >= n) {
        print(-1);
      } else {
        print(X.prefix_kth(root, n - 1 - k).fi);
      }
    }
    if (t == 3) {
      ll n = X.get_range(root, x, infty<ll>).fi;
      if (k >= n) {
        print(-1);
      } else {
        print(X.suffix_kth(root, n - 1 - k).fi);
      }
    }
  };
}

signed main() {
  solve();
  return 0;
}