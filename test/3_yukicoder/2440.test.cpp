#define PROBLEM "https://yukicoder.me/problems/no/2440"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/floor_sum_of_linear.hpp"
#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  U64(N, D, M, S);
  B b = 1;
  FOR(S) b += b;

  /*
  差が 1 未満
  |1/D - M/2^S|n < 1
  |2^S-MD|n < 2^SD
  */
  B r = b * B(D);
  B l = b - B(M) * B(D);
  if (l < 0) l = -l;

  auto check = [&](ll n) -> bool { return l * B(n) < r; };

  N = binary_search(check, 0, N + 1);
  u64 X = floor_sum_of_linear<u64, u128>(0, N + 1, 1, 0, D);
  u64 Y = floor_sum_of_linear<u64, u128>(0, N + 1, M, 0, u128(1) << S);
  if (Y - X > N) swap(X, Y);
  u64 ANS = Y - X;
  ANS = N - ANS;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
