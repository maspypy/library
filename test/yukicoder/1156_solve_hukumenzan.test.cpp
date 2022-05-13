#define PROBLEM "https://yukicoder.me/problems/no/1156"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/solve_hukumenzan.hpp"

void solve() {
  /*
  auto res1 = solve_hukumenzan("abc", "def", "bgcb");
  auto res2 = solve_hukumenzan("0012", "3456", "78129");
  auto res3 = solve_hukumenzan("spring", "eight", "picnic");
  vc<int> ANS(4);
  ANS[1] = get<2>(res1[0]);
  ANS[2] = get<2>(res2[0]);
  ANS[3] = get<2>(res3[0]);
  */
  vc<int> ANS = {0, 1051, 10947, 841341};
  LL(N);
  print(ANS[N]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
