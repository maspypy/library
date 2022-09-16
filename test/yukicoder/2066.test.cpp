#define PROBLEM "https://yukicoder.me/problems/no/2066"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/floor_sum_of_linear.hpp"

void solve() {
  LL(P, Q, K);
  auto check = [&](ll N) -> bool {
    // Px+Qy<=N かつ 0 <= x < Q が K 個以上
    ll LIM = min(Q, N / P + 1);
    // 0 <= x < LIM で、floor(N-Px,Q)+1 を和
    return floor_sum_of_linear(0, LIM, -P, N + Q, Q) - 1 >= K;
  };

  ll g = gcd(P, Q);
  P /= g, Q /= g;

  ll ANS = binary_search(check, (P + Q) * (K + 1), 0);
  ANS *= g;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
