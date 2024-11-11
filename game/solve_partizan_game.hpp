
#include "game/number_and_star.hpp"

// number, star でいい感じに計算できたときだけ成功
// 失敗したときは、empty map が返る
// ・states：興味のある state 全体
// ・get_options：pair<vc<STATE>, vc<STATE>>(STATE), left ops / right ops
// https://qoj.ac/contest/1828/problem/9567
template <typename STATE, typename F>
map<STATE, Number_And_Star> solve_partizan_game(const vector<STATE>& states, F get_options) {
  using X = Number_And_Star;
  map<STATE, X> MP;

  bool success = 1;

  auto dfs = [&](auto& dfs, const STATE& s) -> X {
    if (!success) return X();
    if (MP.count(s)) return MP[s];
    vc<X> left, right;
    auto [lop, rop] = get_options(s);
    for (auto&& t: lop) left.eb(dfs(dfs, t));
    for (auto&& t: rop) right.eb(dfs(dfs, t));
    auto [ok, t] = X::from_options(left, right);
    if (!success) return X{};
    if (!ok) {
      // print("FAILED");
      // print(s);
      // print("LEFT");
      // for (auto& t: lop) {
      //   X x = dfs(dfs, t);
      //   print(t, x.to_string());
      // }
      // print("RIGHT");
      // for (auto& t: rop) {
      //   X x = dfs(dfs, t);
      //   print(t, x.to_string());
      // }
      success = 0;
      return X();
    }
    MP[s] = t;
    return MP[s] = t;
  };

  for (auto&& s: states) dfs(dfs, s);
  if (!success) MP.clear();
  return MP;
}
