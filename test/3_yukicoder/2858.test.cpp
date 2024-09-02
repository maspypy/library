#define PROBLEM "https://yukicoder.me/problems/no/2858"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/interpolate_periodic_sequence.hpp"
#include "string/manacher.hpp"

void solve() {
  LL(N, M);
  STR(S);
  vi A = {0};
  FOR(k, 1, 6) {
    string x;
    FOR(k) x += S;
    ll ans = 0;
    for (auto& [l, r]: manacher(x)) { chmax(ans, r - l); }
    A.eb(ans);
  }
  Interpolate_Difference_Periodic_Sequence<ll> P(A);

  ll ANS = binary_search([&](ll n) -> bool { return P[n] >= M; }, M + 1, 0, 0);
  if (ANS == M + 1) return print(-1);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
