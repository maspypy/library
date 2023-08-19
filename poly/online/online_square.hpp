#pragma once
#include "poly/ntt.hpp"

/*
query(i)：a[i]] を与えて (a^2)[i] を得る。
2^{17}：52ms
2^{18}：107ms
2^{19}：237ms
2^{20}：499ms
*/
template <class mint>
struct Online_Square {
  vc<mint> f, h, b0, b1;
  vvc<mint> fm;
  int p;

  Online_Square() : p(0) { assert(mint::can_ntt()); }

  mint query(int i, mint f_i) {
    assert(i == p);
    f.eb(f_i);
    int z = __builtin_ctz(p + 2), w = 1 << z, s;
    if (p + 2 == w) {
      b0 = f, b0.resize(2 * w);
      ntt(b0, false);
      fm.eb(b0.begin(), b0.begin() + w);
      FOR(i, 2 * w) b0[i] *= b0[i];
      s = w - 2;
      h.resize(2 * s + 2);
    } else {
      b0.assign(f.end() - w, f.end()), b0.resize(2 * w);
      ntt(b0, false);
      FOR(i, 2 * w) b0[i] *= mint(2) * fm[z][i];
      s = w - 1;
    }
    ntt(b0, true);
    FOR(i, s + 1) h[p + i] += b0[s + i];
    return h[p++];
  }
};
