#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "ds/segtree/prefix_max_segtree.hpp"
#include "random/base.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;
using F = pair<mint, mint>;

void test(ll N) {
  vc<int> key(N);
  vc<F> X(N);
  auto get = [&]() -> pair<int, F> {
    int k = RNG(0, 100);
    mint a = RNG(0, mint::get_mod());
    mint b = RNG(0, mint::get_mod());
    return {k, {a, b}};
  };

  FOR(i, N) tie(key[i], X[i]) = get();

  auto segf = [&](int i) -> pair<int, F> { return {key[i], X[i]}; };

  using Mono = Monoid_Affine<mint>;
  Prefix_Max_SegTree<int, Mono> seg(N, segf);

  auto naive = [&](int L, int R) -> F {
    int mx = -infty<int>;
    F prod = Mono::unit();
    FOR(i, L, R) {
      if (mx <= key[i]) {
        mx = key[i];
        prod = Mono::op(prod, X[i]);
      }
    }
    return prod;
  };

  /*
  set
  get
  get_all
  prod
  prod_all
  */
  int Q = 1000;
  FOR(Q) {
    int t = RNG(0, 5);
    int i = RNG(0, N);
    int L = RNG(0, N), R = RNG(0, N);
    auto [k, x] = get();
    if (L > R) swap(L, R);
    ++R;
    if (t == 0) {
      key[i] = k, X[i] = x;
      seg.set(i, {k, x});
    }
    if (t == 1) {
      auto [k, x] = seg.get(i);
      assert(key[i] == k);
      assert(X[i] == x);
    }
    if (t == 2) {
      auto [k, x] = seg.get_all();
      assert(key == k);
      assert(X == x);
    }
    if (t == 3) { assert(naive(L, R) == seg.prod(L, R)); }
    if (t == 4) { assert(naive(0, N) == seg.prod_all()); }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(100) FOR(N, 1, 100) { test(N); }
  solve();
  return 0;
}
