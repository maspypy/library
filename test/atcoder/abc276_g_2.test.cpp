#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_g"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/from_log_differentiation.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  --N;
  M -= N;
  if (M < 0) return print(0);
  using poly = vc<mint>;
  vc<pair<poly, poly>> rationals;
  rationals.eb(poly{N}, poly{1, 1});
  rationals.eb(poly{2, 2, 3 * N + 2}, poly{1, 0, 0, -1});
  auto [a, b] = sum_of_rationals(rationals);
  auto ANS = from_log_differentiation_kth(M, a, b);
  print(ANS);
}

signed main() { solve(); }