#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/random_monge.hpp"
#include "convex/alien.hpp"
#include "convex/monge/monge_dp_update.hpp"
#include "convex/monge/monge_shortest_path.hpp"

ll path_cost(const vc<int>& path, const vvc<ll>& A) {
  ll res = 0;
  FOR(i, len(path) - 1) {
    int l = path[i], r = path[i + 1];
    assert(l < r);
    res += A[l][r];
  }
  return res;
}

void test_one(int N) {
  vvc<ll> A = random_monge_matrix(N + 1, N + 1);

  auto cost = [&](int l, int r) -> ll {
    assert(0 <= l && l < r && r <= N);
    return A[l][r];
  };

  auto solve = [&](ll penalty, bool minimize_cnt) -> pair<vc<ll>, vc<int>> {
    return monge_shortest_path<ll>(
        N, [&](int l, int r) -> ll { return cost(l, r) + penalty; },
        minimize_cnt);
  };

  vc<ll> dp(N + 1, infty<ll>);
  dp[0] = 0;

  FOR(K, 1, N + 1) {
    dp = monge_dp_update<ll>(N, dp, cost);
    ll expected = dp[N];
    // alien_trick requires lo: cnt > K, hi: cnt <= K.
    // Since max path length is N, K == N has no cnt > K side.
    if (K == N) continue;

    ll lo = -1000000;
    ll hi = 1000000;

    ll got = alien_trick<ll>(N, K, lo, hi, solve);
    assert(got == expected);

    auto [got_restore, path] =
        alien_trick_restore<ll>(N, K, lo, hi, solve, cost);
    assert(got_restore == expected);
    assert(len(path) == K + 1);
    assert(path[0] == 0);
    assert(path.back() == N);
    FOR(i, len(path) - 1) assert(path[i] < path[i + 1]);

    ll restored_cost = path_cost(path, A);
    assert(restored_cost == expected);
  }
}

void test() {
  FOR(N, 1, 40) { FOR(500) test_one(N); }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}