#define PROBLEM "https://yukicoder.me/problems/no/1549"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/segtree/segtree.hpp"
#include "poly/convolution.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

const int LIM = 3000;

struct Mono {
  using value_type = vc<mint>;
  using X = value_type;
  static X op(X x, X y) {
    X z = convolution(x, y);
    if (len(z) > LIM + 1) z.resize(LIM + 1);
    return z;
  }
  static X unit() { return {1}; }
  static constexpr bool commute = 1;
};

void solve() {
  LL(N, Q);
  const int LIM = 3000;
  using T = tuple<ll, int, int, int, int>;
  vc<T> query;
  vi I;
  FOR(q, Q) {
    LL(k, a, b, s, t);
    query.eb(k, a, b, s, t);
    I.eb(k);
  }
  UNIQUE(I);
  for (auto&& [k, a, b, s, t]: query) k = LB(I, k);

  ll K = len(I);
  vv(mint, F, K, LIM + 1, mint(1));
  SegTree<Mono> seg(F);

  vc<mint> F0(LIM + 1);
  F0[0] = mint(1), F0[1] = mint(-1);
  F0 = fps_pow_1<mint>(F0, K - N);

  for (auto&& [k, a, b, s, t]: query) {
    FOR(i, a, b + 1) F[k][i] = mint(0);
    seg.set(k, F[k]);
    auto f = seg.prod_all();
    f = convolution(F0, f);
    mint ANS = 0;
    FOR(i, s, t + 1) ANS += f[i];
    print(ANS);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
