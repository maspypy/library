#define PROBLEM "https://atcoder.jp/contests/abc229/tasks/abc229_h"

#include "my_template.hpp"
#include "other/io.hpp"

#include "game/solve_partizan_game.hpp"

void solve() {
  LL(N);
  VEC(string, G, N);
  vc<string> states(N);
  FOR(i, N) FOR(j, N) states[j] += G[i][j];

  auto get_options = [&](string s) -> pair<vc<string>, vc<string>> {
    int n = len(s);
    vc<string> left, right;
    FOR(i, 1, n) {
      // 進める
      if (s[i - 1] == '.' && s[i] == 'W') {
        swap(s[i - 1], s[i]);
        left.eb(s);
        swap(s[i - 1], s[i]);
      }
      if (s[i - 1] == '.' && s[i] == 'B') {
        swap(s[i - 1], s[i]);
        right.eb(s);
        swap(s[i - 1], s[i]);
      }
    }
    FOR(i, n) {
      // 食べる
      if (s[i] == 'B') {
        s[i] = '.';
        left.eb(s);
        s[i] = 'B';
      }
      if (s[i] == 'W') {
        s[i] = '.';
        right.eb(s);
        s[i] = 'W';
      }
    }
    return {left, right};
  };

  using X = Dyadic_Rational<int>;
  auto MP = solve_partizan_game<string, int>(states, get_options);
  X x(0);
  // for (auto&& [k, x]: MP) { print(k, ",", x.to_string()); }
  for (auto&& s: states) { x += MP[s]; }
  print(x > X(0) ? "Takahashi" : "Snuke");
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
