#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/xor_segtree.hpp"

using mint = modint998;

mint pow2[1 << 18];
mint pow11[1 << 18];

struct Mono {
  using value_type = pair<int, mint>;
  using X = value_type;
  static X op(X& x, X& y) {
    return {x.fi + y.fi, x.se * pow11[y.fi] + y.se * pow2[x.fi]};
  }
  static X from_element(mint x) { return {1, x}; }
  static constexpr X unit() { return {0, mint(0)}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);

  pow2[0] = mint(1);
  FOR(i, 1, 1 << N) pow2[i] = mint(2) * pow2[i - 1];
  pow11[0] = mint(1);
  FOR(i, 1, 1 << N) pow11[i] = mint(11) * pow11[i - 1];
  STR(S);

  Xor_SegTree<Mono> seg(1 << N, [&](int i) -> pair<int, mint> {
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
      print(seg.prod(L, R, X).se);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
