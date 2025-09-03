#define PROBLEM "https://yukicoder.me/problems/no/1262"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/euler_phi.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, M);
  auto phi = euler_phi_table<int>(N);
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
  solve();
  return 0;
}