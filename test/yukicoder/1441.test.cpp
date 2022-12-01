#define PROBLEM "https://yukicoder.me/problems/no/1441"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/splay/splaytree_monoid.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  SplayTree_Monoid<Monoid_Add<ll>> ST;
  auto root = ST.new_node(A);
  FOR(Q) {
    LL(t, l, r);
    --l;
    if (t == 1) {
      auto nr = ST.split(root, r);
      auto nm = ST.split(root, l);
      nm = ST.new_node(nm->prod);
      ST.merge(root, nm);
      ST.merge(root, nr);
    }
    if (t == 2) { print(ST.prod(root, l, r)); }
  }
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
