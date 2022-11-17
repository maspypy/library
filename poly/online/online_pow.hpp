#include "poly/online/online_division.hpp"

// query(i)：f[i] を与えて (f^K)[i] を得る。
// f[0] == 1 を仮定する。
template <typename mint>
struct Online_Pow {
  vc<mint> f, F;
  vc<mint> g; // f'/f
  const mint K;
  Online_Division<mint> X;
  Online_Convolution<mint> Y;

  Online_Pow(mint K) : K(K) {}

  mint query(int i, mint f_i) {
    assert(i == len(f));
    f.eb(f_i);
    if (i == 0) {
      assert(f_i == mint(1));
      F.eb(f_i);
      return F[0];
    }
    g.eb(X.query(i - 1, f[i] * mint(i), f[i - 1]));
    F.eb(Y.query(i - 1, g[i - 1], F[i - 1]) * K * inv<mint>(i));
    return F[i];
  }
};
