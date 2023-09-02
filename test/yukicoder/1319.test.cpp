#define PROBLEM "https://yukicoder.me/problems/no/1319"
#define ERROR 0.01
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/definite_integral.hpp"

void solve() {
  DBL(R, H, D);
  using Re = double;
  auto f = [&](Re z) -> Re {
    Re r = R * z / H;
    if (2 * r <= D) return 0;
    Re theta = acos(D / (2 * r));
    Re S = r * r * sin(2 * theta);
    Re T = r * r * theta * 2;
    return T - S;
  };

  Re ANS = definite_integral<Re>(0, H, f, 10000);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
