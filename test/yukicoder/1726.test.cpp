#define PROBLEM "https://yukicoder.me/problems/no/1726"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

void solve() {
  LL(N, M);
  ll ANS = 0;
  VEC(ll, P, N);
  VEC(pi, AB, N);
  VEC(pi, CD, M);

  HashMap<ll, 20> MP;

  FOR(2) {
    for (auto&& [a, b]: AB) a = -a;
    FOR(2) {
      for (auto&& [a, b]: AB) b = -b;
      MP.reset();
      FOR(i, N) FOR(j, M) {
        auto [a, b] = AB[i];
        auto [c, d] = CD[j];
        ll key = ((a - c) << 32) + (b - d);
        MP[key] += P[i];
      }
      MP.enumerate_all([&](auto k, auto v) { chmax(ANS, v); });
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
