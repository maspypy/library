#include "poly/fps_inv.hpp"
template <typename mint>
pair<vc<mint>, vc<mint>> poly_divmod(vc<mint> f, vc<mint> g) {
  assert(g.back() != 0);
  if (len(f) < len(g)) { return {{}, f}; }
  auto rf = f, rg = g;
  reverse(all(rf)), reverse(all(rg));
  ll deg = len(rf) - len(rg) + 1;
  rf.resize(deg), rg.resize(deg);
  rg = fps_inv(rg);
  auto q = convolution(rf, rg);
  q.resize(deg);
  reverse(all(q));
  auto h = convolution(q, g);
  FOR(i, len(f)) f[i] -= h[i];
  while (len(f) > 0 && f.back() == 0) f.pop_back();
  return {q, f};
}
