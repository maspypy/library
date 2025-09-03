#define PROBLEM "https://yukicoder.me/problems/no/3005"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/outcircle.hpp"

using P = Point<ll>;

void solve() {
  P A, B, C, D;
  read(A, B, C, D);
  if ((A - B).det(A - C) == 0) return NO();
  int k = outcircle_side(A, B, C, D);
  YES(k == 0);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
