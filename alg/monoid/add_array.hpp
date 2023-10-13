#pragma once

template <typename E, int K>
struct Monoid_Add_Array {
  using value_type = array<E, K>;
  using X = value_type;
  static X op(X x, X y) {
    FOR(i, K) x[i] += y[i];
    return x;
  }
  static constexpr X unit() { return X{}; }
  static constexpr X inverse(X x) {
    for (auto& v: x) v = -v;
    return x;
  }
  static constexpr X power(X x, ll n) {
    for (auto& v: x) v *= E(n);
    return x;
  }
  static constexpr bool commute = 1;
};
