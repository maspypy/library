#include "setfunc/online/oniline_subset_zeta.hpp"
#include "setfunc/online/oniline_subset_mobius.hpp"

template <typename T>
struct Online_Or_Convolution {
  Online_Subset_Zeta<T> X1, X2;
  Online_Subset_Mobius<T> Y;
  Online_Or_Convolution(int LOG) : X1(LOG), X2(LOG), Y(LOG) {}
  // set a[i] and b[i], return conv(a,b)[i]
  T set(int i, T ai, T bi) { return Y.set(i, X1.set(i, ai) * X2.set(i, bi)); }
  // assume a[i],b[i], return zeta(a)[i]. not increment the pointer.
  T assume(int i, T ai, T bi) { return Y.assume(i, X1.assume(i, ai) * X2.assume(i, bi)); }
};
