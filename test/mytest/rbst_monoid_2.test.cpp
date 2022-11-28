#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"
#include "ds/bbst/rbst_monoid.hpp"
#include "random/base.hpp"

using mint = modint998;

void test() {
  using Mono = Monoid_Affine<mint>;
  RBST_Monoid<Mono, 100> X;
  auto rnd_affine = [&]() -> pair<mint, mint> {
    int a = RNG(0, 3);
    int b = RNG(0, 3);
    return {a, b};
  };

  using T = typename Mono::value_type;

  FOR(1000) {
    X.reset();
    int N = 2;
    int Q = RNG(1, 1000);
    vc<T> A(N);
    FOR(i, N) A[i] = rnd_affine();
    auto root = X.new_node(A);

    FOR(Q) {
      vc<int> cand = {0, 1, 2, 3, 4, 5};
      int t = cand[RNG(0, len(cand))];
      if (t == 0) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i));
      }
      if (t == 1) {
        int i = RNG(0, N);
        T x = rnd_affine();
        root = X.set(root, i, x);
        A[i] = x;
      }
      if (t == 2) {
        int i = RNG(0, N);
        T x = rnd_affine();
        root = X.multiply(root, i, x);
        A[i] = Mono::op(A[i], x);
      }
      if (t == 3) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        vc<T> B = {A.begin() + L, A.begin() + R};
        T t = Mono::unit();
        for (auto&& b: B) t = Mono::op(t, b);
        assert(X.prod(root, L, R) == t);
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
        vc<T> B = X.get_all(root);
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