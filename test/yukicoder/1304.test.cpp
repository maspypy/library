#define PROBLEM "https://yukicoder.me/problems/no/1304"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/xor_range.hpp"

void solve() {
  LL(N, K, X, Y);
  VEC(ll, A, K);
  // (最後, 総xor)
  auto calc = [&](ll L, ll R) -> vvc<int> {
    vc<pi> dp;
    dp.eb(-1, 0);
    FOR(i, L, R) {
      vc<pi> newdp;
      for (auto&& [a, b]: dp) {
        FOR(i, K) {
          if (a == i) continue;
          newdp.eb(i, b ^ A[i]);
        }
      }
      swap(dp, newdp);
    }
    vvc<int> dat(K + 1);
    for (auto&& [a, b]: dp) {
      dat[a].eb(b);
      dat[K].eb(b);
    }
    return dat;
  };

  auto dpl = calc(0, N / 2);
  auto dpr = calc(N / 2, N);

  auto f = [&](vc<int>& A, vc<int>& B) -> ll {
    sort(all(A));
    sort(all(B));
    ll x = 0;

    for (auto&& b: B) {
      for (auto&& [lo, hi]: xor_range(b, X, Y + 1)) {
        x += LB(A, hi) - LB(A, lo);
      }
    }
    return x;
  };

  ll ANS = 0;
  FOR(k, K) ANS -= f(dpl[k], dpr[k]);
  ANS += f(dpl[K], dpr[K]);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
