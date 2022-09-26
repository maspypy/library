#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"
#include "game/solve_partizan_game.hpp"

void test_push() {
  // LESSONS IN PLAY p.113
  vc<string> states = {"LR", ".RL", ".R", "RRL"};
  auto get_options = [&](string s) -> pair<vc<string>, vc<string>> {
    vc<string> left_ops, right_ops;
    FOR(i, len(s)) {
      if (s[i] == '.') continue;
      string t = s;
      char x = '.';
      int p = i;
      while (p >= 0) {
        swap(x, t[p--]);
        if (x == '.') break;
      }
      if (s[i] == 'L') left_ops.eb(t);
      if (s[i] == 'R') right_ops.eb(t);
    }
    return {left_ops, right_ops};
  };

  auto MP = solve_partizan_game<string, ll>(states, get_options);
  // for (auto&& [s, x]: MP) { print(s, x.to_string()); }
  assert(MP["LR"].to_string() == "-3/2");
  assert(MP[".RL"].to_string() == "7/4");
  assert(MP[".R"].to_string() == "-2/1");
  assert(MP["RRL"].to_string() == "13/8");
}

void test_problem_5_2() {
  // switch になるので解けない
  int LIM = 10;
  vc<int> states(LIM);
  iota(all(states), 0);

  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {
    vc<int> left_ops, right_ops;
    if (s % 3 == 0 && s >= 1) left_ops.eb(s - 1), right_ops.eb(s - 1);
    if (s % 3 == 0 && s >= 2) left_ops.eb(s - 2), right_ops.eb(s - 2);
    if (s % 3 == 1 && s >= 1) left_ops.eb(s - 1);
    if (s % 3 == 1 && s >= 2) left_ops.eb(s - 2);
    if (s % 3 == 2 && s >= 1) right_ops.eb(s - 1);
    if (s % 3 == 2 && s >= 2) right_ops.eb(s - 2);
    return {left_ops, right_ops};
  };

  auto MP = solve_partizan_game<int, ll>(states, get_options);
  assert(MP.empty());
}

void test_problem_5_3() {
  int LIM = 10;
  vc<int> states(LIM);
  iota(all(states), 0);

  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {
    vc<int> left_ops, right_ops;
    if (s % 2 == 0 && s >= 2) left_ops.eb(s - 2);
    if (s % 2 == 0 && s >= 1) right_ops.eb(s - 1);
    if (s % 2 == 1 && s >= 1) left_ops.eb(s - 1);
    if (s % 2 == 1 && s >= 2) right_ops.eb(s - 2);
    return {left_ops, right_ops};
  };

  auto MP = solve_partizan_game<int, ll>(states, get_options);
  assert(MP[0].to_string() == "0/1");
  assert(MP[1].to_string() == "1/1");
  assert(MP[2].to_string() == "1/2");
  assert(MP[3].to_string() == "3/4");
  assert(MP[4].to_string() == "5/8");
  assert(MP[5].to_string() == "11/16");
}

int solve_cherries(string s) {
  // LR cherries を O(N) で解く
  auto eval = [&](char c) -> int {
    if (c == 'L') return 1;
    if (c == 'R') return -1;
    return 0;
  };

  int n = len(s);
  if (n == 0) return 0;
  int res = 0;

  FOR(2) {
    reverse(all(s));
    if (n >= 2 && s[n - 1] == s[n - 2]) {
      res += eval(s[n - 1]);
      s.pop_back();
      n = len(s);
    }
  }

  char a = '.', b = '.';
  FOR_R(i, n - 1) if (s[i] == s[i + 1]) a = s[i];
  FOR(i, n - 1) if (s[i] == s[i + 1]) b = s[i];
  int x = eval(s[0]) + eval(a) + eval(b) + eval(s[n - 1]);
  return x / 2;
};

void test_cherries() {
  int MAX_LEN = 20;
  vc<string> states;
  states.eb("");
  int p = 0, q = 1;
  FOR(MAX_LEN) {
    FOR(i, p, q) {
      states.eb(states[i] + "L");
      states.eb(states[i] + "R");
    }
    p = q;
    q = len(states);
  }

  auto get_options = [&](string s) -> pair<vc<string>, vc<string>> {
    vc<string> left, right;
    int n = len(s);

    if (n && s[0] == 'L') left.eb(s.substr(1, n - 1));
    if (n && s[0] == 'R') right.eb(s.substr(1, n - 1));
    if (n && s[n - 1] == 'L') left.eb(s.substr(0, n - 1));
    if (n && s[n - 1] == 'R') right.eb(s.substr(0, n - 1));
    return {left, right};
  };

  auto MP = solve_partizan_game<string, int>(states, get_options);

  for (auto&& [s, x]: MP) {
    int my_ans = solve_cherries(s);
    assert(x == DyRational<int>(my_ans, 0));
  }
}

void test() {
  test_push();
  test_problem_5_2();
  test_problem_5_3();
  test_cherries();
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  test();

  ll T = 1;
  FOR(T) solve();

  return 0;
}