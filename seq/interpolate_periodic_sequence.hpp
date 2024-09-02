#pragma once

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
    ll k = ceil<ll>(n - (len(dat) - 1), p);
    n -= k * p;
    return dat[n];
  }
};

// 差分が 012[345][345][345] みたいなやつ
template <typename T>
struct Interpolate_Difference_Periodic_Sequence {
  vc<T> dat;
  T d;
  int p;

  Interpolate_Difference_Periodic_Sequence(vc<T> A) : dat(A) {
    vc<T> diff;
    FOR(i, len(A) - 1) diff.eb(A[i + 1] - A[i]);
    reverse(all(diff));
    auto Z = zalgorithm(diff);
    Z[0] = 0;
    p = max_element(all(Z)) - Z.begin();
    ll n = len(A);
    d = A[n - 1] - A[n - p - 1];
  }

  T operator[](ll n) {
    if (n < len(dat)) return dat[n];
    ll k = ceil<ll>(n - (len(dat) - 1), p);
    n -= k * p;
    return dat[n] + k * d;
  }
};