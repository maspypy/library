#include "other/random.hpp"
#include "nt/primetest.hpp"

template <typename Graph, int TRIAL = 0>
int chromatic_number(Graph& G) {
  assert(G.is_prepared());
  // O(N2^N)

  int N = G.N;
  vc<int> nbd(N);
  FOR(v, N) for (auto&& e : G[v]) nbd[v] |= 1 << e.to;

  // s の subset であるような独立集合の数え上げ
  vc<int> dp(1 << N);
  dp[0] = 1;
  FOR(v, N) FOR(s, 1 << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }

  vi pow(1 << N);
  auto solve_p = [&](int p) -> int {
    FOR(s, 1 << N) pow[s] = ((N - popcnt(s)) & 1 ? 1 : -1);
    FOR3(k, 1, N) {
      ll sum = 0;
      FOR(s, 1 << N) {
        pow[s] = pow[s] * dp[s];
        if (p) pow[s] %= p;
        sum += pow[s];
      }
      if (p) sum %= p;
      if (sum != 0) { return k; }
    }
    return N;
  };

  int ANS = 0;
  chmax(ANS, solve_p(0));

  FOR_(TRIAL) {
    RandomNumberGenerator RNG;
    int p;
    while (1) {
      p = RNG(1LL << 30, 1LL << 31);
      if (primetest(p)) break;
    }
    chmax(ANS, solve_p(p));
  }
  return ANS;
}
