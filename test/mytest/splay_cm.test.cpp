#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "mod/modint.hpp"
#include "ds/splaytree/splaytree_commutative_monoid.hpp"
#include "random/base.hpp"

using mint = modint998;

void test() {
  using Mono = Monoid_Add<int>;
  SplayTree_Commutative_Monoid<Mono, 100> X;
  using np = decltype(X)::np;

  FOR(1000) {
    X.reset();
    int N = RNG(1, 20);
    int Q = RNG(1, 1000);
    vc<int> A(N);
    FOR(i, N) A[i] = RNG(0, 100);
    np root = X.new_node(A);

    FOR(Q) {
      vc<int> cand = {0, 1, 2, 3, 4, 5};
      int t = cand[RNG(0, len(cand))];
      if (t == 0) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i));
      }
      if (t == 1) {
        int i = RNG(0, N);
        int x = RNG(0, 100);
        X.set(root, i, x);
        A[i] = x;
      }
      if (t == 2) {
        int i = RNG(0, N);
        int x = RNG(0, 100);
        X.multiply(root, i, x);
        A[i] = Mono::op(A[i], x);
      }
      if (t == 3) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        vc<int> B = {A.begin() + L, A.begin() + R};
        assert(X.prod(root, L, R) == SUM<int>(B));
      }
      if (t == 4) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        X.reverse(root, L, R);
        reverse(A.begin() + L, A.begin() + R);
      }
      if (t == 5) {
        vc<int> B = X.get_all(root);
        assert(A == B);
      }
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
