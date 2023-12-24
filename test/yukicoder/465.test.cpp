#define PROBLEM "https://yukicoder.me/problems/no/465"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/palindrome_decomposition_dp.hpp"

using ARR = array<int, 3>;

void solve() {
  STR(S);
  int N = len(S);

  auto add = [&](ARR& x, ARR y) -> ARR {
    return {x[0] + y[0], x[1] + y[1], x[2] + y[2]};
  };
  auto mul_x = [&](ARR& x) -> ARR { return {0, x[0], x[1]}; };

  auto dp1
      = palindrome_decomposition_dp<ARR>(S, {0, 0, 0}, {1, 0, 0}, add, mul_x);
  reverse(all(S));
  auto dp2
      = palindrome_decomposition_dp<ARR>(S, {0, 0, 0}, {1, 0, 0}, add, mul_x);
  reverse(all(S));
  vc<int> PA(N);
  FOR(n, N) { PA[n] = dp2[n][1]; }
  PA = cumsum<int>(PA);
  ll ANS = 0;
  FOR(i, N + 1) ANS += dp1[i][2] * ll(PA[N - i]);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}