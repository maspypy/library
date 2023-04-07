#define PROBLEM "https://yukicoder.me/problems/no/1728"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/function_on_divisors.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N, C);

  mint ANS = 0;
  // 回転
  Function_on_Divisors<mint> f(N);
  f.set_euler_phi();
  f.enumerate(
      [&](ll d, mint phi) -> void { ANS += phi * mint(C).pow(2 * N / d); });
  ANS += mint(C).pow(N) * mint(N);
  ANS /= mint(N + N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
