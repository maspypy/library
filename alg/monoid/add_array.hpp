#pragma once

template <typename E, int K>
struct Group_Add_Array {
  using value_type = array<E, K>;
  using X = value_type;
  static X op(X x, X y) {
    X z;
    FOR(i, K) z[i] = x[i] + y[i];
    return z;
  }
  static X unit() { return X{}; }
  static constexpr bool commute = 1;
};
