#define PROBLEM "https://yukicoder.me/problems/no/2362"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/floor_sum_of_linear_polynomial.hpp"

void solve() {
  u64 N, M, X, Y;
  read(N, M, X, Y);
  u64 ANS = 0;
  {
    auto a = floor_sum_of_linear_polynomial_nonnegative<u64, 1, 1, u64>(N, X, 0, M);
    ANS -= a[0][1] * N - a[1][1];
  }
  {
    auto a = floor_sum_of_linear_polynomial_nonnegative<u64, 1, 1, u64>(N, X, Y, M);
    ANS -= a[0][1] * (N - 1) - 2 * a[1][1];
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}