#define PROBLEM "https://yukicoder.me/problems/no/2508"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;
void solve() {
  B a, p, q;
  read(a, p, q);
  B b = a * (p + q);
  B c = a * p * q;
  Yes(b * b > B(4) * a * c);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
