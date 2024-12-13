#include "graph/base.hpp"
#include "random/base.hpp"
#include "nt/primetest.hpp"
#include "poly/multipoint.hpp"
#include "setfunc/power_projection_of_sps.hpp"

// O(N2^N)
// N=23: https://codeforces.com/contest/908/problem/H
// 上の問題では乱択がめちゃ高速
template <typename Graph, int TRIAL = 0>
int chromatic_number(Graph& G) {
  assert(G.is_prepared());

  int N = G.N;
  vc<int> nbd(N);
  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= 1 << e.to;

  // s の subset であるような独立集合の数え上げ
  vc<int> dp(1 << N);
  dp[0] = 1;
  FOR(v, N) FOR(s, 1 << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }

  vi pow(1 << N);
  auto solve_p = [&](int p) -> int {
    FOR(s, 1 << N) pow[s] = ((N - popcnt(s)) & 1 ? 1 : -1);
    FOR(k, 1, N) {
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

  FOR(TRIAL) {
    int p;
    while (1) {
      p = RNG(1LL << 30, 1LL << 31);
      if (primetest(p)) break;
    }
    chmax(ANS, solve_p(p));
  }
  return ANS;
}

// O(N^22^N)
template <typename mint, int MAX_N>
vc<mint> chromatic_polynomial(Graph<int, 0> G) {
  int N = G.N;
  assert(N <= MAX_N);
  vc<int> ng(1 << N);
  for (auto& e: G.edges) {
    int i = e.frm, j = e.to;
    ng[(1 << i) | (1 << j)] = 1;
  }
  FOR(s, 1 << N) {
    if (ng[s]) {
      FOR(i, N) { ng[s | 1 << i] = 1; }
    }
  }
  vc<mint> f(1 << N);
  FOR(s, 1 << N) {
    if (!ng[s]) f[s] = 1;
  }
  vc<mint> wt(1 << N);
  wt.back() = 1;
  vc<mint> Y = power_projection_of_sps<mint, MAX_N>(wt, f, N + 1);
  vc<mint> X(N + 1);
  FOR(i, N + 1) X[i] = i;
  return multipoint_interpolate<mint>(X, Y);
}
