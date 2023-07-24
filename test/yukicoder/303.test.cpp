#define PROBLEM "https://yukicoder.me/problems/no/303"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/famous/fibonacci.hpp"
#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  LL(N);
  if (N == 2) {
    print(3);
    print("INF");
    return;
  }
  B x = fibonacci<B>(N);
  if (N % 2 == 0) {
    B y = fibonacci<B>(N / 2);
    x -= y * y;
  }
  print(N);
  print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
