#define PROBLEM "https://yukicoder.me/problems/no/2280"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/range_freq_of_linear.hpp"

void solve() {
  LL(M, A, B, K);
  ll NA = M / A;
  ll ANS = 0;

  ll xAA = 0, xAB = 0, xBA = 0;
  if (K == A) { xAA = range_freq_of_linear(1, NA, A, 0, B, 1, B - A); }

  auto f = [&](ll A, ll B) -> ll {
    if (K > A || K > B) return 0;
    // A の倍数 -> B の倍数
    ll res = 0;
    ll ub = floor(M - K, A);
    res = range_freq_of_linear(1, ub + 1, A, K, B, 0, 1);
    return res;
  };

  xAB = f(A, B);
  xBA = f(B, A);
  ANS = xAA + xAB + xBA;

  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
