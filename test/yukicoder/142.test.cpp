#define PROBLEM "https://yukicoder.me/problems/no/142"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_bitset.hpp"

void solve() {
  LL(N, S, X, Y, Z);
  LL(Q);
  using BS = My_Bitset;
  BS A(N);
  FOR(i, N) {
    if (S & 1) A.on(i);
    S = (X * S + Y) % Z;
  }

  FOR(Q) {
    LL(a, b, c, d);
    --a, --c;
    BS x = A.range(a, b);
    A.xor_to_range(c, d, x);
  }
  string ANS = A.to_string();
  for (auto&& ch: ANS) { ch = (ch == '0' ? 'E' : 'O'); }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
