#define PROBLEM "https://yukicoder.me/problems/no/1790"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/xor.hpp"
#include "alg/monoid/max.hpp"
#include "graph/ds/lazytreemonoid.hpp"

struct ActedMonoid {
  using Monoid_X = Monoid_Xor<ll>;
  using Monoid_A = Monoid_Max<int>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (a == Monoid_A::unit()) return x;
    return 0;
  }
};

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  vc<ll> dat;
  FOR(N - 1) {
    LL(a, b, x);
    --a, --b;
    G.add(a, b);
    dat.eb(x);
  }
  G.build();
  TREE<decltype(G)> tree(G);

  LazyTreeMonoid<decltype(tree), ActedMonoid, 1> X(tree, dat);
  LL(Q);
  FOR(Q) {
    LL(t, x);
    --x;
    if (t == 2) { print(X.prod_subtree(x)); }
    if (t == 1) {
      X.apply_subtree(x, 0);
      if (x) X.apply_path(x, tree.parent[x], 0);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
