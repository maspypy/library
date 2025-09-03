#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/count_points_in_triangles.hpp"

using P = Point<ll>;

void solve() {
  LL(N);
  vc<P> A(N);
  FOR(i, N) read(A[i]);
  LL(M);
  vc<P> B(M);
  FOR(i, M) read(B[i]);

  Count_Points_In_Triangles X(A, B);

  LL(Q);
  FOR(Q) {
    INT(a, b, c);
    print(X.count3(a, b, c));
  }
}

signed main() {
  solve();
  return 0;
}