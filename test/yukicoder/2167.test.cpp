#define PROBLEM "https://yukicoder.me/problems/no/2167"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"
#include "random/base.hpp"
#include "random/hash_vector.hpp"

HashMap<ll> MP;

void solve() {
  MP.reset();
  LL(N, LIM);
  VEC(ll, A, N);

  vi F = {1, 2};
  while (len(F) <= N) F.eb(F[len(F) - 2] + F[len(F) - 1]);
  F.resize(N); // 価値
  auto Ac = cumsum<ll>(F);

  const ll INF = 1LL << 60;
  auto dfs = [&](auto& dfs, int n, ll val) -> ll {
    ll key = hash_pair(n, val);
    
    if (MP.count(key)) return MP[key];
    // 価値 -> n 個までで達成するための最小重さ
    if (val <= 0) return 0;
    if (val > Ac[n]) return INF;
    ll v = F[n - 1], w = A[n - 1];
    ll x1 = dfs(dfs, n - 1, val);
    ll x2 = dfs(dfs, n - 1, val - v) + w;
    ll x = min(x1, x2);
    chmin(x, INF);
    return (MP[key] = x);
  };

  ll ANS = binary_search(
      [&](ll val) -> bool { return dfs(dfs, N, val) <= LIM; }, 0, INF);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
