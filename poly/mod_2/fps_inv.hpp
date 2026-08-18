#include "poly/mod_2/convolution.hpp"

Bit_Array fps_inv(const Bit_Array& F) {
  if (len(F) == 0) return F;
  assert(F[0]);
  auto dfs = [&](auto& dfs, int n) -> Bit_Array {
    // 1/f を [0,n] で求める
    if (n == 0) {
      return Bit_Array(1, 1);
    }
    int m = n / 2;
    Bit_Array g = dfs(dfs, m);
    Bit_Array gg(n + 1);
    FOR(i, g.size()) {
      if (2 * i <= n) gg[2 * i] = g[i];
    }
    Bit_Array h = F.slice(0, n + 1);
    g = convolution(gg, h);
    g.resize(n + 1);
    return g;
  };
  return dfs(dfs, F.size() - 1);
}