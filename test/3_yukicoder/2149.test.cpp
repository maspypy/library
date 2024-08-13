#define PROBLEM "https://yukicoder.me/problems/no/2149"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/domino_standard_tableaux.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(int, A, N);
  reverse(all(A));
  print(domino_standard_tableaux<mint>(A));
}

signed main() {
  solve();
  return 0;
}
