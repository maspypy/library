#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "string/count_subseq.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(int, A, N);
  mint ANS = count_subseq<mint, int>(A);
  ANS -= mint(1);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
