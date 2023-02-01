#define PROBLEM "https://yukicoder.me/problems/no/2167"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"
#include "random/base.hpp"
#include "random/hash_pair.hpp"

HashMap<ll> MP;

void solve() {
  MP.reset();
  LL(N, LIM);
  VEC(ll, A, N);

  vi F = {1, 2};
  while (len(F) <= N) F.eb(F[len(F) - 2] + F[len(F) - 1]);
  F.resize(N); // 価値
  auto Ac = cumsum<ll>(F);

  auto dfs = [&](auto& dfs, int n, ll val) -> ll {
    ll key = hash_pair(pair<ll, ll>{n, val});

    if (MP.count(key)) return MP[key];
    // 価値 -> n 個までで達成するための最小重さ
    if (val <= 0) return 0;
    if (val > Ac[n]) return infty<ll>;
    ll v = F[n - 1], w = A[n - 1];
    ll x1 = dfs(dfs, n - 1, val);
    ll x2 = dfs(dfs, n - 1, val - v) + w;
    ll x = min(x1, x2);
    chmin(x, infty<ll>);
    return (MP[key] = x);
  };

  ll ANS = binary_search(
      [&](ll val) -> bool { return dfs(dfs, N, val) <= LIM; }, 0, infty<ll>);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
