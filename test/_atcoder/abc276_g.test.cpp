#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_g"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/from_log_differentiation.hpp"
#include "poly/sum_of_rationals.hpp"

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
  /*
  vvc<mint> c(5);
  int r = 4;
  FOR(i, r + 1) {
    mint c0 = 0, c1 = 0;
    if (i < len(a)) c0 += mint(r - i) * a[i];
    if (i < len(a)) c1 += a[i];
    if (0 <= i - 1 && i - 1 < len(b)) c0 += b[i - 1];
    c[i] = {c0, c1};
  }
  mint ANS = kth_term_of_p_recursive(f, c, M);
  print(ANS);
  */
  auto f = from_log_differentiation(M, a, b);
  print(f[M]);
}

signed main() { solve(); }