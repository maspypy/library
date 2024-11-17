#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/kdtree/kdtree_acted_monoid.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"
#include "alg/monoid/add_pair.hpp"

using mint = modint998;
struct ActedMonoid {
  using Monoid_X = Monoid_Add_Pair<mint>;
  using Monoid_A = Monoid_Affine<mint>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static X act(const X &x, const A &a, const ll &size) { return {x.fi, a.fi * x.se + a.se * x.fi}; }
};

void solve() {
  LL(N, Q);
  vc<int> X(N), Y(N);
  vc<pair<mint, mint>> W(N);
  FOR(i, N) {
    INT(x, y, w);
    X[i] = x, Y[i] = y, W[i] = {1, w};
  }

  vc<tuple<int, int, int, int, int, int, int>> query;
  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(x, y, w);
      int k = len(X);
      X.eb(x), Y.eb(y), W.eb(0, 0);
      query.eb(0, k, w, 0, 0, 0, 0);
    }
    if (t == 1) {
      INT(k, w);
      query.eb(1, k, w, 0, 0, 0, 0);
    }
    if (t == 2) {
      INT(a, b, c, d);
      query.eb(2, a, c, b, d, 0, 0);
    }
    if (t == 3) {
      INT(a, b, c, d, p, q);
      query.eb(3, a, c, b, d, p, q);
    }
  }
  assert(len(X) == len(Y) && len(X) == len(W));
  KDTree_ActedMonoid<ActedMonoid, int> KDT(X, Y, W);

  for (auto &[t, a, b, c, d, A, B]: query) {
    if (t == 0) { KDT.set(a, {1, b}); }
    if (t == 1) { KDT.set(a, {1, b}); }
    if (t == 2) {
      mint ANS = KDT.prod(a, b, c, d).se;
      print(ANS);
    }
    if (t == 3) { KDT.apply(a, b, c, d, {A, B}); }
  }
}

signed main() { solve(); }