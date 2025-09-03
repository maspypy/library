#define PROBLEM "https://yukicoder.me/problems/no/465"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/palindrome_decomposition_dp.hpp"

using ARR = array<int, 3>;

void solve() {
  STR(S);
  int N = len(S);

  vc<ARR> dp_init(N + 1);
  dp_init[0] = {1, 0, 0};
  ARR gdp_unit = {0, 0, 0};
  auto F = [&](int i, ARR a, ARR g) -> ARR {
    a[1] += g[0], a[2] += g[1];
    return a;
  };
  auto G = [&](int i, ARR g, ARR a) -> ARR {
    a[0] += g[0], a[1] += g[1], a[2] += g[2];
    return a;
  };

  auto dp1 = palindrome_decomposition_dp<ARR, ARR>(S, dp_init, gdp_unit, F, G);
  reverse(all(S));
  auto dp2 = palindrome_decomposition_dp<ARR, ARR>(S, dp_init, gdp_unit, F, G);
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