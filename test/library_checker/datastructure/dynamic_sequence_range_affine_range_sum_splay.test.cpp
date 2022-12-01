#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/cntsum_affine.hpp"
#include "mod/modint.hpp"
#include "ds/splay/splaytree_acted_monoid.hpp"

using mint = modint998;

void solve() {
  using AM = ActedMonoid_CntSum_Affine<mint>;
  SplayTree_ActedMonoid<AM, 1'000'000> X;
  using P = typename AM::X;

  INT(N, Q);
  vc<P> dat(N);
  FOR(i, N) {
    mint a;
    read(a);
    dat[i] = {mint(1), a};
  }

  auto root = X.new_node(dat);

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(i, x);
      auto [a, b] = X.split(root, i);
      root = X.merge3(a, X.new_node({mint(1), mint(x)}), b);
    }
    if (t == 1) {
      INT(i);
      auto [a, b, c] = X.split3(root, i, i + 1);
      root = X.merge(a, c);
    }
    if (t == 2) {
      INT(L, R);
      X.reverse(root, L, R);
    }
    if (t == 3) {
      INT(L, R, b, c);
      X.apply(root, L, R, {mint(b), mint(c)});
    }
    if (t == 4) {
      INT(L, R);
      print(X.prod(root, L, R).se);
    }
  }
}

signed main() {
  solve();
  return 0;
}
