#define PROBLEM "https://yukicoder.me/problems/no/1977"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/doubling.hpp"
#include "alg/monoid/add.hpp"

using GRP = Monoid_Add<ll>;

void solve() {
  LL(N, M, L);
  VEC(ll, A, N);
  Doubling<GRP, 50> X(N);
  FOR(i, N) {
    int j = (i + L) % N;
    X.add(i, j, A[j]);
  }
  X.build();

  const ll INF = 1LL << 60;
  ll ANS = -INF;

  FOR(i, N) {
    ll s0 = i;
    ll s1 = L / N * N + i;
    while (s0 >= L) s0 -= N;
    while (s1 >= L) s1 -= N;
    ll a0 = (N * M - 1 - s0) / L;
    ll a1 = (N * M - 1 - s1) / L;
    if (s0 >= 0) chmax(ANS, X.calc(i, a0).se + A[i]);
    if (s1 >= 0) chmax(ANS, X.calc(i, a1).se + A[i]);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
