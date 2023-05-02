#include "poly/convolution.hpp"

template <typename mint>
struct Polynomial : vector<mint> {
  using vector<mint>::vector;
  using Poly = Polynomial;
  vc<mint> NTT;

  Poly &operator*=(const Poly &r) {
    vc<mint> f = convolution(*this, r);
    return *this = {f.begin(), f.end()};
  }
};
