#include "poly/fps_inv.hpp"

template <typename mint>
struct SubproductTree {
  int m;
  int sz;
  vc<vc<mint>> T;
  SubproductTree(const vc<mint>& x) {
    m = len(x);
    sz = 1;
    while (sz < m) sz *= 2;
    T.resize(2 * sz);
    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};
    FOR3_R(i, 1, sz) T[i] = convolution(T[2 * i], T[2 * i + 1]);
  }

  vc<mint> mid_prod(vc<mint>& a, vc<mint>& b) {
    assert(len(a) >= len(b) && !b.empty());
    if (min(len(b), len(a) - len(b) + 1) <= 60) {
      vc<mint> res(len(a) - len(b) + 1);
      FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];
      return res;
    }
    int n = 1 << std::__lg(2 * len(a) - 1);
    vc<mint> fa(n), fb(n);
    std::copy(a.begin(), a.end(), fa.begin());
    std::copy(b.rbegin(), b.rend(), fb.begin());
    ntt(fa, 0), ntt(fb, 0);
    FOR(i, n) fa[i] *= fb[i];
    ntt(fa, 1);
    fa.resize(len(a));
    fa.erase(fa.begin(), fa.begin() + len(b) - 1);
    return fa;
  }

  vc<mint> evaluation(vc<mint>& f) {
    int n = len(f);
    f.resize(2 * n - 1);
    vc<vc<mint>> g(2 * sz);
    g[1] = T[1];
    g[1].resize(n);
    g[1] = fps_inv(g[1]);
    g[1] = mid_prod(f, g[1]);
    g[1].resize(sz);

    FOR3(i, 1, sz) {
      g[2 * i] = mid_prod(g[i], T[2 * i + 1]);
      g[2 * i + 1] = mid_prod(g[i], T[2 * i]);
    }
    vc<mint> vals(m);
    FOR(i, m) vals[i] = g[sz + i][0];
    return vals;
  }

  vc<mint> interpolation(vc<mint>& y) {
    assert(len(y) == m);
    vc<mint> a(m);
    FOR(i, m) a[i] = T[1][m - i - 1] * (i + 1);

    a = evaluation(a);
    vc<vc<mint>> t(2 * sz);
    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};
    FOR3_R(i, 1, sz) {
      t[i] = convolution(t[2 * i], T[2 * i + 1]);
      auto tt = convolution(t[2 * i + 1], T[2 * i]);
      FOR(k, len(t[i])) t[i][k] += tt[k];
    }
    t[1].resize(m);
    reverse(all(t[1]));
    return t[1];
  }
};

template<typename mint>
vc<mint> multipoint_eval(vc<mint>& f, vc<mint>& x){
  SubproductTree<mint> F(x);
  return F.evaluation(f);
}

template<typename mint>
vc<mint> multipoint_interpolate(vc<mint>& x, vc<mint>& y){
  SubproductTree<mint> F(x);
  return F.interpolation(y);
}
