#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/splaytree/splaytree_commutative_monoid.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);

  SplayTree_Commutative_Monoid<Monoid_Add<ll>, 200'100> ST;
  auto root = ST.new_node(A);

  FOR(Q) {
    LL(t, L, R);
    if (t == 0) {
      ST.reverse(root, L, R);
    } else {
      print(ST.prod(root, L, R));
    }
  }
}

signed main() {
  solve();
  return 0;
}