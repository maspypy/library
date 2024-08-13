#define PROBLEM "https://yukicoder.me/problems/no/1649"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "mod/modint.hpp"

using mint = modint998;

struct Mono {
  using value_type = tuple<mint, mint, mint>;
  using X = value_type;
  static X op(X x, X y) {
    auto& [x0, x1, x2] = x;
    auto& [y0, y1, y2] = y;
    return {x0 + y0, x1 + y1, x2 + y2};
  }
  static constexpr X unit() { return {mint(0), mint(0), mint(0)}; }
  static constexpr bool commute = true;
};

void solve() {
  LL(N);
  VEC(pi, XY, N);
  ll LIM = 1 << 30;

  Dynamic_SegTree_Sparse<Mono, false, 200000> seg(-LIM, LIM);
  using np = decltype(seg)::np;

  mint ANS = 0;
  FOR(4) {
    for (auto&& [x, y]: XY) tie(x, y) = mp(-y, x);
    seg.reset();
    np root = nullptr;
    sort(all(XY));
    for (auto&& [x, y]: XY) {
      mint x2 = (x + y) * (x + y);
      mint x1 = x + y;
      mint x0 = 1;
      auto [s0, s1, s2] = seg.prod(root, -LIM, y);
      ANS += x2 * s0 - mint(2) * x1 * s1 + x0 * s2;
      root = seg.multiply(root, y, {x0, x1, x2});
    }
  }
  ANS /= mint(2);
  print(ANS);
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
