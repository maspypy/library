#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "ds/bbst/splaytree_monoid.hpp"

void test() {
  // reverse, set, prod の動作を確認
  using mint = modint998;
  using Mono = Monoid_Affine<mint>;
  using X = Mono::value_type;
  SplayTree_Monoid<Mono> ST;

  auto rnd_X = [&]() -> X {
    ll a = RNG(0, 1 << 30);
    ll b = RNG(0, 1 << 30);
    return {mint(a), mint(b)};
  };
  auto get_lr = [&](int N) -> pi {
    int l = RNG(0, N);
    int r = RNG(0, N);
    if (l > r) swap(l, r);
    ++r;
    return {l, r};
  };

  FOR(N, 1, 10) {
    ST.reset();

    vc<X> A(N);
    FOR(i, N) { A[i] = rnd_X(); }

    auto root = ST.new_node(A);
    FOR(100) {
      int t = RNG(0, 3);
      if (t == 0) {
        // set
        int i = RNG(0, N);
        X x = rnd_X();
        A[i] = x;
        ST.set(root, i, x);
      }
      if (t == 1) {
        // reverse
        auto [l, r] = get_lr(N);
        reverse(A.begin() + l, A.begin() + r);
        ST.reverse(root, l, r);
      }
      if (t == 2) {
        // prod
        auto [l, r] = get_lr(N);
        X a = Mono::unit();
        FOR(i, l, r) a = Mono::op(a, A[i]);
        X b = ST.prod(root, l, r);
        assert(a == b);
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();

  ll T = 1;
  FOR(T) solve();

  return 0;
}
