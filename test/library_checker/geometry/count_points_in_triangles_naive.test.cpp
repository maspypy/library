#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/convex_polygon.hpp"

using P = Point<ll>;
void solve() {
  LL(N);
  VEC(P, A, N);
  LL(M);
  VEC(P, B, M);
  LL(Q);
  FOR(Q) {
    LL(a, b, c);
    ConvexPolygon<ll> X({A[a], A[b], A[c]});
    int ans = 0;
    FOR(i, M) { ans += (X.side(B[i]) == 1); }
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}