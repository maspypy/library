#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/count_points_in_triangles.hpp"

using P = Point<ll>;

void solve() {
  INT(N);
  VEC(P, A, N);
  INT(M);
  VEC(P, B, M);

  INT(Q);
  FOR(Q) {
    INT(a, b, c);
    P A = points_1[a], B = points_1[b], C = points_1[c];
    // counter-clockwise
    if ((B - A).det(C - A) < 0) swap(B, C);

    int ans = 0;
    FOR(i, M) {
      P p = points_2[i];
      if ((B - A).det(p - A) <= 0) continue;
      if ((C - B).det(p - B) <= 0) continue;
      if ((A - C).det(p - C) <= 0) continue;
      ++ans;
    }
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}