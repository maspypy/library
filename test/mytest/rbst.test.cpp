#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/rbst/rbst.hpp"
#include "random/base.hpp"

void test() {
  RBST<int, true, 10000> X;
  using np = decltype(X)::np;

  FOR(1000) {
    X.reset();
    int N = RNG(1, 20);
    int Q = RNG(1, 1000);
    vvc<int> AA(1);
    FOR(i, N) AA[0].eb(RNG(0, 100));
    vc<np> roots = {X.new_node(AA[0])};

    FOR(Q) {
      vc<int> cand = {0, 1, 2, 3};
      int t = cand[RNG(0, len(cand))];
      int frm = RNG(0, len(AA));
      vc<int> A = AA[frm];
      np root = roots[frm];
      if (t == 0) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i));
      }
      if (t == 1) {
        int i = RNG(0, N);
        int x = RNG(0, 100);
        root = X.set(root, i, x);
        A[i] = x;
      }
      if (t == 2) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        root = X.reverse(root, L, R);
        reverse(A.begin() + L, A.begin() + R);
      }
      if (t == 3) {
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