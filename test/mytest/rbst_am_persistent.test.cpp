#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/min_assign.hpp"
#include "ds/randomized_bst/rbst_acted_monoid.hpp"
#include "random/base.hpp"

void test() {
  using AM = ActedMonoid_Min_Assign<int, -1>;
  using MonoX = typename AM::Monoid_X;

  RBST_ActedMonoid<AM, true, 100000> X;
  using np = decltype(X)::np;

  FOR(1000) {
    X.reset();
    int N = RNG(1, 20);
    int Q = RNG(1, 1000);
    vvc<int> AA(1);
    vc<np> roots;
    FOR(i, N) AA[0].eb(RNG(1, 100));
    roots.eb(X.new_node(AA[0]));

    FOR(Q) {
      int t = RNG(0, 7);
      int frm = RNG(0, len(AA));
      np root = roots[frm];
      vc<int> A = AA[frm];
      if (t == 0) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i));
      }
      if (t == 1) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.set(root, i, x);
        A[i] = x;
      }
      if (t == 2) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.multiply(root, i, x);
        A[i] = MonoX::op(A[i], x);
      }
      if (t == 3) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        vc<int> B = {A.begin() + L, A.begin() + R};
        assert(X.prod(root, L, R) == MIN(B));
      }
      if (t == 4) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        root = X.reverse(root, L, R);
        reverse(A.begin() + L, A.begin() + R);
      }
      if (t == 5) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        int x = RNG(1, 100);
        FOR(i, L, R) A[i] = x;
        root = X.apply(root, L, R, x);
      }
      if (t == 6) {
        vc<int> B = X.get_all(root);
        assert(A == B);
      }
      AA.eb(A);
      roots.eb(root);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
