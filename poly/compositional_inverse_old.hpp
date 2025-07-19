#include "poly/differentiate.hpp"
#include "poly/fps_div.hpp"

// O(N ^ 2)
template <typename mint>
vc<mint> compositional_inverse_old(const vc<mint>& F) {
  const int N = len(F);
  if (N == 0) return {};
  assert(F[0] == mint(0));
  if (N == 1) return F;
  assert(F[0] == mint(0) && F[1] != mint(0));
  vc<mint> DF = differentiate(F);

  vc<mint> G(2);
  G[1] = mint(1) / F[1];
  while (len(G) < N) {
    // G:= G(x)-(F(G(x))-x)/DF(G(x))
    int n = len(G);
    vc<mint> G1, G2;
    {
      vc<mint> FF(2 * n), GG(2 * n), DFF(n);
      FOR(i, min<int>(len(F), 2 * n)) FF[i] = F[i];
      FOR(i, min<int>(len(DF), n)) DFF[i] = DF[i];
      FOR(i, n) GG[i] = G[i];
      G1 = composition(FF, GG);
      G2 = composition(DFF, G);
    }
    G1 = {G1.begin() + n, G1.end()};
    G1 = fps_div(G1, G2);
    G.resize(2 * n);
    FOR(i, n) G[n + i] -= G1[i];
  }
  G.resize(N);
  return G;
}