template <typename INT, int LOG>
struct Monoid_XorBasis {
  using value_type = array<INT, LOG>;
  using X = value_type;
  static void add_element(X& x, INT v) {
    int n = 0;
    for (auto&& e: x) {
      if (e == 0 || v == 0) break;
      ++n;
      chmin(v, v ^ e);
    }
    if (v) x[n] = v;
  }

  static X op(const X& x, const X& y) {
    X z = x;
    int n = 0;
    while (n < LOG && z[n]) ++n;
    for (auto v: y) { add_element(z, v); }
    return z;
  }
  static INT get_max(const X& x) {
    INT res = 0;
    for (auto&& a: x) chmax(res, res ^ a);
    return res;
  }
  static constexpr X unit() { return X{}; };
  static constexpr bool commute = true;
};
