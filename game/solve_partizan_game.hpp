#include "game/dyadic_rational.hpp"

// 全部 dyadic rational number になるときだけ解ける
// 失敗したときは、empty map が返る
// ・states：興味のある state 全体
// ・get_options：pair<vc<STATE>, vc<STATE>>(STATE), left ops / right ops
template <typename STATE, typename INTEGER, typename F>
map<STATE, Dyadic_Rational<INTEGER>> solve_partizan_game(
    const vector<STATE>& states, F get_options) {
  using X = Dyadic_Rational<INTEGER>;
  map<STATE, X> MP;

  bool success = 1;

  auto dfs = [&](auto& dfs, const STATE& s) -> X {
    if (!success) return X();
    if (MP.count(s)) return MP[s];
    vc<X> left, right;
    X xl = -X::infinity(), xr = X::infinity();
    auto [left_ops, right_ops] = get_options(s);
    for (auto&& t: left_ops) chmax(xl, dfs(dfs, t));
    for (auto&& t: right_ops) chmin(xr, dfs(dfs, t));

    if (xl >= xr) {
      // switch
      success = 0;
      MP.clear();
      return X();
    }
    return (MP[s] = X::simplest(xl, xr));
  };

  for (auto&& s: states) dfs(dfs, s);
  return MP;
}