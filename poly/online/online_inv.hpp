#include "poly/online/online_division.hpp"

// query(i)：f[i] を与えて (f^{-1})[i] を得る。
// f[0] == 1 を仮定する。
template <typename mint>
struct Online_Inv {
  Online_Division<mint> X;

  mint query(int i, mint f_i) {
    mint g_i = (i == 0 ? mint(1) : mint(0));
    return X.query(i, g_i, f_i);
  }
};
