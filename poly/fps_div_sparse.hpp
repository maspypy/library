
// f/g ただし g は sparse
template <typename mint>
vc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {
  if (g[0] != mint(1)) {
    mint cf = g[0].inverse();
    for (auto&& x: f) x *= cf;
    for (auto&& x: g) x *= cf;
  }

  vc<pair<int, mint>> dat;
  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);
  FOR(i, len(f)) {
    for (auto&& [j, x]: dat) {
      if (i >= j) f[i] += x * f[i - j];
    }
  }
  return f;
}