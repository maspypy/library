#include "string/zalgorithm.hpp"

// 012[345][345][345] みたいなやつ
template <typename T>
struct Interpolate_Periodic_Sequence {
  vc<T> dat;
  int p;

  Interpolate_Periodic_Sequence(vc<T> A) : dat(A) {
    reverse(all(A));
    auto Z = zalgorithm(A);
    Z[0] = 0;
    p = max_element(all(Z)) - Z.begin();
  }

  T operator[](ll n) {
    if (n < len(dat)) return dat[n];
    ll k = ceil(n - (len(dat) - 1), p);
    n -= k * p;
    return dat[n];
  }
};