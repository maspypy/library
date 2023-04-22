#define PROBLEM "https://yukicoder.me/problems/no/2276"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/fibonacci_search.hpp"

void solve() {
  LL(N);
  STR(S);
  vc<int> I;
  FOR(i, N) if (S[i] == '?') I.eb(i);

  auto f = [&](ll n) -> ll {
    assert(0 <= n && n <= len(I));
    FOR(i, n) S[I[i]] = 'A';
    FOR(i, n, len(I)) S[I[i]] = 'C';
    ll a = 0, res = 0;
    for (auto&& x: S) {
      if (x == 'A') ++a;
      if (x == 'C') res += a;
    }
    // print(S);
    // print(n, res);
    return res;
  };

  auto [x, fx] = fibonacci_search<ll, false>(f, 0, len(I) + 1);
  print(fx);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
