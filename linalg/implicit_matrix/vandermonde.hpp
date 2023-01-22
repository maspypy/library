#include "poly/multipoint.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/fps_div.hpp"

// transpose = 0：g[i] = sum pow(i,j) f[j]
// transpose = 1：g[i] = sum pow(j,i) f[j]
template <typename mint>
vc<mint> vandermonde(vc<mint> f, bool transpose, bool inverse) {
  int N = len(f);
  using poly = vc<mint>;
  if (!transpose) {
    vc<mint> x(N);
    FOR(i, N) x[i] = mint(i);
    if (!inverse) { return multipoint_eval(f, x); }
    if (inverse) { return multipoint_interpolate(x, f); }
  }
  if (!inverse) {
    vc<pair<poly, poly>> dat(N);
    FOR(j, N) {
      poly a{f[j]}, b{mint(1), mint(-j)};
      dat[j] = {a, b};
    }
    auto [num, den] = sum_of_rationals(dat);
    num.resize(N);
    return fps_div(num, den);
  }
  // こっちは multipoint evalation でできると思われるが、未実装
  assert(0);
  return poly{};
}