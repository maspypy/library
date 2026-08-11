#define PROBLEM "https://yukicoder.me/problems/no/3619"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/schroder.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  VEC(mint, F, N);
  Schroder<mint> SCH(F);
  vc<mint> ANS = SCH.iterated_composition(K);
  print(ANS);
}

signed main() { solve(); }
