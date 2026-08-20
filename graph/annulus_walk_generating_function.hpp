#include "poly/poly_taylor_shift.hpp"

// return: P,Q such that (# of walk s->t of step K)=[x^K]P(x)/Q(x)
// stay==0: O(N)time
// stay!=0: O(NlogN)time
template <typename mint>
pair<vc<mint>, vc<mint>> annulus_walk_generating_function(
    int N, int s, int t, mint stay) {
  int k = bmod<int>(t - s, N);
  auto get_D = [&](int m) -> vc<mint> {
    if (m < 0) return vc<mint>{mint(0)};
    vc<mint> f(m + 1);
    for (int j = 0; 2 * j <= m; ++j) {
      f[2 * j] = (j & 1 ? -mint(1) : mint(1)) * C<mint>(m - j, j);
    }
    return f;
  };

  vc<mint> P(N), Q(N + 1);

  auto add = [&](vc<mint>& f, const vc<mint>& g, int shift, mint coef) {
    FOR(i, len(g)) {
      if (i + shift >= len(f)) break;
      f[i + shift] += coef * g[i];
    }
  };

  add(P, get_D(N - k - 1), k, 1);
  add(P, get_D(k - 1), N - k, 1);
  add(Q, get_D(N), 0, 1);
  add(Q, get_D(N - 2), 2, -1);
  Q[N] -= 2;
  auto conv = [&](vc<mint>& f) -> void {
    reverse(all(f));
    f = poly_taylor_shift<mint>(f, -stay);
    reverse(all(f));
  };
  if (stay != 0) {
    conv(P), conv(Q);
  }
  return {P, Q};
}
