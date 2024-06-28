#define PROBLEM "https://yukicoder.me/problems/no/2801"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution.hpp"
#include "poly/online/online_square.hpp"

/*
すごい.

F(x) = x + Mx^2 + O(x^3) であって
F(x+x^2)=F(x)+F(x)^2
を満たすものを求める

F(x)=xG(x)
(x+x^2)G(x+x^2)=xG(x)+x^2G(x)^2

(1+x)G(x+x^2)=G(x)+xG(x)^2

[x^{n+1}]
LHS: G[n+1] + (n+1)G[n] + (G[0], ..., G[n-1])
RHS: G[n+1] + 2G[n] + ...

H(x):=G(x+x^2)

G(x)=1+xA(x)
G(x)^2=1+2xA(x)+x^2A(x)^2
*/

using mint = modint998;

void solve() {
  LL(N, M);
  ++N;

  Online_Square<mint> SQ;

  vc<mint> G(N + 1);
  vc<mint> A(N);
  vc<mint> AA(N);

  vc<mint> H(N + 1);

  auto dfs = [&](auto& dfs, int L, int R) -> vc<mint> {
    /*
    return: sum G[i](x+x^2)^{i-L}
    dfs call の時点で、G[0:L) の H[L+1:R+1) への寄与は計算済であるようにする
    */
    if (R == L + 1) {
      mint ans = [&]() -> mint {
        if (L == 0) return 1;
        if (L == 1) return M;
        // (1+x)H(x)=G(x)+xG(x)^2
        // [x^{L+1}]x(1+xA)^2
        mint lhs = H[L + 1] + H[L];
        mint rhs = AA[L - 2];
        if (L == 2) SHOW(lhs, rhs);
        return (rhs - lhs) * inv<mint>(L - 1);
      }();
      G[L] = ans;
      H[L] += ans;
      H[L + 1] += mint(L) * ans;
      if (L > 0) A[L - 1] = ans, AA[L - 1] = SQ.query(L - 1, A[L - 1]);
      return {ans};
    }
    int M = (L + R) / 2;
    vc<mint> f = dfs(dfs, L, M);
    // f(x)(x+x^2)^L を [M+1,R+1) に反映させる
    // [M-L+1,R-L+1) of f(x)(1+x)^L
    {
      vc<mint> g(R - L + 1);
      FOR(i, R - L + 1) g[i] = C<mint>(L, i);
      g = convolution<mint>(f, g);
      g = {g.begin() + (M - L + 1), g.end()};
      FOR(i, M + 1, R + 1) { H[i] += g[i - (M + 1)]; }
      SHOW(L, M, R, g);
    }
    vc<mint> g = dfs(dfs, M, R);
    // f(x) <- f(x) + g(x)(x+x^2)^{M-L}
    vc<mint> h(2 * (M - L) + 1);
    FOR(i, M - L + 1) h[M - L + i] = C<mint>(M - L, i);
    g = convolution<mint>(g, h);
    if (len(f) < len(g)) swap(f, g);
    FOR(i, len(g)) f[i] += g[i];
    return f;
  };
  dfs(dfs, 0, N);
  print(G[N - 1]);
}

signed main() {
  solve();
  return 0;
}
