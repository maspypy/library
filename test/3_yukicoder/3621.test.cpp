#define PROBLEM "https://yukicoder.me/problems/no/3621"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/schroder.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, F, N);
  Schroder<mint> SCH(F);

  print(SCH.G);
  print(SCH.H);
}

signed main() { solve(); }
