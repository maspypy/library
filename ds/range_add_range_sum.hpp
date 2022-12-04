#include "fenwicktree/fenwicktree.hpp"

template <typename Monoid>
struct Range_Add_Range_Sum {
  using MX = Monoid;
  using E = typename MX::value_type;

  struct Mono {
    using value_type = pair<E, E>;
    using X = value_type;
    static X op(X x, X y) { return {MX::op(x.fi, y.fi), MX::op(x.se, y.se)}; }
    static constexpr X unit() { return {MX::unit(), MX::unit()}; }
    static constexpr bool commute = 1;
  };
  FenwickTree<Mono> bit;

  Range_Add_Range_Sum() {}
  Range_Add_Range_Sum(int n) { build(n); }
  template <typename F>
  Range_Add_Range_Sum(int n, F f) {
    build(n, f);
  }
  Range_Add_Range_Sum(const vc<E>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> E { return MX::unit(); });
  }
  void build(const vc<E>& v) {
    build(len(v), [&](int i) -> E { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    bit.build(m, [&](int i) -> pair<E, E> { return {f(i), MX::unit()}; });
  }

  void add(int L, int R, E a) {
    E b = MX::inverse(a);
    bit.add(L, {MX::power(b, L), a});
    bit.add(R, {MX::power(a, R), b});
  }

  E sum(int L, int R) {
    auto [x0, x1] = bit.sum(L);
    auto [y0, y1] = bit.sum(R);
    E x = MX::op(MX::power(x1, L), x0);
    E y = MX::op(MX::power(y1, R), y0);
    return MX::op(MX::inverse(x), y);
  }
};
