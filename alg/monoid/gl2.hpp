#pragma once

template <typename T, bool reversed>
struct Group_GL2 {
  using X = array<array<T, 2>, 2>;
  using value_type = X;
  static X op(const X &x, const X &y) {
    X z{};
    if (!reversed) {
      FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] += x[i][j] * y[j][k];
    }
    if (reversed) {
      FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] += y[i][j] * x[j][k];
    }
    return z;
  }
  static X inverse(const X &x) {
    T det = x[0][0] * x[1][1] - x[0][1] * x[1][0];
    T cf = T(1) / det;
    X y;
    y[0] = {x[1][1] * cf, -x[0][1] * cf};
    y[1] = {-x[1][0] * cf, x[0][0] * cf};
    return y;
  }
  // static X power(const X &x, ll n) { return n * x; }
  static constexpr X unit() {
    X x;
    x[0] = {T(1), T(0)};
    x[1] = {T(0), T(1)};
    return x;
  }
  static constexpr bool commute = 0;
};
