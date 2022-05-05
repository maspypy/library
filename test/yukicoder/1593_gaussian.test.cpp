#define PROBLEM "https://yukicoder.me/problems/no/1593"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/gaussian_integers.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  auto res = solve_norm_equation(N * N);
  for (auto &&g: res) {
    if (g.x > 0 && g.y > 0) ++ANS;
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
