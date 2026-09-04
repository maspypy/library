
template <typename E, int K>
struct Monoid_Add_Array {
  using value_type = array<E, K>;
  using X = value_type;
  static X op(const X& x, const X& y) {
    X z;
    FOR(i, K) z[i] = x[i] + y[i];
    return z;
  }
  static constexpr X id() { return X{}; }
  static constexpr X inverse(X x) {
    for (auto& v : x) v = -v;
    return x;
  }
  static constexpr X power(X x, ll n) {
    for (auto& v : x) v *= E(n);
    return x;
  }
  static constexpr bool commute = 1;
};
