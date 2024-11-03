
#include "linalg/frobenius.hpp"
#include "mod/modint.hpp"
#include "linalg/characteristic_poly.hpp"
#include "linalg/frobenius.hpp"

template <typename mint>
vvc<mint> adjugate_matrix(vvc<mint> A) {
  int N = len(A);
  Frobenius_Form<mint> X(A);
  auto F = X.characteristic_poly();
  if (N % 2 == 0) {
    for (auto& x: F) x = -x;
  }
  F.erase(F.begin());
  return X.poly_eval(F);
}