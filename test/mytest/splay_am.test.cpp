#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/cntsum_add.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "ds/splay/splaytree_acted_monoid.hpp"

using mint = modint998;

void test() {
  using AM = ActedMonoid_CntSum_Add<int>;

  SplayTree_ActedMonoid<AM, 100> X;

  FOR(1000) {
    X.reset();
    int N = RNG(1, 10);
    int Q = RNG(1, 1000);
    vc<int> A(N);
    FOR(i, N) A[i] = RNG(1, 10);

    vc<pair<int, int>> seg_raw(N);
    FOR(i, N) seg_raw[i] = {1, A[i]};
    auto root = X.new_node(seg_raw);

    FOR(Q) {
      int t = RNG(0, 7);
      if (t == 0) {
        vc<pair<int, int>> B = X.get_all(root);
        FOR(i, N) assert(A[i] == B[i].se);
      }
      if (t == 1) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i).se);
      }
      if (t == 2) {
        int i = RNG(0, N);
        int x = RNG(1, 10);
        X.set(root, i, {1, x});
        A[i] = x;
      }
      if (t == 3) {
        int i = RNG(0, N);
        int x = RNG(1, 10);
        X.multiply(root, i, {0, x});
        A[i] += x;
      }
      if (t == 4) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        int sm = 0;
        FOR(i, L, R) sm += A[i];
        assert(X.prod(root, L, R).se == sm);
      }
      if (t == 5) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        X.reverse(root, L, R);
        reverse(A.begin() + L, A.begin() + R);
      }
      if (t == 6) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        int a = RNG(1, 10);
        ++R;
        FOR(i, L, R) A[i] += a;
        X.apply(root, L, R, a);
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