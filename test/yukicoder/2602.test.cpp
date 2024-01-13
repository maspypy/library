#define PROBLEM "https://yukicoder.me/problems/no/2602"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/base.hpp"
#include "geo/outcircle.hpp"

using P = Point<ll>;

void solve() {
  LL(Q);
  P A, B, C;
  read(A, B, C);

  A.x *= 2;
  A.y *= 2;
  B.x *= 2;
  B.y *= 2;
  C.x *= 2;
  C.y *= 2;

  FOR(3) {
    tie(A, B, C) = mt(B, C, A);
    ll dot = (B - A).dot(C - A);
    if (dot < 0) {
      P O = (B + C);
      O.x /= 2, O.y /= 2;
      A = B - O;
      tie(A.x, A.y) = mp(A.y, -A.x);
      A = A + O;
    }
  }

  FOR(Q) {
    P p;
    read(p);
    p.x *= 2, p.y *= 2;
    Yes(outcircle_side(A, B, C, p) >= 0);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
