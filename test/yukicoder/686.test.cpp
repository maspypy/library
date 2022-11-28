#define PROBLEM "https://yukicoder.me/problems/no/686"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/max_add.hpp"
#include "ds/bbst/rbst_lazy.hpp"

void solve() {
  LL(N);
  const int LIM = 100'010;
  using AM = ActedMonoid_Max_Add<int>;
  vc<int> dp(LIM);
  RBST_Lazy<AM, LIM> seg;
  auto root = seg.new_node(dp);

  FOR(N) {
    LL(L, R);
    {
      int a = seg.prod(root, R, R + 1);
      int b = seg.prod(root, R - 1, R);
      if (a != b) {
        --R;
      } else {
        auto check = [&](int e) -> bool { return e <= a; };
        int k = seg.max_right(root, check, R);
        R = k - 1;
      }
    }
    if (L > R) continue;
    root = seg.apply(root, L, R, 1);
    int x = seg.get(root, L - 1);
    auto [a, b, c, d] = seg.split4(root, L, R, R + 1);
    c = seg.set(c, 0, x + 1);
    root = seg.merge4(a, c, b, d);
    assert(root->size == LIM);
  }

  print(seg.prod(root, 0, LIM));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}