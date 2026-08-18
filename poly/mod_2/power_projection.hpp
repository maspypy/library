#include "ds/bit_array.hpp"
#include "poly/mod_2/convolution.hpp"

// ANS[i] = sum_j wt[j] [x^j] f(x)^i, 0 <= i <= m
Bit_Array power_projection(Bit_Array wt, Bit_Array f, int m) {
  assert(f.size() == wt.size());
  assert(m >= 0);

  int sz = f.size();
  if (sz == 0) return Bit_Array(m + 1);

  int N = sz - 1;

  // g[N-j] = wt[j]
  Bit_Array g(sz);
  FOR(j, sz) g[N - j] = wt[j];

  Bit_Array ANS(m + 1);
  auto dfs = [&](auto& dfs, Bit_Array f, Bit_Array g, int m, int i0,
                 int step) -> void {
    int N = f.size() - 1;
    /*
    [x^N] f(x)^i g(x), 0 <= i <= m を
    ANS[i0], ANS[i0+step], ... に書きこむ
    */
    if (m == 0) {
      ANS[i0] = g[N];
      return;
    }

    int n = N / 2;
    {  // even case
      Bit_Array nxtf = f.slice(0, n + 1);
      Bit_Array nxtg(n + 1);
      FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];

      dfs(dfs, nxtf, nxtg, m / 2, i0, step * 2);
    }
    {  // odd case
      g = convolution(f, g);
      g.resize(N + 1);

      Bit_Array nxtf = f.slice(0, n + 1);
      Bit_Array nxtg(n + 1);
      FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];

      dfs(dfs, nxtf, nxtg, (m - 1) / 2, i0 + step, step * 2);
    }
  };

  dfs(dfs, f, g, m, 0, 1);
  return ANS;
}