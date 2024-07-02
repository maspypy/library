#include "mod/crt3.hpp"
#include "poly/online/online_convolution.hpp"

template <class mint>
struct Online_Convolution_Garner {
  static constexpr int p0 = 167772161;
  static constexpr int p1 = 469762049;
  static constexpr int p2 = 754974721;
  using mint0 = modint<p0>;
  using mint1 = modint<p1>;
  using mint2 = modint<p2>;
  Online_Convolution<mint0> OC0;
  Online_Convolution<mint1> OC1;
  Online_Convolution<mint2> OC2;
  int p;
  Online_Convolution_Garner() : p(0) {}

  mint query(int i, mint f_i, mint g_i) {
    assert(i == p);
    p++;
    u64 x0 = OC0.query(i, f_i.val, g_i.val).val;
    u64 x1 = OC1.query(i, f_i.val, g_i.val).val;
    u64 x2 = OC2.query(i, f_i.val, g_i.val).val;
    return CRT3<mint, p0, p1, p2>(x0, x1, x2);
  }
};
