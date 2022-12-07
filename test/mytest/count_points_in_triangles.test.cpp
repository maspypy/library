#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/count_points_in_triangles.hpp"
#include "random/base.hpp"

void test() {
  using P = Point<ll>;
  vc<P> A, B;
  int K = 1'000'000'000;
  int N = 100, M = 100;
  FOR(N) {
    bool small = RNG(0, 2);
    if (small) {
      A.eb(RNG(-4, 5), RNG(-4, 5));
    } else {
      A.eb(RNG(-K, K), RNG(-K, K));
    }
  }
  FOR(M) {
    bool small = RNG(0, 2);
    if (small) {
      B.eb(RNG(-4, 5), RNG(-4, 5));
    } else {
      B.eb(RNG(-K, K), RNG(-K, K));
    }
  }
  Count_Points_In_Triangles X(A, B);
  FOR(100) {
    int i = RNG(0, N), j = RNG(0, N), k = RNG(0, N);
    int me = X.query(i, j, k);
    int naive = 0;
    for (auto&& p: B) {
      ll s1 = (A[j] - A[i]).det(p - A[i]);
      ll s2 = (A[k] - A[j]).det(p - A[j]);
      ll s3 = (A[i] - A[k]).det(p - A[k]);
      ll s = (A[k] - A[i]).det(A[j] - A[i]);
      if (s1 == 0 || s2 == 0 || s3 == 0 || s == 0) continue;
      if (abs(s1) + abs(s2) + abs(s3) == abs(s)) ++naive;
    }
    assert(me == naive);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  FOR(100) test();
  solve();

  return 0;
}
