#include "nt/primetable.hpp"
#include "nt/primesum.hpp"

// factor type: 降順 270 -> (3,1,1)
// N=10^9: 1324 種類, 0.4sec
// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d
map<vc<int>, ll> count_by_factor_type(ll N) {
  ll sqN = sqrtl(N);
  auto P = primetable<int>(sqN);
  PrimeSum<ll> X(N);
  X.calc_count();

  // 1 and prime
  map<vc<int>, ll> ANS;
  ANS[vc<int>()] = 1;
  if (X[N] > 0) ANS[vc<int>({1})] = X[N];

  auto add = [&](vc<int> F, int k) -> vc<int> {
    int p = len(F);
    F.eb(k);
    while (0 < p && F[p - 1] < F[p]) { swap(F[p - 1], F[p]), --p; }
    return F;
  };

  // t = up_i^k のときに
  auto dfs = [&](auto& dfs, ll t, ll i, ll k, vc<int> U) -> void {
    // U * primes を追加する
    vc<int> nxt1 = add(U, k + 1);
    ANS[nxt1]++;
    vc<int> Uk = add(U, k);
    vc<int> nxt2 = add(Uk, 1);
    ll cnt = X[N / t] - X[P[i]];
    if (cnt > 0) ANS[nxt2] += X[N / t] - X[P[i]];
    ll lim = sqrtl(double(N) / t);
    if (P[i] <= lim) { dfs(dfs, t * P[i], i, k + 1, U); }
    FOR(j, i + 1, len(P)) {
      if (P[j] > lim) break;
      dfs(dfs, t * P[j], j, 1, Uk);
    }
  };
  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, {});
  return ANS;
}