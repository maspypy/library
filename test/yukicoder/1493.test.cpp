#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "dp/count_subseq.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  FOR(i, N - 1) A[i + 1] ^= A[i];
  A.pop_back();

  mint ANS = count_subseq<mint, int, vc<int>>(A);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
