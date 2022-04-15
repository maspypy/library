#include "nt/factor.hpp"
#include "nt/divisors.hpp"

template <typename T>
pair<vi, vc<T>> multiplier_mobius_on_divisors(ll N, function<ll(T)> f) {
  /*
  約数ごとの集計 → gcdごとの集計に変換
  https://codeforces.com/contest/820/problem/E
  */
  auto pf = factor(N);
  auto div = divisors(N);
  ll n = len(div);
  vi DP(n);
  FOR(i, n) DP[i] = f(div[i]);

  ll k = 1;
  for (auto&& [p, e]: pf) {
    ll mod = k * (e + 1);
    FOR(i, len(div) / mod) {
      FOR(j, mod - k) { DP[mod * i + j] -= DP[mod * i + j + k]; }
    }
    k *= (e + 1);
  }
  return {div, DP};
}
