#define PROBLEM "https://yukicoder.me/problems/no/2645"
#define ERROR 1e-6

#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/famous/harmonic.hpp"

using Re = double;

// sum 1/ij
void solve() {
  LL(N);
  Re ANS = 0;

  FOR(i, 1, N + 1) {
    ll hi = N / i;
    if (i >= hi) break;
    Re x = Harmonic(hi) - Harmonic(i);
    ANS += x / i;
  }
  ANS += ANS;
  FOR(i, 1, N + 1) {
    if (i * i > N) break;
    ANS += 1.0 / (i * i);
  }

  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
