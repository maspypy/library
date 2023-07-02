
// 大きいときは infty<T>
template <typename T>
struct Monoid_Lcm {
  using value_type = T;
  using X = value_type;
  static X op(X x, X y) {
    if (x == infty<T> || y == infty<T>) return infty<T>;
    x /= gcd(x, y);
    if (x >= ceil(infty<T>, y)) return infty<T>;
    return x * y;
  }
  static constexpr X unit() { return 1; }
  static constexpr bool commute = 1;
};
