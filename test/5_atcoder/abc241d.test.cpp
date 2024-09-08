#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_d"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_multiset.hpp"

void solve() {
  LL(Q);
  My_Multiset X(Q);
  auto c = X.new_root();
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(x);
      c = X.add(c, x);
    }
    if (t == 2) {
      LL(x, k);
      auto [cnt, sm] = X.get_range(c, -infty<ll>, x + 1);
      if (cnt < k) {
        print(-1);
      } else {
        ll ans = X.prefix_kth(c, cnt - k).fi;
        print(ans);
      }
    }
    if (t == 3) {
      LL(x, k);
      auto [cnt, sm] = X.get_range(c, x, infty<ll>);
      if (cnt < k) {
        print(-1);
      } else {
        ll ans = X.suffix_kth(c, cnt - k).fi;
        print(ans);
      }
    }
  }
}

signed main() {
  solve();
  return 0;
}