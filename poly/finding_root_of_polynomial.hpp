#include "poly/poly_mod_pow.hpp"
#include "poly/poly_gcd.hpp"
#include "random/base.hpp"

// F(a)=0 を満たす a 全体を返す
// 昇順にソートして返すことに
template <typename mint>
vc<mint> finding_root_of_polynomial(vc<mint> F) {
  while (len(F) && F.back() == mint(0)) POP(F);
  assert(!F.empty());

  const int p = mint::get_mod();
  assert(p % 2 == 1);

  vc<mint> g = {0, 1};
  g = poly_mod_pow(g, p, F);
  if (len(g) <= 2) g.resize(2);
  g[1] -= 1;
  F = poly_gcd(F, g);

  // F は相異なる 1 次式の積
  vc<mint> ANS;
  auto dfs = [&](auto& dfs, vc<mint> F) -> void {
    if (len(F) == 1) return;
    if (len(F) == 2) {
      mint a = F[0], b = F[1];
      // a+bx=0
      ANS.eb((-a) / b);
      return;
    }
    vc<mint> g(2);
    g[0] = RNG(0, p), g[1] = 1;
    vc<mint> h = poly_mod_pow(g, (p - 1) / 2, F);
    if (h.empty()) { return dfs(dfs, F); }
    h[0] -= 1;
    vc<mint> f1 = poly_gcd(F, h);
    vc<mint> f2 = poly_divmod(F, f1).fi;
    dfs(dfs, f1), dfs(dfs, f2);
  };
  dfs(dfs, F);
  sort(all(ANS));
  return ANS;
}