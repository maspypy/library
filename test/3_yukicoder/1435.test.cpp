#define PROBLEM "https://yukicoder.me/problems/no/1435"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"

struct Mono {
  using value_type = tuple<int, int, int>; // max, min1, min2
  using X = value_type;
  static X op(X& x, X& y) {
    auto& [xma, xmi1, xmi2] = x;
    auto& [yma, ymi1, ymi2] = y;
    if (xma == -1) return y;
    if (yma == -1) return x;
    if (xmi1 < ymi1) { return {max(xma, yma), xmi1, min(xmi2, ymi1)}; }
    return {max(xma, yma), ymi1, min(ymi2, xmi1)};
  }
  static X from_element(int x) { return {x, x, 1 << 30}; }
  static constexpr X unit() { return {-1, -1, -1}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);
  VEC(int, A, N);
  SegTree<Mono> seg(
      N, [&](int i) -> Mono::value_type { return Mono::from_element(A[i]); });

  ll ANS = 0;
  FOR(L, N) {
    auto check = [&](auto e) -> bool {
      auto& [M, m1, m2] = e;
      if (M == -1) return 1;
      return M <= m1 + m2;
    };
    auto R = seg.max_right(check, L);
    ANS += max<int>(0, R - L - 1);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
