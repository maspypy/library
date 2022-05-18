#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/lazy_cntsum_affine.hpp"
#include "mod/modint.hpp"
#include "bbst/randomized_bst_lazy.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  Randomized_BST_Lazy<Lazy_CntSum_Affine<mint>> RBST;
  vc<pair<mint, mint>> seg_raw(N);
  FOR(i, N) seg_raw[i] = {mint(1), A[i]};
  auto root = RBST.new_node(seg_raw);

  FOR(Q) {
    LL(t);
    // ST.debug(root);
    if (t == 0) {
      LL(i, x);
      RBST.insert(root, i, {mint(1), mint(x)});
    }
    if (t == 1) {
      LL(i);
      RBST.erase(root, i);
    }
    if (t == 2) {
      LL(l, r);
      RBST.reverse(root, l, r);
    }
    if (t == 3) {
      LL(l, r, b, c);
      RBST.apply(root, l, r, {mint(b), mint(c)});
    }
    if (t == 4) {
      LL(l, r);
      print(RBST.prod(root, l, r).se);
    }
  }
}

signed main() {
  solve();

  return 0;
}
