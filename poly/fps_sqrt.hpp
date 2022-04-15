#include "poly/fps_inv.hpp"
#include "mod/mod_sqrt.hpp"
template <typename mint>
vc<mint> fps_sqrt(vc<mint>& f) {
  assert(f[0] == mint(1));
  int n = len(f);
  vc<mint> R = {1};
  while (len(R) < n) {
    int m = min(2 * int(len(R)), n);
    R.resize(m);
    vc<mint> tmp = {f.begin(), f.begin() + m};
    tmp = convolution(tmp, fps_inv(R));
    tmp.resize(m);
    FOR(i, m) R[i] += tmp[i];
    mint c = mint(1) / mint(2);
    FOR(i, len(R)) R[i] *= c;
  }
  R.resize(n);
  return R;
}

template <typename mint>
vc<mint> fps_sqrt_any(vc<mint>& f) {
  int n = len(f);
  int d = n;
  FOR_R(i, n) if (f[i] != 0) d = i;
  if (d == n) return f;
  if (d & 1) return {};
  mint y = f[d];
  mint x = mod_sqrt(y);
  if (x * x != y) return {};
  mint c = mint(1) / y;
  vc<mint> g(n - d);
  FOR(i, n - d) g[i] = f[d + i] * c;
  g = fps_sqrt(g);
  FOR(i, len(g)) g[i] *= x;
  g.resize(n);
  FOR_R(i, n) {
    if (i >= d / 2)
      g[i] = g[i - d / 2];
    else
      g[i] = 0;
  }
  return g;
}
