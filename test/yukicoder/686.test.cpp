#define PROBLEM "https://yukicoder.me/problems/no/686"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/lazy/max_add.hpp"
#include "ds/bbst/rbst_lazy.hpp"

void solve() {
  LL(N);
  ll LIM = 100'010;
  using Lazy = Lazy_Max_Add<int>;
  vc<int> dp(LIM);
  RBST_Lazy<Lazy> seg;
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
    seg.apply(root, L, R, 1);
    auto d = seg.split(root, R + 1);
    auto c = seg.split(root, R);
    auto b = seg.split(root, L);
    int x = seg.prod(root, L - 1, L);
    seg.merge(root, seg.new_node(x + 1));
    seg.merge(root, b);
    seg.merge(root, d);
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
