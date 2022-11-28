#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/cntsum_affine.hpp"
#include "mod/modint.hpp"
#include "ds/bbst/splaytree_lazy.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  SplayTree_Lazy<ActedMonoid_CntSum_Affine<mint>> ST;
  vc<pair<mint, mint>> seg_raw(N);
  FOR(i, N) seg_raw[i] = {mint(1), A[i]};
  auto root = ST.new_node(seg_raw);

  FOR(Q) {
    LL(t);
    // ST.debug(root);
    if (t == 0) {
      LL(i, x);
      ST.insert(root, i, {mint(1), mint(x)});
    }
    if (t == 1) {
      LL(i);
      ST.erase(root, i);
    }
    if (t == 2) {
      LL(l, r);
      ST.reverse(root, l, r);
    }
    if (t == 3) {
      LL(l, r, b, c);
      ST.apply(root, l, r, {mint(b), mint(c)});
    }
    if (t == 4) {
      LL(l, r);
      print(ST.prod(root, l, r).se);
    }
  }
}

signed main() {
  solve();

  return 0;
}
