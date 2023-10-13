#include "enumerate/bits.hpp"
#include "graph/base.hpp"

// 頂点集合ごとにサイクルを数える. N^22^N.
// サイクルの長さは 3 以上（単純グラフを仮定）
template <typename T, typename GT>
vc<T> count_cycle(GT& G) {
  const int N = G.N;
  assert(N <= 32 && !G.is_directed());
  vc<u32> nbd(N);
  FOR(v, N) for (auto& e: G[v]) nbd[v] |= u32(1) << (e.to);

  vc<T> cyc(1 << N);
  for (int v = 0; v < N; ++v) {
    vc<T> dp(v << v);
    for (int w = 0; w < v; ++w) {
      if (nbd[v] >> w & 1) dp[(v << w) + w] = 1;
    }
    const u32 mask = (u32(1) << v) - 1;
    for (u32 s = 0; s < (u32(1) << v); ++s) {
      enumerate_bits_32(s, [&](int a) -> void {
        enumerate_bits_32(nbd[a] & mask & (~s), [&](int b) -> void {
          dp[v * (s | 1 << b) + b] += dp[v * s + a];
        });
        if (popcnt(s) >= 2 && nbd[a] >> v & 1) cyc[s | 1 << v] += dp[v * s + a];
      });
    }
  }
  for (auto& x: cyc) x /= T(2);
  return cyc;
}
