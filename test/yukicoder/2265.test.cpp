#define PROBLEM "https://yukicoder.me/problems/no/2265"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/xor_segtree.hpp"

using mint = modint998;

struct Mono {
  using value_type = tuple<mint, mint, mint>;
  using X = value_type;
  static X op(X& x, X& y) {
    auto& [x1, x2, x3] = x;
    auto& [y1, y2, y3] = y;
    return {x1 * y3 + y1 * x2, x2 * y2, x3 * y3};
  }
  static X from_element(mint x) { return {x, mint(2), mint(11)}; }
  static constexpr X unit() { return {mint(0), mint(1), mint(1)}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);
  STR(S);

  Xor_SegTree<Mono> seg(1 << N, [&](int i) -> tuple<mint, mint, mint> {
    return Mono::from_element(S[i] - '0');
  });

  LL(Q);
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(x, y);
      seg.set(x, Mono::from_element(y));
    }
    if (t == 2) {
      LL(L, R, X);
      ++R;
      print(seg.prod(L, R, X));
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
