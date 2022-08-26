#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "other/random.hpp"
#include "string/is_substring.hpp"

string gen(int n) {
  string s;
  FOR(n) { s += char('a' + RNG(3)); }
  return s;
}

bool naive(string S, string T) {
  FOR(i, len(T)) if (T.substr(i, len(S)) == S) return true;
  return false;
}

void test() {
  FOR(1000) {
    FOR(n, 1, 10) FOR(m, 1, 10) {
      string s = gen(n), t = gen(m);
      bool a = naive(s, t);
      bool b = is_substring(s, t);
      assert(a == b);
    }
  }
}

void solve() {
  LL(A, B);
  print(A + B);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}