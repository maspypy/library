#define PROBLEM "https://yukicoder.me/problems/no/1262"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/euler_phi.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, M);
  /*
  auto f = [&](ll a, ll b) -> ll { return gcd(a, b) - 1; };
  ll ANS = 0;
  FOR(i, M) FOR(j, 1, A[i] + 1) { ANS += f(A[i], j); }
  print(ANS);
  */
  auto phi = euler_phi_table(N);
  vi F(N + 1);
  FOR(d, 1, N + 1) {
    ll x = d;
    while (x <= N) {
      F[x] += phi[x / d] * d;
      x += d;
    }
  }
  ll ANS = 0;
  for (auto&& a: A) ANS += F[a] - a;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
