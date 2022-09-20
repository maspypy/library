#define PROBLEM "https://yukicoder.me/problems/no/1201"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/floor_sum_of_linear.hpp"

const int mod = 1'000'000'007;

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);

  i128 ANS = 0;
  for (auto&& a: A) {
    for (auto&& b: B) {
      // FOR(k, 1, b + 1) ANS += mint(floor(a * k, b));
      i128 x = floor_sum_of_linear(1, b + 1, a, 0, b);
      ANS += x;
    }
  }
  ANS += ANS;
  ANS %= mod;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
