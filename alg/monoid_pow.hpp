#pragma once

// chat gpt
template <typename U, typename Arg1, typename Arg2>
struct has_power_method {
private:
  // ヘルパー関数の実装
  template <typename V, typename A1, typename A2>
  static auto check(int)
      -> decltype(std::declval<V>().power(std::declval<A1>(),
                                          std::declval<A2>()),
                  std::true_type{});
  template <typename, typename, typename>
  static auto check(...) -> std::false_type;

public:
  // メソッドの有無を表す型
  static constexpr bool value = decltype(check<U, Arg1, Arg2>(0))::value;
};

template <typename Monoid>
typename Monoid::X monoid_pow(typename Monoid::X x, ll exp) {
  using X = typename Monoid::X;
  if constexpr (has_power_method<Monoid, X, ll>::value) {
    return Monoid::power(x, exp);
  } else {
    assert(exp >= 0);
    X res = Monoid::unit();
    while (exp) {
      if (exp & 1) res = Monoid::op(res, x);
      x = Monoid::op(x, x);
      exp >>= 1;
    }
    return res;
  }
}